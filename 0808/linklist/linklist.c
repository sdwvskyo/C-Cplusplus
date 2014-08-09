#include "linklist.h"

//尾插法初始化链表，加入n个元素
void initLinkListTail(LinkList *L, int n)
{
	Node *pnew = NULL;
	Node *ptail = *L; 
	int i;
	for (i = 0; i < n; i++) {
		pnew = (Node *)calloc(1, sizeof(Node));
		if (pnew == NULL) {
			printf("get memory failure!\n");
			return;
		}

		pnew->data = rand() % 1000;
		if (*L == NULL) {
			(*L) = pnew;
		} else {
			ptail->next = pnew;
		}
		ptail = pnew;
	}
}
//头插法初始化链表，加入n个元素
void initLinkListHead(LinkList *L, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		Node *pnew = (Node *)calloc(1, sizeof(Node));
		if(pnew == NULL) {
			printf("get memory error!\n");
			return;
		}
		pnew->data = rand() % 1000;
		pnew->next = (*L);
		(*L) = pnew;
	}
}

//建立有顺序的链表
void insertLinkListSort(LinkList *L, Item item)
{
	Node *p = (*L);
	Node *q = NULL;
	Node *pnew = (Node *)calloc(1, sizeof(Node));
	if (pnew == NULL) {
		printf("Get memory error!\n");
		return;
	}
	pnew->data = item;
	pnew->next = NULL;
	if (p == NULL || item < p->data) {
		pnew->next = (*L);
		(*L) = pnew;
	} else {
		while(p != NULL) {
			if (item < p->data) {
				break;
			}
			q = p;
			p = p->next;
		}
		pnew->next = p;
		q->next = pnew;
	}
}

//找到值为item的元素，返回它的坐标
int seekItem(LinkList L, Item item)
{
	Node *p = L;
	int cnt = 0;
	if (L == NULL) {
		printf("LinkList is NULL.\n");
		return -1;
	}
	while (p != NULL) {
		cnt++;
		if (p->data == item) {
			return cnt; 
		}
		p = p->next;
	}
	return -1;
}

//删除第i个元素，返回其值
Item deleteItemAt(LinkList *L, int index)
{
	Item item;
	int i;
	Node *p = (*L);
	Node *q = NULL;
	if ((*L) == NULL) {
		printf("The LinkList is null\n");
		return -1;
	}
	for (i = 1; i < index; i++) {
		if (p == NULL) {
			printf("can not find %dth item\n", i);
			return -1;
		} else {
			q = p;
			p = p->next;
		}
	}
	if (index <= 1) {
		item = p->data;
		(*L) = p->next;
	} else {
		item = p->data;
		q->next = p->next;
	}
	free(p);
	return item;
}

//增加元素item
void addItem(LinkList *L, Item item)
{
	Node *pnew = (Node *)calloc(1, sizeof(Node));
	if (pnew == NULL) {
		printf("get memory error!\n");
		return;
	} else {
		pnew->data = item;
		pnew->next = (*L);
		(*L) = pnew;
	}
}

//在第i个位置后插入元素item
void insertItemAt(LinkList *L, int index, Item item)
{
	int i;
	Node *p = (*L);
	for (i = 1; i < index; i++) {
		if (p == NULL) {
			printf("can not find %dth item\n", i);
			return;
		} else {
			p = p->next;
		}
	}
	Node *pnew = (Node *)calloc(1, sizeof(Node));
	if (pnew == NULL) {
		printf("get memory failure!\n");
		return;
	}
	pnew->data = item;
	if (*L == NULL) {
		(*L) = pnew;
		pnew->next = NULL;
	} else {
		pnew->next = p->next;
		p->next = pnew;
	}
}

