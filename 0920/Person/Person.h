#ifndef PERSON_H_
#define PERSON_H_ 

#include "../Date/Date.h"

class Person{
	public:
		Person();
		~Person();
		
		int aliveDay() const;
		bool isPassBirthday() const; 
		void printBirthday() const;
	private:
		string name_;
		string address_;
		Date birth_;
};


#endif  /*PERSON_H_*/
