// CITAMOS: La presente clase se basa mucho en la implementacion
//          dada por la catedra de BlockingQueue y en la documentacion
//          de C++ Reference sobre condition_variable. 

#ifndef _PROTECTED_QUEUE_H
#define _PROTECTED_QUEUE_H

#include "Exception.h"

class ExceptionClosedQueue: public Exception {
  	public:
    	ExceptionClosedQueue(): Exception("La cola bloqueante esta cerrada") {}
		explicit ExceptionClosedQueue(const char* description)
    	:Exception("%s ", description) { }
		virtual ~ExceptionClosedQueue() noexcept {}
};



#include <queue>
#include <mutex>
#include <condition_variable>
#include <utility>

//#include "ExceptionClosedQueue.h"

template <class T> class ProtectedQueue {
		std::queue<T, std::deque<T>> queue;
		std::mutex m;
		bool closed;
		std::condition_variable condition_variable;

	public:
		ProtectedQueue(): closed(false) {}

		// POST: Retorna el primer dato de la cola. 
		//       Si no hay datos, el metodo es bloqueante
		//       y espera a un push. Si la cola esta vacia 
		//       y cerrada, lanza ExceptionClosedQueue.
		/*void blocking_pop(T& data) {
			std::unique_lock<std::mutex> lock(m);
			while (queue.empty()) {
				if (closed)
					throw ExceptionClosedQueue("La cola esta cerrada");
				condition_variable.wait(lock);
			}
			data = std::move(queue.front());
			queue.pop();
		}*/

		T& blocking_pop() {
			std::unique_lock<std::mutex> lock(m);
			while (queue.empty()) {
				if (closed)
					throw ExceptionClosedQueue("La cola esta cerrada");
				condition_variable.wait(lock);
			}
			T& data = queue.front();
			queue.pop();
			return data;
		}








		// POST: Retorna el primer dato de la cola. 
		// Si la cola esta vacia lanza una Exception.
		T& pop() {
			std::unique_lock<std::mutex> lock(m);
			if (queue.empty()) {
				throw Exception("Queue is empty");
			}
			T data = queue.front();
			queue.pop();
			return data;
		}


		// POST: Agrega un dato a la cola siempre y 
		//       cuando la cola no este cerrada. 
		//       Notifica a quienes pueden estar 
		//       esperando en un pop. 
		void push(T& data) {
			std::unique_lock<std::mutex> lock(m);
			if (!closed) {
				queue.push(data);
				condition_variable.notify_all();
			}
		}
		
		bool empty() {
			std::unique_lock<std::mutex> lock(m);
			return queue.empty();
		}
		
		// POST: Cierra la cola y notifica a quienes esperan
		//       un pop. 
		void close() {
			std::unique_lock<std::mutex> lock(m);
			closed = true;
			condition_variable.notify_all();
		}
		
		bool is_closed() {
			std::unique_lock<std::mutex> lock(m);
			return closed;
		}
		
		~ProtectedQueue() {}
	
	private:
		ProtectedQueue(const ProtectedQueue &other) = delete;
		ProtectedQueue& operator=(const ProtectedQueue &other) = delete;
};


#endif