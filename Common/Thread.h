// CITO: La presenta clase se apoya en la implementacion hecha por 
//       la catedra para la clase Thread. 

#ifndef _THREAD_H_
#define _THREAD_H_

#include <thread>
#include <utility>

class Thread {
    private:
        std::thread thread;
 
    public:
        Thread() {}

        void start();
        void join();

        Thread(Thread&& other);

        virtual void run() = 0;
        virtual ~Thread() {}
    private:    
        Thread(const Thread&) = delete;
        Thread& operator=(const Thread&) = delete;
};


#endif
