#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Student {
	int id_;
	string name_;
	int score_;

	Student(int id, string name, int score)
		: id_(id), name_(name), score_(score)
	{  }
};

class Cmp {
	public:
		bool operator() (const Student &s1, const Student &s2) {
			if (s1.score_ < s2.score_)
				return true;
			else if ( s1.score_ == s2.score_ && s1.name_ < s2.name_)
				return true;
			else if ( s1.score_ == s2.score_ && s1.name_ == s2.name_ && s1.id_ < s2.id_)
				return true;

			return false;
		}
};


int main(int argc, const char *argv[])
{
	priority_queue<Student, vector<Student>, Cmp> q;
	
	q.push(Student(1, "suyu", 55));
	q.push(Student(2, "sxx", 99));
	q.push(Student(99, "ddd", 0));
	q.push(Student(22, "suasdyu", 155));
	q.push(Student(10, "suyu", 550));
	q.push(Student(11, "suyu11", 5));
	q.push(Student(12, "suyu6", 553));
	q.push(Student(13, "suyu5", 525));
	q.push(Student(14, "suyu4", 515));
	q.push(Student(15, "suyu3", 551));
	q.push(Student(16, "suyu2", 155));

	while (!q.empty()) {
		cout << q.top().id_ << "." << q.top().name_ << ":" << q.top().score_ << endl;
		q.pop();
	}
	return 0;
}
