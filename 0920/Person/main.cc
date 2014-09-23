#include "Person.h"

using namespace std;

int main(int argc, const char *argv[])
{
	Person person;
	
	cout << person.aliveDay() << endl;
	cout << person.isPassBirthday() << endl;
	person.printBirthday();

	return 0;
}
