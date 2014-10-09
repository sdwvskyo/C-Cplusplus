#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal{
public:
	Animal() { cout << "Animal start" << endl; }
	~Animal() { cout << "~Animal end" << endl; }
	void run() { cout << "Animal running" << endl; }
};

class AnimalPtr {
public:
	AnimalPtr(Animal *ptr = NULL) : ptr_(ptr) { }
	~AnimalPtr() { delete ptr_; }

	Animal & operator* () { return *ptr_; }
	const Animal & operator* () const { return *ptr_; }

	Animal * operator-> () { return ptr_; }
	const Animal * operator-> () const {return ptr_; }

	const Animal * getPtr() const { return ptr_; }
	void resetPtr(Animal *ptr = NULL)
	{ 
		if (ptr_ != ptr) {
			delete ptr_;
			ptr_ = ptr; 
		}
	}
private:
	Animal *ptr_;
};

int main(int argc, const char *argv[])
{
	AnimalPtr ptr(new Animal);
	cout << ptr.getPtr() << endl;
	ptr->run();

	ptr.resetPtr();
	ptr.resetPtr(new Animal);
	cout << ptr.getPtr() << endl;
	return 0;
}
