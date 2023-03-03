#include<iostream>
#include"linklist.h"
#include<string>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;

//合并链表
void Add(LNode* L1, LNode* L2, LNode*& L) {
	InitList_wwl(L);
	LNode* s, * r = L;
	int carry = 0;//携带进位
	while (L1 != NULL && L2 != NULL) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = (L1->data + L2->data + carry) % 10;
		r->next = s;	r = s;
		carry = (L1->data + L2->data + carry) / 10;
		L1 = L1->next;
		L2 = L2->next;
	}
	if (L1 == NULL)	L1 = L2;
	while (L1 != NULL) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = (L1->data + carry) % 10;
		r->next = s;	r = s;
		carry = (L1->data + carry) / 10;
		L1 = L1->next;
	}
	if (carry) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = carry;
		r->next = s;	r = s;
	}
	r->next = NULL;
}

//逆序链表
void Reverse_wwl(LNode*& L) {
	LNode* p = L->next, * q;
	L->next = NULL;
	while (p != NULL) {
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}

int main() {
	LNode* L1, * L2, * L;
	char s1[MaxSize], s2[MaxSize];
	cout << "请输入整数1："; scanf("%s", s1);
	cout << "请输入整数2："; scanf("%s", s2);
	CreateList_wwl(L1, s1, strlen(s1));
	CreateList_wwl(L2, s2, strlen(s2));
	Add(L1->next, L2->next, L);
	DestroyList_wwl(L1);
	DestroyList_wwl(L2);
	Reverse_wwl(L);
	DispList_wwl(L);
	DestroyList_wwl(L);
	return 0;
}