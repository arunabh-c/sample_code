class Work_Queue {

mutex lock;
condition_variable cv;
int thrd_ctr, max_thrd;
queue<pair<int, int>> wq;
map<int, int> am;

public:
Work_Queue(int cap) {
    max_thrd = cap;
    thrd_ctr = 0;
}

void churn() {
    if (!wq.empty()) {
        unique_lock<mutex> ul(lock);
        cv.wait(ul, [this]() { return (thrd_ctr < max_thrd); });
        auto [ip, id] = wq.front();
        wq.pop();
        ++thrd_ctr;
        cout << "thrd # " << thrd_ctr << " started" << endl;
        ip++;
        sleep(1);
        cout << "thrd # " << thrd_ctr << " ended" << endl;
        am[id] = ip;
        --thrd_ctr;
        cv.notify_all();
    }
}

void do_work(int ip, int id) {
    wq.push({ip, id});
    thread thrdobj([&]() { churn(); });
    thrdobj.detach();
}

int get_ans(int id) {
    while (am.find(id) == am.end()) {
        // do nothing
    }
    return am[id];
}
};

int main() {
cout << "Number of cores: " << thread::hardware_concurrency() << endl;
Work_Queue q(4);
for (int i = 0; i < 6; ++i) {
    q.do_work(i, i + 5);
}
for (int i = 0; i < 6; ++i) {
    cout << q.get_ans(i + 5) << endl;
}
return 0;
}
