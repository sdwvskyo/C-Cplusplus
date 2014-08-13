#include "sims.h"

//Print the system title
static void printTitle() 
{
	system("clear");
	puts(STARS);
	puts(TITLE);
	puts(STARS);
	printf("\n");
}

//static input int 
static void inputInt(int *n)
{
	fflush(stdin);
	fflush(stdout);
	scanf("%d", n);
	while (getchar() != '\n') {
		continue;
	}
}

//static input double
static void inputDouble(double *n)
{
	fflush(stdout);
	fflush(stdin);
	scanf("%lf", n);
	while (getchar() != '\n') {
		continue;
	}
}

//static input string
static void inputStr(char *str)
{
	fflush(stdout);
	fflush(stdin);
	scanf("%s", str);
	while (getchar() != '\n') {
		continue;
	}
}


//The branch of the system init, init account linklist
static void initAccountList(pAccount *pHead, FILE *fp)
{
	char line[STR_LEN];
	char name[NAME_LEN];
	char pwd[PWD_LEN];
	Role role;
	while (memset(line, 0, STR_LEN), fgets(line, STR_LEN, fp) != NULL) {
		memset(name, 0, NAME_LEN);
		memset(pwd, 0, PWD_LEN);
		if (sscanf(line, "%s%s%d", name, pwd, &role) == 3) {
			pAccount pCur = *pHead;
			pAccount pPre = NULL;
			int flag = 0;
			while (pCur) {
				if (strcmp(name, pCur->name) < 0) {
					break;
				} else if (strcmp(name, pCur->name) == 0) {
					flag = 1;
					break;
				}
				pPre = pCur;
				pCur = pCur->next;
			}
			if(flag == 0) {
				pAccount pNew = (pAccount)calloc(1, sizeof(Account));
				if (pNew == NULL) {
					printf("Assign memory error.\n");
					return;
				}
				strcpy(pNew->name, name);
				strcpy(pNew->pwd, pwd);
				pNew->role = role;
				pNew->next = NULL;
				if (pPre == NULL) {
					*pHead = pNew;
				} else {
					pPre->next = pNew;
				}
				pNew->next = pCur;
			}
		} else {
			printf("Read account config file error.\n");
			while (getchar() != '\n') {
				continue;
			}
		}
	}
}

//Print all of the user account information
static void printAccount(pAccount p) 
{
	printTitle();
	printf("\t\t\tName\tPassword\tRole\t\n");
	while(p) {
		printf("\t\t\t%s\t%s\t\t%d\n", p->name, p->pwd, p->role);
		p = p->next;
	}
	printf("Press any key to continue.\n");
	while (getchar() != '\n') {
		continue;
	}
}

//init student linklist
static void initStudentList(pStudent *pHead, FILE *fp)
{
	char line[STR_LEN];
	char name[NAME_LEN];
	int id;
	int course;
	double score;
	while (memset(line, 0, STR_LEN), fgets(line, STR_LEN, fp) != NULL) {
		memset(name, 0, NAME_LEN);
		if (sscanf(line, "%d%s%d%lf", &id, name, &course, &score) == 4) {
			pStudent pCur = *pHead;
			pStudent pPre = NULL;
			int flag = 0;
			while (pCur) {
				if (id < pCur->id) {
					break;
				} else if (id == pCur->id) {
					flag = 1;
					break;
				}
				pPre = pCur;
				pCur = pCur->next;
			}
			if(flag == 0) {
				pStudent pNew = (pStudent)calloc(1, sizeof(Student));
				if (pNew == NULL) {
					printf("Assign memory error.\n");
					return;
				}
				strcpy(pNew->name, name);
				pNew->id = id;
				pNew->course = course;
				pNew->score = score;
				pNew->next = NULL;
				if (pPre == NULL) {
					*pHead = pNew;
				} else {
					pPre->next = pNew;
				}
				pNew->next = pCur;
			}
		} else {
			printf("Student config file error.\n");
			while (getchar() != '\n') {
				continue;
			}
		}
	}
}

//Print all of the student information
static void printStudent(pStudent p) 
{
	printTitle();
	printf("\t\t\tID\tName        Course    Score\t\n");
	while(p) {
		printf("\t\t\t%04d\t%-12s%-10d%.2f\n", p->id, p->name, p->course, p->score);
		p = p->next;
	}
	printf("Press any key to continue.\n");
	while (getchar() != '\n') {
		continue;
	}
}

