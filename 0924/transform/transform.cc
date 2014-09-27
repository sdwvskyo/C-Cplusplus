#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <fstream>
#include <sstream>

using namespace std;

void wordTransform(ifstream &mapfile, ifstream &input);
map<string, string> buildMap(ifstream &mapfile);
const string & transform(const string &s, const map<string, string> &m);

int main(int argc, const char *argv[])
{
	if (argc < 3)
		throw runtime_error("argument less");
	ifstream mapfile(argv[1]);
	ifstream input(argv[2]);
	wordTransform(mapfile, input);
	mapfile.close();
	input.close();
	return 0;
}

void wordTransform(ifstream &mapfile, ifstream &input)
{
	auto transMap = buildMap(mapfile);
	string line;
	while (getline(input, line)) {
		istringstream stream(line);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else 
				cout << " ";
			cout << transform(word, transMap);
		}
		cout << endl;
	}
}

map<string, string> buildMap(ifstream &mapfile)
{
	map<string, string> transMap;
	string key;
	string value;
	while (mapfile >> key && getline(mapfile, value)) {
		if (value.size() > 1) 
			transMap[key] = value.substr(1);
		else 
			throw runtime_error("No value for" + key);
	}
	return transMap;
}

const string & transform(const string &s, const map<string, string> &m)
{
	auto map_it = m.find(s);
	if (map_it != m.end())
		return map_it->second;
	else
		return s;
}
