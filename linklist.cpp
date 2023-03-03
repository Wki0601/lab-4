#include "linklist.h"

void CreateList_wwl(LinkNode*& L, char a[], int n)
{
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	r = L;
	for (int i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[n - i - 1] - '0';
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void InitList_wwl(LinkNode*& L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}

void DestroyList_wwl(LinkNode*& L)
{
	LinkNode* pre = L, * p = L->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

bool ListEmpty_wwl(LinkNode* L)
{
	return (L->next == NULL);
}

int ListLength_wwl(LinkNode* L)
{
	int n = 0;
	LinkNode* p = L;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

void DispList_wwl(LinkNode* L)
{
	LinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}

bool GetElem_wwl(LinkNode* L, int i, ElemType& e)
{
	int j = 0;
	LinkNode* p = L;
	if (i <= 0)	return false;
	while (j < i && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)	return false;
	else {
		e = p->data;
		return true;
	}
}

int LocateElem_wwl(LinkNode* L, ElemType e)
{
	int i = 1;
	LinkNode* p = L->next;
	while (p != NULL && p->data != e) {
		p = p->next;
		i++;
	}
	if (p == NULL)	return 0;
	else	return i;
}

bool Listlnsert_wwl(LinkNode*& L, int i, ElemType e)
{
	int j = 0;
	LinkNode* p = L, * s;
	if (i <= 0)	return false;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)	return false;
	else
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

bool ListDelete(LinkNode*& L, int i, ElemType& e)
{
	int j = 0;
	LinkNode* p = L, * q;
	if (i <= 0)	return false;
	while (j < i - 1 && p != NULL) {
		j++;
		p = p->next;
	}
	if (p == NULL)	return false;
	else {
		q = p->next;
		if (q == NULL)	return false;
		e = q->data;
		p->next = q->next;
		free(q);
		return true;
	}
}
