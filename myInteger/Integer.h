#ifndef INTEGER_H_
#define INTEGER_H_ 

#include <iostream>

class Integer {
		friend std::ostream & operator<< (std::ostream &os, const Integer &i);
		friend std::istream & operator>> (std::istream &is, Integer &i);
	public:
		Integer(int data = 0);
		~Integer();
		
		Integer & operator= (int data);
		Integer & operator++ ();
		Integer operator++ (int);

		operator int() { return data_; }
	private:
		int data_;
};

#endif  /*INTEGER_H_*/
