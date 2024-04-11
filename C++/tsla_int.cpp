#include <bits/stdc++.h>
using namespace std;

// std::function <void ()> // how to have a single function template so that different kinds of input with same input name can result in work being done

/*class Work_Base {

virtual void do_work() = 0;
};*/


class Work_Queue//::Base Work_Base
{

public:
mutex lock;
condition_variable cv;
int thrd_ctr, max_thrd;//max_treads = 4;
queue<pair<int,int>> wq;

map<int,int> am;

Work_Queue(int cap)
{
   max_thrd = cap;
   thrd_ctr = 0;
}

void churn()//block
{
   //sleep(10);
   
   if (!wq.empty())
   {
    unique_lock<mutex> ul(lock);
    cv.wait(ul,[this](){ return (thrd_ctr < max_thrd);});
    auto [ip, id] = wq.front();
    wq.pop();
    ++thrd_ctr;
    cout<<"thrd # "<<thrd_ctr<<" started"<<endl;
    ip++;sleep(5);
    cout<<"thrd # "<<thrd_ctr<<" ended"<<endl;    
    am[id] = ip;
    --thrd_ctr;
    //cout<<"i just finished job for id: "<<id<<endl;
    if (!wq.empty()) cv.notify_all();
   }

}

void do_work(int ip, int id)
{
   wq.push({ip,id});
   thread thrdobj([&](){churn();});
   thrdobj.detach();
}

int get_ans(int id)
{ 
  while (am.find(id) == am.end())
  {
    //do nothing
  }
   return am[id];
  
}



/*void do_work(string s)
{

}

void do_work (char x[])
{

}*/


};

// To execute C++, please define "int main()"
int main() {
  
 Work_Queue q(4);

 //vector<thread> th;

 for (int i =0;i<10;++i)
 {
   q.do_work(i, i+5);
 }

 for (int i =0;i<10;++i)
 {
  cout<<q.get_ans(i+5)<<endl;
 }
 
 //cout<<q.do_work(5)<<endl;

  
  return 0;
}

//width limited work queue
//constraint - width o the queue - how many jobs concurrently at the same time
