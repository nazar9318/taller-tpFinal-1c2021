#include "Thread.h"

void Thread::start() {
	thread = std::thread(&Thread::run, this);
}

void Thread::join() {
	thread.join();
}

Thread::Thread(Thread&& other): thread(std::move(other.thread)) {
}
