#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <assert.h>
#include <stdexcept>
#define ERR_EXIT(m) \
	do { \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)
using namespace std;

int main(int argc, const char *argv[])
{
	assert(argc == 3);
	ifstream infile(argv[1]);
	ofstream outfile(argv[2]);
	if (!infile || !outfile)
		ERR_EXIT("open file");
	
	string line;
	while (getline(infile, line)) 
		outfile << line << endl;

	infile.close();
	outfile.close();
	
	return 0;
}
