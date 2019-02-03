#include "pch.h"
#include <mutex>
#include <stack>
#include <iostream>
#include <queue>
#include <thread>

template <typename t>
class SafeStack {
private:
	std::stack<t> data;
	mutable std::mutex m;
public:

	SafeStack() {};
	SafeStack(SafeStack & other) {
		std::lock_guard<std::mutex>lock(other.m);
		data = other.data;
	}
	SafeStack& operator =(SafeStack & other) = delete;
	void Pop() {
		std::lock_guard<std::mutex> lock(m);
		if (data.empty()) throw std::invalid_argument("error");
		//value = std::move(data.top());
		data.pop();
	}
	void push(t new_value)
	{
		std::lock_guard<std::mutex>lock(m);
		data.push(std::move(new_value));
	}
	bool empty()const
	{
		std::lock_guard<std::mutex> lock(m);
		return data.empty();
	}
};
int main() {
	SafeStack<int> data;
	data.push(5);
}
