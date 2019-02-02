#include "pch.h"
#include <iostream>

template <typename T>
class scoped_ptr
{
	T * ptr_;
	scoped_ptr(const scoped_ptr & ptr) = delete;
	const scoped_ptr & operator =(const scoped_ptr &ptr) = delete;
public:
	scoped_ptr(T* ptr)
	{
		ptr_ = ptr;
	}

	~scoped_ptr()
	{
		delete ptr_;
	}

	T* operator -> ()
	{
		return ptr_;
	}

	T & operator * ()
	{
		return *ptr_;
	}

	T * get()
	{
		return ptr_;
	}
};

template<typename T, typename... Args>
scoped_ptr<T> make_scoped(Args&&... args)
{
	return scoped_ptr<T>(new T(std::forward<Args>(args)...));
}
struct test {
	int a, b;
	test() = default;
	test(int c, int d) {
		a = c;
		b = d;
	}
	test operator =(test & other) {
		a = other.a;
		b = other.b;
		return *this;
	}
	~test() = default;
};
