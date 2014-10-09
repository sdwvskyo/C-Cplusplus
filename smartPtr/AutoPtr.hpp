#ifndef AUTOPTR_HPP_
#define AUTOPTR_HPP_ 

#include <stddef.h>

template <typename T>
class AutoPtr
{
public:
	typedef T element_type;
	typedef T *pointer;
	typedef T &reference;

	AutoPtr(T *ptr = NULL);
	AutoPtr(const AutoPtr<T> &other);
	~AutoPtr() { delete ptr_; }

	AutoPtr &operator=(const AutoPtr &other);

	reference operator*() const throw() { return *ptr_; }
	pointer operator->() const throw() { return ptr_; }

	void reset(T *ptr = NULL) throw() {
		if (ptr_ != ptr) {
			delete ptr_;
			ptr_ = ptr;
		}
	}
	
	//释放内部指针，返回当前指针
	pointer release() throw() {
		pointer tmp(ptr_);
		ptr_ = NULL;
		return tmp;
	}

	operator bool() { return ptr_ != NULL; }
private:
	element_type *ptr_;
};

template <typename T>
AutoPtr<T>::AutoPtr(T *ptr)
	: ptr_(ptr)
{
	
}

template <typename T>
AutoPtr<T>::AutoPtr(const AutoPtr<T> &other)
	: ptr_(other.release())
{

}

template <typename T>
AutoPtr<T> & AutoPtr<T>::operator=(const AutoPtr<T> &other)
{
	reset(other.release());
	return *this;
}

#endif  /*AUTOPTR_HPP_*/
