#include "findword.h"

using namespace std;

int main(int argc, const char *argv[])
{
	if (argc < 2)
		throw runtime_error("argumen less");

	ifstream infile(argv[1]);
	if (!infile)
		throw runtime_error("open file");
	Word word(infile);
	string s;
	cout << "which word to find: " << endl;
	while (cin >> s) {
		word.findWord(s);
	}
	infile.close();
	return 0;
}
