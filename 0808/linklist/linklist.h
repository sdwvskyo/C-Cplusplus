#ifndef _LINKLIST_H
#define _LINKLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;

typedef struct node
{
	Item data;
	struct node *next;
} Node, *LinkList;

void initLinkListTail(LinkList *L, int n);

void initLinkListHead(LinkList *L, int n);

void insertLinkListSort(LinkList *L, Item item);

int seekItem(LinkList L, Item iitem);

void addItem(LinkList *L, Item item);

Item seekBackforward4th(LinkList L);

void printLinkList(LinkList L);

void insertItemAt(LinkList *L, int i, Item item);

void reversalLinkList(LinkList *L);

Item deleteItemAt(LinkList *L, int index);

Item seekMidItem(LinkList L);

void mergeLinkList(LinkList *L1, LinkList L2);

int isCircle(LinkList L);

int isIntersect(LinkList L1, LinkList L2);

void deleteRecurItem(LinkList L);

int intersectItem(LinkList L1, LinkList L2);

#endif

