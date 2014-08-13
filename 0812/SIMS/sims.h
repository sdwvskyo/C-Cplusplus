/*
 * Student Information Management System
 */
#ifndef _SIMS_H_
#define _SIMS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STARS "\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"
#define TIMES 3
#define TITLE "\t* * * * * * * * *Student   Information   Management   System* * * * * * * * *\n"
#define NAME_LEN 32		//Name max size
#define STR_LEN 128		//String max size
#define PWD_LEN 16		//Password max size
#define CONFIG_FILE "./config/config.txt"

typedef int Role;		//User role numbers
typedef int Bool;
typedef int Menu;

//User account information struct
typedef struct account {
	char name[NAME_LEN];
	char pwd[PWD_LEN];
	Role role;
	struct account *next;
} Account, *pAccount;

//Student information struct
typedef struct student {
	char name[NAME_LEN];
	int id;
	int course;
	double score;
	struct student *next;
} Student, *pStudent;


void systemInit(char *config_file, pAccount *AccountList, pStudent *StudentList);

Role confirmAccount(pAccount pHead);

Menu showSystemMenu(Role role);

void searchStudentAdmin(pStudent pHead);

void searchStudentGuest(pStudent pHead);

pStudent addStudent(pStudent *pHead);

void saveData(char *config_file, pAccount AccountList, pStudent StudentList);

pStudent updateStudent(pStudent pHead);

pStudent deleteStudent(pStudent *pHead);

pAccount addUserAccount(pAccount *pHead);

pAccount updateUserAccount(pAccount pHead);

pAccount deleteUserAccount(pAccount *pHead);

pAccount searchAccountMenu(pAccount pHead);

#endif
