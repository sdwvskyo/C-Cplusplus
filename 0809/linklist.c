#include <stdio.h>

typedef int Item;

typedef struct Node {
	Item data;
	struct Node *next;
} Node;

typedef struct Node * LinkList;

bool getItem(LinkList L, int i, Item *e) {
	int j = 1;
	Node *p = L->next;
	while(P && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return false;
	*e = p->data;
	return true;
}

bool insertItem(LinkList L, int i, Item e) {
	Node *p, *s;
	int j = 1;
	p = L->next;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j>i)
		return false;
	s = (Node *)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;

	return true;
}

bool deleteitem(LinkList L, int i, Item *e) {
	Node *p = L-next;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p && j > i)
		return false;
	Node *q = p->next;
	p-next = q-next;
	*e = q->data;
	free(q);
	return true;
}

bool createListHead(LinkList L) {
	L = (Node *)malloc(sixeof(Node));
	if (L == NULL)
		return false;
	else {
		L->next = NULL;
		L->data = 0;
		return true;
	}
}
}


