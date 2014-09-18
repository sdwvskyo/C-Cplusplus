#include <iostream>
#include <string>
#include <vector>

using namespace std;

void sort(vector<int> &vec, int (*cmp)(int, int));
int cmp(int a, int b);
void swap(int &a, int &b);

int main(int argc, const char *argv[])
{
	vector<int> vec;
	int tmp;
	for (size_t i = 0; i < 10; ++i) {
		cin >> tmp;
		vec.push_back(tmp);
	}
	::sort(vec, cmp);
	for (vector<int>::iterator it = vec.begin();
		it != vec.end();
		++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}

void sort(vector<int> &vec, int (*cmp)(int, int))
{
	bool flag = true;
	for (size_t ix = 0; 
		ix != vec.size() - 1 && flag; 
		++ix) 
	{
		flag = false;
		for (size_t jx = 0; jx != vec.size() - ix - 1; ++jx) {
			if (cmp(vec[jx], vec[jx+1]) < 0) {
				::swap(vec[jx], vec[jx+1]);
				flag = true;
			}
		}
	}
}

int cmp(int a, int b)
{
	if (a < b)
		return -1;
	else if (a > b)
		return 1;
	else
		return 0;
}

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
