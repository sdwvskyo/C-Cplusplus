#ifndef COUNTER_HPP_
#define COUNTER_HPP_ 
//引用计数指针

#include <algorithm>

template <typename T>
class CounterPtr
{
public:
	typedef T value_type;
	typedef T *pointer;
	typedef const T *const_pointer;
	typedef T &reference;
	typedef const T &const_reference;

	explicit CounterPtr(pointer p = NULL);
	CounterPtr(const CounterPtr<T> &other);
	~CounterPtr();

	CounterPtr<T> &operator=(const CounterPtr<T> &other);

	reference operator*() const throw() { return *ptr_; }
	pointer operator->() const throw() { return ptr_; }

	size_t getCount() const { return *count_; }
	void swap(CounterPtr<T> &other) {
		std::swap(ptr_, other.ptr_);
		std::swap(count_, other.count_);
	}

	void get() { return ptr_; }
	void reset() { 
		dispose(); 
		ptr_ = NULL;
		count_ = new size_t(1);
	}
	operator bool() { return ptr_ != NULL; }
	bool unique() const { return *count_ == 1; }

private:
	void dispose() {
		if (count_ && --(*count_) == 0) {
			delete ptr_;
			delete count_;
		}
	}

	pointer ptr_;
	std::size_t *count_;	//引用计数
};

template <typename T>
CounterPtr<T>::CounterPtr(pointer p)
	: ptr_(p), count_(new std::size_t(1))
{

}

template <typename T>
CounterPtr<T>::~CounterPtr()
{
	dispose();
}

template <typename T>
CounterPtr<T>::CounterPtr(const CounterPtr<T> &other)
	: ptr_(other.ptr_), count_(other.count_)
{
	++*count_;
}

template <typename T>
CounterPtr<T> &CounterPtr<T>::operator=(const CounterPtr<T> &other)
{
	if (this != &other) {
		dispose();
		count_ = other.count_;
		ptr_ = other.ptr_;
		++*count_;
	}
	return *this;
}

#endif  /*COUNTER_HPP_*/
