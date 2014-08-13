#include "sims.h"

int main(int argc, char *argv[])
{
	//LinkList to store all account and student info
	pAccount AccountList = NULL;
	pStudent StudentList = NULL;

	//Init the LinkList
	systemInit(CONFIG_FILE, &AccountList, &StudentList);

	Role role;
	Menu menu;
	role = confirmAccount(AccountList);
	if (role == -1) {
		return 0;
	}

	while ((menu = showSystemMenu(role)) != 9) {
		while (getchar() != '\n') {
			continue;
		}
		switch(menu) {
			case 1: 
				if (role == 1) {
					searchStudentAdmin(StudentList);
				} else {
					searchStudentGuest(StudentList);
				}
				break;
			case 2: addStudent(&StudentList); break;
			case 3: updateStudent(StudentList); break;
			case 4: deleteStudent(&StudentList); break;
			case 5: addUserAccount(&AccountList); break;
			case 6: updateUserAccount(AccountList); break;
			case 7: deleteUserAccount(&AccountList); break;
			case 8: searchAccountMenu(AccountList); break;
			default: break;
		}
		saveData(CONFIG_FILE, AccountList, StudentList);
	}
	return 0;
}
