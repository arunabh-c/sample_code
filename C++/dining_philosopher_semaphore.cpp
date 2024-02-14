class Semaphore
{
    public:
    Semaphore() {count=1;} //constructor

    inline void signal()
    {
        std::unique_lock<std::mutex> lock(m);
        if (++count<=0) cv.notify_all();
    }
    inline void wait()
    {
        std::unique_lock<std::mutex> lock(m);
        count--;//negative
        //cout<<"count now "<<count<<endl;
        cv.wait(lock,[this]{return (count>=0);});//keep waiting until count goes >=0
    }

    private:
    std::mutex m;
    std::condition_variable cv;
    int count;
};

class DiningPhilosophers {
    Semaphore fork[5];
    std::mutex m;
public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		{
            std::lock_guard<std::mutex>lock(m);
            fork[(philosopher+1)%5].wait();
            fork[philosopher].wait();
        }
        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        fork[(philosopher+1)%5].signal();
        putRightFork();
        fork[philosopher].signal();
    }
};
