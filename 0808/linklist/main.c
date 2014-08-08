#include "linklist.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	LinkList L = NULL;
	LinkList Q = NULL;
/*
	printf("头插法初始化：\n");
	initLinkListHead(&L, 10);
	printLinkList(L);

	printf("尾查法初始化：\n");
	initLinkListTail(&L, 10);
	printLinkList(L);

	printf("第九个位置插入99\n");
	insertItemAt(&L, 9, 99);
	printLinkList(L);

*/
	printf("Sort init:\n");
	for (int i = 0; i < 10; i++) {
		insertLinkListSort(&L, rand() % 1000);
	}

	printf("Sort init:\n");
	for (int i = 0; i < 10; i++) {
		insertLinkListSort(&Q, rand() % 1000);
	}

	printLinkList(L);
	printLinkList(Q);
	mergeLinkList(&L, Q);
	printLinkList(L);
	Node *p = L;
	while (p->next != NULL) {
		p = p->next; 
	}
	p->next = L->next;
	printf("here\n");

	if (isCircle(L)) {
		printf("L is circle!\n");
	} else {
		printf("L is not a circle.\n");
	}
	//printf("mid元素: %d\n", seekMidItem(L));
	//reversalLinkList(&L);
	//int n;
	//scanf("%d", &n);
	//printf("删除第1个元素\n");
	//Item item = deleteItemAt(&L, n);
	//printLinkList(L);
	//addItem(&L, n);
	//printLinkList(L);


	return 0;
}
