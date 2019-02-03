#include "pch.h"
#include <mutex>
#include <iostream>
#include <queue>
#include <thread>

template <typename t>
class threadsafe_queue
{
private:
	std::mutex mut;
	std::queue<t> data_queue;

public:
	threadsafe_queue() {}
	t pop()
	{
		std::lock_guard<std::mutex> lk(mut);
		if (data_queue.empty())
			return NULL;
		t res = data_queue.front();
		data_queue.pop();
		return res;
	}

	bool try_pop(t& value)
	{
		std::lock_guard<std::mutex> lk(mut);
		if (data_queue.empty())
			return false;
		value = std::move(*data_queue.front());
		data_queue.pop();
		return true;
	}


	void push(t new_value)
	{
		
			
		std::lock_guard<std::mutex> lk(mut);
		data_queue.push(new_value);
	    
	}

};
