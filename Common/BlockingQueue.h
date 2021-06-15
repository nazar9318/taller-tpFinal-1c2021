// CITO: La presente clase se basa mucho en la implementacion
//       dada por la catedra de BlockingQueue y en la documentacion
//       de C++ Reference sobre condition_variable. 

#ifndef _BLOCKING_QUEUE_H
#define _BLOCKING_QUEUE_H

#include <queue>
#include <string>
#include <mutex>
#include <condition_variable>
#include <fstream>
#include <iostream>

#include "ExceptionClosedQueue.h"

template <class T> class BlockingQueue {
		std::queue<T> queue;
		bool closed;
		std::mutex m;
		std::condition_variable condition_variable;

	public:
		BlockingQueue(): closed(false) {}

		// POST: Retorna el primer dato de la cola. 
		//       Si no hay datos, el metodo es bloqueante
		//       y espera a un push. Si la cola esta vacia 
		//       y cerrada, lanza ClosedQueueException.
		T pop() {
			std::unique_lock<std::mutex> lock(m);
			while (queue.empty()) {
				if (closed)
					throw ExceptionClosedQueue();
				condition_variable.wait(lock);
			}
			T data = queue.front();
			queue.pop();
			return data;
		}
		
		// POST: Agrega un dato a la cola siempre y 
		//       cuando la cola no este cerrada. 
		//       Notifica a quienes pueden estar 
		//       esperando en un pop. 
		void push(const T& data) {
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

		~BlockingQueue() {}
	
	private:
		BlockingQueue(const BlockingQueue &other) = delete;
		BlockingQueue& operator=(const BlockingQueue &other) = delete;
};


#endif
