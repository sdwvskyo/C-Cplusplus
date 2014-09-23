#include "AnswerSystem.h"

using namespace std;

int main(int argc, const char *argv[])
{
	if (argc < 2) 
		throw runtime_error("argument less");

	srand(time(NULL));
	Users users(argv[1]);
	Questions questions(argv[2]);

	if (users.landUser()) {
		users.printCurUser();
		int res = questions.answerQuestions(20);
		users.updateRecord(res);
		users.printCurUser();
		users.saveUsersToFile();
	}

	return 0;
}
