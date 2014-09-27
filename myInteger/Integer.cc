#include "Integer.h"

using namespace std;

Integer::Integer(int data)
	: data_(data)
{  }

Integer::~Integer()
{  }

Integer & Integer::operator= (int data)
{
	data_ = data;
	return *this;
}

Integer & Integer::operator++ ()
{	
	++data_;
	return *this;
}

Integer Integer::operator++ (int)
{
	Integer tmp(*this);
	++data_;
	return tmp;
}

std::ostream & operator<< (std::ostream &os, const Integer &i)
{
	return os << i.data_;	
}

std::istream & operator>> (std::istream &is, Integer &i)
{
	int tmp;
	if (is >> tmp)
		i.data_ = tmp;
	return is;
}
