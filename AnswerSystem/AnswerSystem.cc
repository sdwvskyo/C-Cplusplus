#include "AnswerSystem.h"

using namespace std;

Users::Users(const string &filename)
{
	loadUsers(filename);
}

void Users::loadUsers(const string &filename)
{
	filename_ = filename;
	ifstream infile(filename);
	if (!infile)
		throw runtime_error("open file fail");
	string line;
	User user;
	char name[STR_SIZE];
	char password[STR_SIZE];
	while (getline(infile, line)) {
		memset(&user, 0, sizeof user);
		memset(name, 0, sizeof name);
		memset(password, 0, sizeof password);
		sscanf(line.c_str(), "%s %s %d %d", name, password, 
			   &user.lastRecord_, &user.maxRecord_);
		user.name_ = name;
		user.password_ = password;

		users_.push_back(user);
	}
	infile.close();
}

bool Users::landUser() 
{
	system("clear");
	int times = 3;
	string name = "";
	string password = "";
	while (times != 0) {
		--times;
		cout << "Enter the user name: " << endl;
		cout << ">>";
		cin >> name;
		if (hasUser(name)) {
			cout << "Enter the password: "<< endl;
			cout << ">>";
			cin >> password;
			if (password == curUser_.password_) {
				cout << "Welcome " << curUser_.name_ << " !" << endl;
				return true;
			} else {
				cout << "Password invalid." << endl;
			}
		} else {
			cout << "User name invalid!" << endl; 
		}

		cout << times << " times left" << endl;
	}
	return false;
}

bool Users::hasUser(const string &name)
{
	vector<User>::iterator it = users_.begin();
	while (it != users_.end()) {
		if (it->name_ == name) {
			curUser_.name_ = it->name_;	
			curUser_.password_ = it->password_;
			curUser_.lastRecord_ = it->lastRecord_;
			curUser_.maxRecord_ = it->maxRecord_;
			return true;
		}
		++it;
	}
	return false;
}

void Users::updateRecord(int record)
{
	curUser_.lastRecord_ = record;
	if (curUser_.maxRecord_ < record)
		curUser_.maxRecord_ = record;

	vector<User>::iterator it = users_.begin();
	while (it != users_.end()) {
		if (it->name_ == curUser_.name_) {
			*it = curUser_;
			break;
		}
		++it;
	}
}

void Users::printCurUser() const
{
	cout << "User: " << curUser_.name_ 
		 << "  Last Record: " << curUser_.lastRecord_
		 << "  Max Record: " << curUser_.maxRecord_ << endl;
}

static bool cmp(const User &u1, const User &u2)
{
	if (u1.maxRecord_ != u2.maxRecord_)
		return u1.maxRecord_ > u2.maxRecord_;
	else if (u1.lastRecord_ != u2.lastRecord_)
		return u1.lastRecord_ > u2.lastRecord_;
	else 
		return u1.name_ > u2.name_;
}

void Users::printSortByRecord() const
{
	vector<User> users = users_;
	sort(users.begin(), users.end(), cmp);
	vector<User>::iterator it = users.begin();
	while (it != users.end()) {
		cout << it->name_ << "	"
			<< "lastRecord: " << it->lastRecord_ << "  "
			<< "maxRecord_: " << it->maxRecord_ << endl;
		++it;
	}
}

void Users::saveUsersToFile() const
{
	ofstream outfile(filename_);
	if (!outfile)
		throw runtime_error("open file fail");

	char buf[100];
	string line = "";
	vector<User>::const_iterator it = users_.begin();
	while (it != users_.end()) {
		memset(buf, 0, sizeof buf);
		snprintf(buf, sizeof buf, "%s %s %d %d", it->name_.c_str(), 
				it->password_.c_str(), it->lastRecord_, it->maxRecord_);
		line = buf;
		outfile << line << endl;
		++it;
	}
	outfile.close();
}

Questions::Questions(const string &filename)
{
	loadQuestions(filename);
}

void Questions::loadQuestions(const string &filename)
{
	ifstream infile(filename);
	if (!infile)
		throw runtime_error("open file fail");
	Question question;
	memset(&question, 0, sizeof question);

	while (getline(infile, question.question_)) {
		if(!getline(infile, question.options_))
			throw runtime_error("getline");
		if(!getline(infile, question.answer_))
			throw runtime_error("getline");
		questions_.push_back(question);
	}

	infile.close();
}

int Questions::answerQuestions(int size)
{
	if (size > questions_.size())
		size = questions_.size();
	vector<int> vec;
	while (size != vec.size()) {
		int randNum = rand() % questions_.size();
		if (find(vec.begin(), vec.end(), randNum) == vec.end())
			vec.push_back(randNum);
	}
	cout << "Begin: " << endl;
	int price = 100 / size;
	int result = 0;
	string answer;
	for (int i = 0; i < vec.size(); i++) {
		int num = vec[i];
		curQuestion_ = questions_[num];
		cout << i + 1 << ". " << curQuestion_.question_ << endl;
		cout << curQuestion_.options_ << endl;
		cout << ">";
		cin.sync();
		cin >> answer;
		cin.sync();
		if (islower(answer[0])) 
			answer[0] = toupper(answer[0]);
		if (answer == curQuestion_.answer_) {
			result += price;
		}
	}
	cout << "Done!" << endl;
	cout << "Your age is " << result << endl;
	return result;
}

