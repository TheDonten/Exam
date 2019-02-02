
template <Typename T>

class Shared_ptr{
private:

std::atomic_uint* count;
T* ptr_;
T* release() = delete;

public:
  Shared_ptr(){
    ptr = nullptr;
    count = nullptr;
}
  explicit Shared_ptr(T* ptr){
    ptr_ = ptr;
    if(ptr_ != nullptr)
    count = std::atomic_uint(1);
    else count = nullptr;
}
  Shared_ptr(Shared_ptr && other){
    if(other != *this){
    ptr_ = other.ptr_;
    count = other.count_;
    other.ptr_ = nullptr;
    other.count = nullptr;
    }
}
  Shared_ptr& operator=(Shared_ptr && other){
    if(other != *this){
    ptr_ = other.ptr_;
    count = other.count_;
    other.ptr_ = nullptr;
    other.count = nullptr;
    }
    shared_ptr(shared_ptr const& other)
	{
		ptr_ = other.ptr_;
		count = other.count;
		if (other.count)
			++*count;
	}
  shared_ptr& operator=(shared_ptr const& other){
  if(&other != *this){
   shared_ptr(other).swap(*this);
  }
  }
  void swap(shared_ptr& shared)
	{
		std::swap(shared.ptr_, ptr_);
		std::swap(shared.count, count);
	}

	void reset(T* ptr = nullptr)
	{
		shared_ptr(ptr).swap(*this);
	}

	T& operator*() const
	{
		return *ptr_;
	}

	T* operator->() const
	{
		return ptr_;
	}

	T* get() const
	{
		return ptr_;
	}
    



};
template <typename T, typename ...Args>
shared_ptr<T> make_shared(Args&& ...args) {
	return shared_ptr<T>(new T(std::forward<Args>(args)...));
}
