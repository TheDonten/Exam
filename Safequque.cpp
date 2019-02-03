#include <mutex>
#include <queue>
#include <thread>

template <typename t>
class threadsafe_queue
{
private:
	mutable std::mutex mut;
	std::queue<t> data_queue;
	std::condition_variable data_cond;
public:
	threadsafe_queue() {}


	bool try_pop(T& value)
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
