#include "holy_bible.h"

//按单词频率初始化链表
void sortByFreq(pNode *pHead)
{
	if (*pHead == NULL) {
		printf("LinksList is NULL.\n");
		return;
	}
	pNode pWork = *pHead;
	*pHead = NULL;
	while (pWork) {
		pNode pPre = NULL;
		pNode pCur = *pHead;
		pNode pNext = pWork->next;
		while (pCur) {
			if (pWork->count > pCur->count) {
				break;
			} else {
				pPre = pCur;
				pCur = pCur->next;
			}
		}
		if (pPre == NULL) {
			pWork->next = *pHead;
			*pHead = pWork;
		} else {
			pWork->next = pCur;
			pPre->next = pWork;
		}
		pWork = pNext;
	}
}

//按单词顺序初始化链表
void sortByWordOder(char *filename, pNode *L)
{
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		perror("Open file error.\n");
		return;
	}
	char word[LEN];	
	while (memset(word, 0, LEN), fscanf(fp, "%s", word) == 1) {

		pNode pCur = *L;
		pNode pPre = NULL;
		int flag = 0;
		while (pCur) {
			if (strcmp(word, pCur->word) < 0) {
				break;
			} else if (strcmp(word, pCur->word) == 0) {
				flag = 1;
				(pCur->count)++;
				break;
			} else {
				pPre = pCur;
				pCur = pCur->next;
			}
		}
		if (flag == 0) {
			pNode pNew = (pNode)calloc(1, sizeof(Node));
			if (pNew == NULL) {
				printf("get memory error.\n");
			}
			pNew->next = NULL;
			strcpy(pNew->word, word);
			pNew->count = 1;
			if (pPre == NULL) {
				pNew->next = pCur;
				*L = pNew;
			} else {
				pNew->next = pCur;
				pPre->next = pNew;
			}
		}
	}
	fclose(fp);
}


void printLinkList(pNode p, int size) 
{
	int index = 0;
	while (index < size && p) {
		printf("%10s: %8d\n", p->word, p->count);
		index++;
		p = p->next;
	}
}

