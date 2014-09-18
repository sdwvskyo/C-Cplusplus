/*************************************************************************
	> File Name: vectors.cpp
	> Author: SDW
	> Mail:264459522@qq.com 
	> Created Time: 三  9/ 3 11:39:52 2014
 ************************************************************************/

/*
 * Problem 1: Vectors (AKA C++ ArrayLists...)
 * Say we are writing the next version of a nifty new mail reading program and want to use a Vector (interface in reader appendix) to store all the data. The following structure is used to hold the data of an email message:
 */

struct eMailMsg {
	string to;
	string from;
	string message;
	string subject;
	int date;
	int time;
};

Vector<eMailMsg> email;

void removeSpam(Vector<eMailMsg> & v) {
	for (int i = v.seze(); i >= 0; i--) {
		if (v[i].subject.find("SPAM") == 0) {
			v.removeAt(i);
		}
	}
}
//c) use another vector
struct eMailMsg {
	Vector<string> to;
	string from;
	string message;
	string subject;
	int date;
	int time;
};
