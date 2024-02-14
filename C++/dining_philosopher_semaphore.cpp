class Semaphore
{
    int count;
    public:
    Semaphore() {count=1;}//constructor
    void signal()
    {
        ++count;
    }
    void wait()
    {
        while (count<=0);
        count--;//negative
    }
};

class DiningPhilosophers {
    Semaphore fork[5];
    mutex m;
public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        fork[philosopher].wait();
        
        unique_lock<mutex>lock(m);
        
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        fork[philosopher].signal();
    }
};
