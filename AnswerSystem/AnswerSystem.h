#ifndef ANSWERSYSTEM_H_
#define ANSWERSYSTEM_H_ 

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <set>

using std::string;
using std::vector;

const int STR_SIZE = 32;

struct User {
	string name_;
	string password_;
	int lastRecord_;
	int maxRecord_;
};

struct Question {
	string question_;
	string options_;
	string answer_;
};

class Users {
	public:
		Users() { }
		Users(const string &filename);
		~Users() { }

		void loadUsers(const string &filename);
		bool landUser();
		void updateRecord(int record);
		void printSortByRecord() const;
		void saveUsersToFile() const;
		void printCurUser() const;
	private:
		vector<User> users_;
		User curUser_;
		string filename_;
		bool hasUser(const string &name);
};


class Questions {
	public:
		Questions() { }
		Questions(const string &filename);
		~Questions() { }

		void loadQuestions(const string &filename);
		int answerQuestions(int size = 20);
	private:
		vector<Question> questions_;
		Question curQuestion_;
};

#endif  /*ANSWERSYSTEM_H_*/
