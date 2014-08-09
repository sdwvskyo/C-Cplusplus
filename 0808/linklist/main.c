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
	int n;
	printf("Sort init:\n");
	for (int i = 0; i < 10; i++) {
		scanf("%d", &n);
		insertLinkListSort(&L, n);
	}

	printf("Sort init:\n");
	for (int i = 0; i < 10; i++) {
		scanf("%d", &n);
		insertLinkListSort(&Q, n);
	}

	printLinkList(L);
	printLinkList(Q);
	printf("xiangjiaodian: %d.\n", intersectItem(L, Q));
//	if (isIntersect(L, Q)) {
//		printf("Is Intersect.\n");
//	} else {
//		printf("is not intersect.\n");
//	}
//	printf("Delete recur item:\n");
//	deleteRecurItem(L);
//	printLinkList(L);

	//mergeLinkList(&L, Q);
	//printLinkList(L);
	//Node *p = L;
	//while (p->next != NULL) {
	//	p = p->next; 
	//}
//	p->next = L;

	//if (isCircle(L)) {
	//	printf("L is circle!\n");
	//} else {
	//	printf("L is not a circle.\n");
	//}
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