//Save the change of the information
void saveData(char *config_file, pAccount AccountList, pStudent StudentList)
{	
	FILE *fp_con = fopen(config_file, "r");
	if(fp_con == NULL) {
		perror("Open confi file error.\n");
		exit(1);
	}

	FILE *fp_acc = NULL;
	FILE *fp_sdt = NULL;
	char line[STR_LEN];
	char str1[STR_LEN];
	char str2[STR_LEN];

	//Open config file
	while(memset(line, 0, STR_LEN), fgets(line, STR_LEN, fp_con) != NULL) {
		memset(str1, 0, STR_LEN);
		memset(str2, 0, STR_LEN);
	   	sscanf(line, "%s%s", str1, str2);
		if (strcmp(str1, "account.txt") == 0) {
			fp_acc = fopen(str2, "w");
			if(fp_con == NULL) {
				perror("Open confi file error.\n");
				exit(1);
			}
		} else if (strcmp(str1, "student.txt") == 0) {
			fp_sdt = fopen(str2, "w");
			if(fp_con == NULL) {
				perror("Open confi file error.\n");
				exit(1);
			}
		} else {
			printf("config file error.\n");
			return;
		}
	}

	while (AccountList) {
		fprintf(fp_acc, "%-16s%-16s%-4d\n", AccountList->name, AccountList->pwd, AccountList->role);
		AccountList = AccountList->next;
	}
	while (StudentList) {
		fprintf(fp_sdt, "%-5d%-16s%-4d%.2f\n", StudentList->id, StudentList->name, StudentList->course, StudentList->score);
		StudentList = StudentList->next;
	}

	fclose(fp_acc);
	fclose(fp_sdt);
	fclose(fp_con);
}


//init system: open config file and init account & student linklist
void systemInit(char *config_file, pAccount *AccountList, pStudent *StudentList)
{
	FILE *fp_con = fopen(config_file, "r");
	if(fp_con == NULL) {
		perror("Open confi file error.\n");
		exit(1);
	}
	FILE *fp_acc = NULL;
	FILE *fp_sdt = NULL;
	char line[STR_LEN];
	char str1[STR_LEN];
	char str2[STR_LEN];

	//Open config file
	while(memset(line, 0, STR_LEN), fgets(line, STR_LEN, fp_con) != NULL) {
		memset(str1, 0, STR_LEN);
		memset(str2, 0, STR_LEN);
	   	sscanf(line, "%s%s", str1, str2);
		if (strcmp(str1, "account.txt") == 0) {
			fp_acc = fopen(str2, "r+");
			if(fp_con == NULL) {
				perror("Open confi file error.\n");
				exit(1);
			}
		} else if (strcmp(str1, "student.txt") == 0) {
			fp_sdt = fopen(str2, "r+");
			if(fp_con == NULL) {
				perror("Open config file error.\n");
				exit(1);
			}
		} else {
			printf("config file error.\n");
			return;
		}
	}

	//init Account LinkList
	initAccountList(AccountList, fp_acc);
	//init student linklist
	initStudentList(StudentList, fp_sdt);

	fclose(fp_acc);
	fclose(fp_con);
	fclose(fp_sdt);
}


//Open the land menu, confir the account and password, return the role of the account
Role confirmAccount(pAccount pHead)
{
	char account[NAME_LEN];
	char password[PWD_LEN];
	int times = TIMES;
	while (times > 0) {
		printTitle();
		printf("->Input your account and password. You have %d time.\n", times);
		int flag = 0;
		int index = 0;
		memset(account, 0, NAME_LEN);
		memset(password, 0, PWD_LEN);
		printf("->Account: ");
		fflush(stdout);
		fflush(stdin);
		scanf("%s", account);
		while (getchar() != '\n') {
			continue;
		}
		printf("->Password: ");
		fflush(stdout);
		fflush(stdin); 
		scanf("%s", password);
		while (getchar() != '\n') {
			continue;
		}
		pAccount pCur = pHead;
		while (pCur) {
			if ((strcmp(pCur->name, account) == 0) && (strcmp(pCur->pwd, password) == 0)) {
				flag = 1;
				break;
			}
			pCur = pCur->next;
		}
		if (flag == 1) {
			return pCur->role;
		} else {
			printf("Invalid account or password.\n");
			while (getchar() != '\n') {
				continue;
			}
		}
		times--;
	}
	printTitle();
	printf("Login fail, Bye!\n");
	return -1;
}

