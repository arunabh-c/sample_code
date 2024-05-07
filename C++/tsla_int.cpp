// std::function <void ()>

#include <bits/stdc++.h>
using namespace std;

class Work_Queue {

    mutex lock, qlock, mlock;
    condition_variable cv, cvq, cvm;
    int thrd_ctr, max_thrd;
    queue<pair<int, int>> wq;
    map<int, int> am;

public:
    Work_Queue(int cap) {
        max_thrd = cap;
        thrd_ctr = 0;
    }
    
    void enqueue(int ip, int id)
    {
        unique_lock<mutex> ul(qlock);
        wq.push({ ip, id });
    }

    void dequeue(int &ip, int &id)
    {
        unique_lock<mutex> ul(qlock);
        cvq.wait(ul, [this]() {return !wq.empty();});
        ip = wq.front().first;
        id = wq.front().second;
        wq.pop();
        cvq.notify_all();
    }
    
    void set_ans(int ip, int id)
    {
        unique_lock<mutex> ul(mlock);
        am[id] = ip;
    }
    
    int get_ans(const int id)
    {
        int ans;
        unique_lock<mutex> ul(mlock);
        cvm.wait(ul, [this, &id]() {return (am.find(id) != am.end());});
        ans = am[id];
        cvm.notify_all();
        return ans;
    }
    
    void new_thread(int &lt)
    {
            unique_lock<mutex> ul(lock);
            cv.wait(ul, [this]() { return (thrd_ctr < max_thrd); });
            lt = ++thrd_ctr;
            cv.notify_all();
    }
    
    void end_thread()
    {
            unique_lock<mutex> ul(lock);
            --thrd_ctr;
            cv.notify_all();
    }
    
    void churn() {
        
        
            int ip, id, lt;
            dequeue(ip,id);

            new_thread(lt);
            
            cout << "thrd # " << lt << " started" << endl;
            ip++;
            sleep((rand())%4);
            cout << "thrd # " << lt << " ended" << endl;
            
            
            end_thread();
}

    void do_work(int ip, int id) {
        enqueue(ip, id);
        thread thrdobj([&]() { churn(); });
        thrdobj.detach();
    }
};

int main() {

    Work_Queue q(5);
    
    for (int i = 0; i < 15; ++i) {
        q.do_work(i, i + 5);
    }
    
    for (int i = 0; i < 15; ++i) {
        cout << q.get_ans(i + 5) << endl;
    }
    
    cout<<"Done!"<<endl;
    return 0;
}
//width limited work queue
//constraint - width o the queue - how many jobs concurrently at the same time