//逐个打印链表元素
void printLinkList(LinkList L)
{
	Node *p = L;
	int index = 1;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

//单链表翻转
void reversalLinkList(LinkList *L)
{
	if (*L == NULL) {
		printf("LinkList is NULL.\n");
		return;
	}
	Node *p = (*L)->next;
	(*L)->next = NULL;
	while (p != NULL) {
		Node *tmp = p;
		p = p->next;
		tmp->next = (*L);
		(*L) = tmp;
	}
}

//找出倒数第4个元素
Item seekBackforward4th(LinkList L)
{
	Node *p = L;
	Node *q = L;
	if (L == NULL) {
		printf("LinkList is NULL.\n");
		return -1;
	}
	int i;
	for (i = 0; i < 4; i++) {
		if (p == NULL) {
			printf("LinkList do not have 4 elements.\n");
		} else {
			p = p->next;
		}
	}
	while (p != NULL) {
		p = p->next;
		q = q->next;
	}
	return q->data;
}

//找出单链表的中间元素
Item seekMidItem(LinkList L)
{
	if (L == NULL) {
		printf("empty linklist.\n");
		return -1;
	}
	Node *p = L;
	Node *q = L;
	while (p != NULL) {
		p = p->next;
		if (p == NULL) {
			break;
		}
		p = p->next;
		if (p == NULL) {
			break;
		}
		q = q->next;
	}
	return q->data;
}

//两个不交叉的有序链表的合并
void mergeLinkList(LinkList *L1, LinkList L2)
{
	Node *p1 = (*L1);
	Node *p2 = L2;
	if ((*L1)->data < L2->data) {
		p1 = p1->next;
	} else {
		(*L1) = L2;
		p2 = p2->next;
	}
	Node *ptail = (*L1);
	while (p1 != NULL && p2 != NULL) {
		if (p1->data < p2->data) {
			ptail->next = p1;
			ptail = p1;
			p1 = p1->next;
		} else {
			ptail->next = p2;
			ptail = p2;
			p2 = p2->next;
		}
	}
	while (p1 != NULL) {
		ptail->next = p1;
		ptail = p1;
		p1 = p1->next;
	}
	while (p2 != NULL) {
		ptail->next = p2;
		ptail = p2;
		p2 = p2->next;
	}
}

//判断单链表是否有环
int isCircle(LinkList L)
{
	if (L == NULL) {
		printf("Empty Linklist.\n");
		return -1;
	}
	Node *p = L;
	Node *q = L;
	while (p->next != NULL) {
		p = p->next;
		if (q == p) {
			return 1;
		}
		p = p->next;
		if (q == p) {
			return 1;
		} else if (p == NULL) {
			return 0;
		}
		q = q->next;
	}
	return 0;
}

//判断两个单链表是否相交
int isIntersect(LinkList L1, LinkList L2)
{
	Node *p1 = L1;
	int flag = 0;
	while (p1 != NULL) {
		Node *p2 = L2;
		Node *tmp = p1;
		while (p2 != NULL && tmp != NULL) {
			if (tmp->data == p2->data) {
				flag = 1;
				tmp = tmp->next;
			} else {
				if (flag == 1) {
					flag = 0;
					break;
				}
				flag = 0;
			}
			p2 = p2->next;
		}
		if (p2 == NULL && flag == 1) {
			break;
		} else {
			p1 = p1->next;
		}
	}
	return flag;
}


//两个单链表相交，计算相交点
int intersectItem(LinkList L1, LinkList L2)
{
	Node *p1 = L1;
	int flag = 0;
	Item n = -1;
	while (p1 != NULL) {
		Node *p2 = L2;
		Node *tmp = p1;
		while (p2 != NULL && tmp != NULL) {
			if (tmp->data == p2->data) {
				if (flag == 0) {
					n = tmp->data;
				}
				flag = 1;
				tmp = tmp->next;
			} else {
				if (flag == 1) {
					flag = 0;
					n = -1;
					break;
				}
				n = -1;
				flag = 0;
			}
			p2 = p2->next;
		}
		if (p2 == NULL && flag == 1) {
		   	break;
		} else {
			p1 = p1->next;
		}
	}
	return n;
}


//删除单链表中的重复元素
void deleteRecurItem(LinkList L) {
	if (L == NULL) {
		printf("Empty LinkList.\n");
		return;
	}
	Node *p = L;
	while (p != NULL) {
		Node *tmp = p->next;
		while(tmp != NULL) {
			if (p->data == tmp->data) {
				p->next = tmp->next;
				Node *q = tmp;
				tmp = tmp->next;
				free(q);
			} else {
				tmp = tmp->next;
			}
		}
		p = p->next;
	}
}

