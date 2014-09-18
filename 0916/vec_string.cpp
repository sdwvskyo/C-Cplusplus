#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
	vector<string> vec;
	string s;
	while (cin >> s) {
		vec.push_back(s);
	}

	for (vector<string>::size_type i = 0; 
		i != vec.size(); 
		i++) 
	{
		cout << vec[i] << endl;	
	}
	return 0;
}