//The branch of the search student menu
static void searchStudentByName(pStudent pHead)
{
	printTitle();
	char name[NAME_LEN];
	printf("->Input student name: ");
	inputStr(name);
	while (pHead) {
		if (strcmp(name, pHead->name) == 0) {
			break;
		}
		pHead = pHead->next;
	}
	if (pHead == NULL) {
		printf("No such student.\n");
	} else {
		printf("\t\t\tID\tName        Course    Score\t\n");
		printf("\t\t\t%04d\t%-12s%-10d%.2f\n", pHead->id, pHead->name, pHead->course, pHead->score);
	}

	printf("Press any key to continue.\n");
	while (getchar() != '\n') {
		continue;
	}
}

//The branch of the search student menu
static void searchStudentById(pStudent pHead)
{
	printTitle();
	int id;
	printf("->Input student ID: ");
	inputInt(&id);
	if (id < 0 || id > 1000) {
		printf("Id must < 1000 && > 0\n");
		id = 0;
	}
	while (pHead) {
		if (id == pHead->id) {
			break;
		}
		pHead = pHead->next;
	}
	if (pHead == NULL) {
		printf("No such student.\n");
	} else {
		printf("\t\t\tID\tName        Course    Score\t\n");
		printf("\t\t\t%04d\t%-12s%-10d%.2f\n", pHead->id, pHead->name, pHead->course, pHead->score);
	}

	printf("Press any key to continue.\n");
	while (getchar() != '\n') {
		continue;
	}
}

//1.1 Administrator search student info menu
void searchStudentAdmin(pStudent pHead)
{
	while (1) {
		int choice = -1;
		printTitle();
		printf("\t\t\tOpition:\n\n");
		printf("\t\t\t->0.search All\n");
		printf("\t\t\t->1.Search by name\n");
		printf("\t\t\t->2.Search by ID\n");
		printf("\t\t\t->9.return\n\n");
		puts(STARS);
		printf("\n");

		printf("->Selete a number: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d", &choice);
		while (getchar() != '\n') {
			continue;
		}
		switch(choice) {
			case 0: printStudent(pHead); break;
			case 1: searchStudentByName(pHead); break;
			case 2: searchStudentById(pHead); break;
			case 9: return; break;
			default: break;
		}
	}
}

//Guest  search student menu
void searchStudentGuest(pStudent pHead)
{
	while (1) {
		int choice = -1;
		printTitle();
		printf("\t\t\tOpition:\n\n");
		printf("\t\t\t->1.Search by name\n");
		printf("\t\t\t->2.Search by ID\n");
		printf("\t\t\t->9.return\n\n");
		puts(STARS);
		printf("\n");

		printf("->Selete a number: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d", &choice);
		while (getchar() != '\n') {
			continue;
		}
		switch(choice) {
			case 1: searchStudentByName(pHead); break;
			case 2: searchStudentById(pHead); break;
			case 9: return;
			default: break;
		}
	}
}

//The branch function of the showSystemMenu
static void showAdminMenu() {
	printTitle();
	printf("\t\t\tOpition:\n\n");
	printf("\t\t\t->1.Search student information\n");
	printf("\t\t\t->2.Add student information.\n");
	printf("\t\t\t->3.Update student information\n");
	printf("\t\t\t->4.Delete student\n");
	printf("\t\t\t->5.Add user account\n");
	printf("\t\t\t->6.Update user information\n");
	printf("\t\t\t->7.Delete user account\n");
	printf("\t\t\t->8.Search user account\n");
	printf("\t\t\t->9.exit\n\n");
	puts(STARS);
	printf("\n");
	printf("->Selete a number: ");
}

//1.2 The branch function of the showSystemMenu
static void showGuestMenu() {
	printTitle();
	printf("\t\t\tOpiton:\n\n");
	printf("\t\t\t->1.Search student information\n");
	printf("\t\t\t->9.exit\n\n");
	puts(STARS);
	printf("\n");
	printf("->Selete a number: ");
}

//Show main system menu and return the choice
Menu showSystemMenu(Role role)
{
	int choice;
		if (role == 1) {
			showAdminMenu();
			fflush(stdin);
			fflush(stdout);
			scanf("%d", &choice);
		} else {
			showGuestMenu();
			fflush(stdin);
			fflush(stdout);
			scanf("%d", &choice);
			while (getchar() != '\n') {
				continue;
			}
		}
	return choice;
}

