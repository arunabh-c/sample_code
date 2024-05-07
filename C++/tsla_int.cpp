// std::function <void ()>

#include <bits/stdc++.h>
using namespace std;

class Work_Queue {
    mutex lock, mlock;          //, qlock;
    condition_variable cv, cvm; //, cvq;
    int thrd_ctr, max_thrd;
    queue<pair<int, int>> wq;
    map<int, int> am;

    void enqueue(int ip, int id) {
        // unique_lock<mutex> ul(qlock);
        wq.push({ip, id});
        // cvq.notify_all();
    }

    void dequeue(int& ip, int& id) {
        // unique_lock<mutex> ul(qlock);
        // cvq.wait(ul, [this]() {return !wq.empty();});
        ip = wq.front().first;
        id = wq.front().second;
        wq.pop();
        // cvq.notify_all();
    }

    void set_ans(int ip, int id) {
        unique_lock<mutex> ul(mlock);
        am[id] = ip;
        cvm.notify_all();
    }

    void new_thread(int& lt) {
        unique_lock<mutex> ul(lock);
        cv.wait(ul, [this]() { return (thrd_ctr < max_thrd); });
        lt = ++thrd_ctr;
        cv.notify_all();
    }

    void end_thread() {
        unique_lock<mutex> ul(lock);
        --thrd_ctr;
        cv.notify_all();
    }

    void churn() {
        int lt, ip, id;
        dequeue(ip, id);
        new_thread(lt);
        // cout << "thrd # " << lt << " started"
        //      << " for task # " << ip << endl;
        ip++;
        sleep((rand()) % 4);
        // cout << "thrd # " << lt << " ended"
        //      << " for task # " << ip << endl;
        set_ans(ip, id);
        end_thread();
    }

public:
    Work_Queue(int cap) : max_thrd(cap), thrd_ctr(0) {}

    int get_ans(const int id) {
        int ans;
        unique_lock<mutex> ul(mlock);
        // cout<<"waiting here for id: "<<id<<endl;
        cvm.wait(ul, [this, &id]() { return (am.find(id) != am.end()); });
        ans = am[id];
        cvm.notify_all();
        return ans;
    }

    void do_work(int ip, int id) {
        enqueue(ip, id);
        thread thrdobj([&]() { churn(); });
        thrdobj.detach();
    }
};

int main() {

    Work_Queue q(10);

    for (int i = 0; i < 79; ++i) {
        cout << "Adding work id: " << i + 5 << " with value: " << i << endl;
        q.do_work(i, i + 5);
    }

    for (int i = 0; i < 79; ++i) {
        cout << "Final answer for id: " << i + 5 << " is " << q.get_ans(i + 5)
             << endl;
    }

    cout << "DONE!" << endl;
    return 0;
}
//width limited work queue
//constraint - width o the queue - how many jobs concurrently at the same time
