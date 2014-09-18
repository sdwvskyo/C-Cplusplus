#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <stdexcept>
#define ERR_EXIT(m) \
	do { \
		perror(m);\
		exit(EXIT_FAILURE);\
	}while(0)

using namespace std;

void erasePunct(istringstream &line);
void loadFileByLine(const char *filename, vector<string> &lines);
void printInfo(const vector<string> &lines);

int main(int argc, const char *argv[])
{
	if (argc != 2)
		ERR_EXIT("argument less");

	vector<string> lines;
	loadFileByLine(argv[1], lines);
	printInfo(lines);
	return 0;
}

void printInfo(const vector<string> &lines)
{
	int lineCnt = 0;
	int wordCnt = 0;
	for(vector<string>::const_iterator it = lines.begin(); it != lines.end(); ++it){
		istringstream line(*it);
		if (!line)
			throw runtime_error("istringstream");
		lineCnt++;
		string s;
		while (line >> s)
			wordCnt++;
	}
	cout << "lines: " << lineCnt << endl;
	cout << "words: " << wordCnt << endl;

}

void erasePunct(istringstream &line)
{
	char ch;
	while (line >> ch) {
		if (ispunct(ch))
			line.putback(' ');
	}
}

void loadFileByLine(const char *filename, vector<string> &lines)
{
	ifstream infile(filename);
	if (!infile)
		throw runtime_error("ifstream");

	string line;
	while (getline(infile, line)) {
		lines.push_back(line);
	}
	infile.close();
}
