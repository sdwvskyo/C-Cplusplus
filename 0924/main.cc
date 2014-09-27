#include "WordCount.h"

using namespace std;

int main(int argc, const char *argv[])
{
	if (argc < 3)
		throw runtime_error("argument less");
	double startTime = gettime();	
	Words words(argv[1], argv[2]);
	words.sortByFrequency();
	words.printByWordOrder();
	words.printTopK();
	double endTime = gettime();
	cout << "cost time: " << endTime - startTime << " second." << endl;

	return 0;
}