//2.Add student information
pStudent addStudent(pStudent *pHead)
{
	printTitle();
	int id;
	char name[NAME_LEN];
	printf("->Input student ID: ");
	inputInt(&id);
	if (id < 0 || id > 10000) {
		printf ("ID must be > 0 & < 10000\n");
		while (getchar() != '\n') {
			continue;
		}
		return NULL;
	}
	pStudent pCur = *pHead;
	pStudent pPre = NULL;
	int flag = 0;
	while (pCur) {
		if (id < pCur->id) {
			break;
		} else if (id == pCur->id) {
			printf("The same Id in the system.\n");
			flag = 1;
			break;
		} 
		pPre = pCur;
		pCur = pCur->next;
	}
	pStudent pReturn = NULL;
	if (flag == 0) {
		pStudent pNew = (pStudent)calloc(1, sizeof(pStudent));
		if (pNew == NULL) {
			printf("Assign memeory fail.\n");
			return pReturn;
		}

		pReturn = pNew;
		pNew->id = id;
		printf("->Input student name: ");
		inputStr(name);
		strcpy(pNew->name, name);
		printf("->Input the course: ");
		inputInt(&(pNew->course));
		if (pNew->course < 1 || pNew->course > 20) {
			pNew->course = 1;
			printf ("Course must be > 0 && < 20\n");
			while (getchar() != '\n') {
				continue;
			}
			return NULL;
		}
		printf("->inputInt the score: ");
		inputDouble(&(pNew->score));
		if (pNew->score < 0 || pNew->score > 100) {
			pNew->score = 0.0;
			printf ("Score must be > 0 && < 100\n");
			while (getchar() != '\n') {
				continue;
			}
			return NULL;
		}
		pNew->next = NULL;

		if (pPre == NULL) {
			*pHead = pNew;
		} else {
			pPre->next = pNew;
		}
		pNew->next = pCur;
		printf("Add student successful.\n");
	} else {
		printf("Add student fail.\n");
	}
	printf("Press any key to continue.\n");
	while (getchar() != '\n') {
		continue;
	}
	return pReturn;
}

//3.Upadate student information
pStudent updateStudent(pStudent pHead)
{
	printTitle();
	int id;
	printf("->Input the ID which student you want to update: ");
	inputInt(&id);
	while (pHead) {
		if (pHead->id == id) {
			printf("->Input update name: ");
			inputStr(pHead->name);
			printf("->Input update course: ");
			inputInt(&(pHead->course));
			printf("->Input update score: ");
			inputDouble(&(pHead->score));
			break;
		}
		pHead = pHead->next;
	}
	if (pHead == NULL) {
		printf("Invalid ID.\n");
	} else {
		printf("Update successful.\n");
	}
	printf("Press any key to continue.\n");
	while (getchar() != '\n') {
		continue;
	}
	return pHead;
}

//4.Delete student 
pStudent deleteStudent(pStudent *pHead)
{
	printTitle();
	if ((*pHead) == NULL) {
		printf("Student List empty.\n");
		while (getchar() != '\n') {
			continue;
		}
		return NULL;
	}
	int id;
	printf("Input the Id which student you want to delete: ");
	inputInt(&id);

	pStudent pCur = *pHead;
	pStudent pPre = NULL;
	while (pCur) {
		if (pCur->id == id) {
			break;
		}
		pPre = pCur;
		pCur = pCur->next;
	}

	if (pCur == NULL) {
		printf("Invalid Id.\n");
	} else {
		if (pPre == NULL) {
			(*pHead) = pCur->next;
		} else {
			pPre->next = pCur->next;
		}
		pStudent q = pCur;
		pCur = pCur->next;
		free(q);
		printf("Delete student success.\n");
	}
	printf("Press any key to continue.\n");
	while (getchar() != '\n') {
		continue;
	}
	return pCur;
}

