#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
	vector<int> vec;

	vec.push_back(521);
	vec.push_back(5);
	vec.push_back(88);
	vec.push_back(666);
	vec.push_back(667);
	vec.push_back(636);
	
	for (vector<int>::size_type i = 0; 
		i != vec.size(); 
		i++) 
	{
		cout << vec[i] << endl;
	}

	return 0;
}
