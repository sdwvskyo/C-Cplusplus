#include "Person.h"

using namespace std;

Person::Person()
{
	name_ = "";
	address_ = "";
	birth_.setToday();
}

Person::~Person()
{
}

int Person::aliveDay() const
{
	return Date::differenceDate(Date::today(), birth_);
}

bool Person::isPassBirthday() const
{
	return (Date::today().calDayOfYear() - birth_.calDayOfYear()) < 0;
}

void Person::printBirthday() const
{
	cout << "Name: " << name_ << endl;
	cout << "Address: " << address_ << endl;
	cout << "Birth: " << birth_.toString() << endl;
}