//5.Add user account
pAccount addUserAccount(pAccount *pHead)
{	
	printTitle();
	char name[NAME_LEN];
	char password[PWD_LEN];
	printf("->Input User name: ");
	inputStr(name);

	pAccount pCur = *pHead;
	pAccount pPre = NULL;
	int flag = 0;
	while (pCur) {
		if (strcmp(name, pCur->name) < 0) {
			break;
		} else if (strcmp(name, pCur->name) == 0) {
			printf("The same Username in the system.\n");
			flag = 1;
			break;
		} 
		pPre = pCur;
		pCur = pCur->next;
	}
	pAccount pReturn = NULL;
	if (flag == 0) {
		pAccount pNew = (pAccount)calloc(1, sizeof(pAccount));
		if (pNew == NULL) {
			printf("Assign memeory fail.\n");
			return NULL;
		}
		pReturn = pNew;
		strcpy(pNew->name, name);
		printf("->Input Password: ");
		inputStr(pNew->pwd);
		printf("->Input Role: ");
		inputInt(&(pNew->role));
		if (pNew->role < 0 || pNew->role > 10) {
			pNew->role = 2;
			printf("Invalid role, system set it to 2.\n");
			while (getchar() != '\n') {
				continue;
			}
		}
		pNew->next = NULL;
		if (pPre == NULL) {
			pNew->next = pCur;
			*pHead = pNew;
		} else {
			pNew->next = pCur;
			pPre->next = pNew;
		}
		printf("Add User successful.\n");
	} else {
		printf("Add User fail.\n");
	}
	printf("Press any key to continue.\n");
	while (getchar() != '\n') {
		continue;
	}
	return pReturn;
}

//6.Update user account
pAccount updateUserAccount(pAccount pHead)
{
	printTitle();
	char name[NAME_LEN];
	printf("->Input the account name which User account you want to update: ");
	inputStr(name);
	while (pHead) {
		if (strcmp(pHead->name, name) == 0) {
			printf("->Input update password: ");
			inputStr(pHead->pwd);
			printf("->Input update role(1-10): ");
			inputInt(&(pHead->role));
			if (pHead->role < 0 || pHead->role > 10) {
				pHead->role = 2;
				printf("Invalid role, system set it to 2.\n");
				while (getchar() != '\n') {
					continue;
				}
			}
			break;
		}
		pHead = pHead->next;
	}
	if (pHead == NULL) {
		printf("Invalid ID.\n");
	} else {
		printf("Update successful.\n");
	}
	printf("Press any key to continue.\n");
	while (getchar() != '\n') {
		continue;
	}
	return pHead;
}

//7.Delete user account 
pAccount deleteUserAccount(pAccount *pHead)
{
	printTitle();
	if ((*pHead) == NULL) {
		printf("Student List empty.\n");
		while (getchar() != '\n') {
			continue;
		}
		return NULL;
	}
	char name[NAME_LEN];
	printf("Input the User name which User account you want to delete: ");
	inputStr(name);

	pAccount pCur = *pHead;
	pAccount pPre = NULL;
	while (pCur) {
		if (strcmp(pCur->name, name) == 0) {
			break;
		}
		pPre = pCur;
		pCur = pCur->next;
	}

	if (pCur == NULL) {
		printf("Invalid Id.\n");
	} else {
		if (pPre == NULL) {
			(*pHead) = pCur->next;
		} else {
			pPre->next = pCur->next;
		}
		pAccount q = pCur;
		pCur = pCur->next;
		free(q);
		printf("Delete student success.\n");
	}
	printf("Press any key to continue.\n");
	while (getchar() != '\n') {
		continue;
	}
	return pCur;
}

//The branch of search student menu
static pAccount searchAccountByName(pAccount pHead)
{
	printTitle();
	char name[NAME_LEN];
	printf("->Input account name: ");
	inputStr(name);
	while (pHead) {
		if (strcmp(name, pHead->name) == 0) {
			break;
		}
		pHead = pHead->next;
	}
	if (pHead == NULL) {
		printf("No such user.\n");
	} else {
		printf("Name\tPassword\tRole\n");
		printf("%s\t%s\t\t%d\n", pHead->name, pHead->pwd, pHead->role);
	}
	printf("Press any key to continue.\n");
	while (getchar() != '\n') {
		continue;
	}
	return pHead;
}

//8.Search user account 
pAccount searchAccountMenu(pAccount pHead)
{
	pAccount pCur = NULL;
	while (1) {
		int choice = -1;
		printTitle();
		printf("\t\t\tOptitions:\n\n");
		printf("\t\t\t->0.Search All\n");
		printf("\t\t\t->1.Search by name\n");
		printf("\t\t\t->9.return\n\n");
		puts(STARS);
		printf("\n");

		printf("->Selete a number: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d", &choice);
		while (getchar() != '\n') {
			continue;
		}
		switch(choice) {
			case 0: printAccount(pHead); break;
			case 1: pCur = searchAccountByName(pHead); break;
			case 9: return NULL; break;
			default: break;
		}
	}
	return pCur;
}
