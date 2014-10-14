#ifndef UNIQUEPTR_H_
#define UNIQUEPTR_H_ 

#include <algorithm>
#include <stddef.h>
#include <utility>

template <typename T>
class UniquePtr
{
public:
	typedef T element_type;
	typedef T *pointer;
	typedef T &reference;

	explicit UniquePtr(T *ptr = NULL) throw()
		: ptr_(ptr)
	{
	}
	UniquePtr(UniquePtr &&u) throw()
		: ptr_(u.ptr_)
	{
		u.ptr_ = NULL;
	}
	UniquePtr &operator=(UniquePtr &&u)
	{
		if (this != &u) {
			delete ptr_;
			ptr_ = u.ptr_;
			u.ptr_ = NULL;
		}
		return *this;
	}

	~UniquePtr() { delete ptr_; }

	reference operator*() const throw() { return *ptr_; }
	pointer operator->() const throw() { return ptr_; }

	pointer get() const { return ptr_; }

	pointer release() throw() 
	{
		pointer temp(ptr_);
		ptr_ = NULL;
		return temp;
	}

	void reset(T *ptr = NULL)
	{
		if (ptr_ != ptr_) {
			delete ptr_;
			ptr_ = ptr;
		}
	}
	void swap(UniquePtr &other)
	{
		std::swap(ptr_, other.ptr_);
	}

private:
	UniquePtr(const UniquePtr &);
	void operator=(const UniquePtr &);

	T *ptr_;
};

#endif  /*UNIQUEPTR_H_*/
