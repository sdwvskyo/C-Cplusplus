#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <assert.h>
#include <stdlib.h>

using namespace std;

int main(int argc, const char *argv[])
{
	assert(argc == 2);
	ofstream outfile(argv[1]);
	if (!outfile) {
		printf("ofstream");
		exit(EXIT_FAILURE);
	}
	string s;
	while (cin >> s) {
		outfile << s << endl;
	}
	outfile.close();
	return 0;
}
