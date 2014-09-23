#include "PhoneRecords.h"

using namespace std;

int main(int argc, const char *argv[])
{
	PhoneRecords records;
	records.addRecord("138", "suyu", "601");
	records.addRecord("1388", "suyu", "601");
	records.addRecord("13889", "suyu", "601");
	records.addRecord("13887", "suyu", "601");
	records.addRecord("13886", "suyu", "601");
	records.printRecords();

	cout << "search by 138" << endl;
	records.findByPhoneNo("138").printRecord();

	cout << "delete 138" << endl;
	records.deleteRecord("138");
	records.printRecords();
	return 0;
}
