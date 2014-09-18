#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct _Student {
	string name;
	int score;
} Student;

int main(int argc, const char *argv[])
{
	vector<Student>	students;
	Student stu;

	while (cin >> stu.name) {
		cin >> stu.score;
		students.push_back(stu);
	}
	
	int count = 0;
	cout << "******************\n" << "score < 60:" << endl;
	for (vector<Student>::iterator it = students.begin();
		it != students.end();
		++it)
	{
		if (it->score < 60) {
			cout << it->name << ":" << it->score << endl;
		}
	}

	return 0;
}

