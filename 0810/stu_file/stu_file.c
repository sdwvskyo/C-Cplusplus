#include "stu_file.h"

void initStu(char *filename, LinkList *L)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		fprintf(stdout, "Open file error!\n");
	}

	int id;
	char name[NAME_SIZE];
	float score;

	while((fscanf(fp, "%d%s%f", &id, name, &score)) == 3) {

		Node *pCur = (*L);
		Node *pPre = NULL;

		Node *pnew = (Node *)calloc(1, sizeof(Node));
		if(pnew == NULL) {
			fprintf(stdout, "get memory fail.\n");
		}
		pnew->id = id;
		strcpy(pnew->name, name);
		pnew->score = score;

		if ((*L) == NULL || pnew->id < (*L)->id) {
			pnew->next = (*L); 
			(*L) = pnew;
			continue;
		} 
		while (pCur != NULL && pnew->id > pCur->id) {
			pPre = pCur;
			pCur = pCur->next;
		}
		pnew->next = pCur;
		pPre->next = pnew;	
	}
}


void printStu(LinkList L)
{
	if (L == NULL) {
		printf("LinkList is empty!\n");
		return;
	}
	Node *p = L;
	while (p) {
		printf("%-4d%-14s%-4.1f\n", p->id, p->name, p->score);
		p = p->next;
	}
}
