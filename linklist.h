#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
#define MaxSize 50
#include<iostream>
#include<malloc.h>
using namespace std;

typedef int ElemType;

typedef struct LinkNode {
	ElemType data;
	LinkNode* next;
}LNode;

void CreateList_wwl(LinkNode*& L, char a[], int n);//�������б�

void InitList_wwl(LinkNode*& L);//��ʼ������

void DestroyList_wwl(LinkNode*& L);//�������Ա�

bool ListEmpty_wwl(LinkNode* L);//�жϿձ�

int ListLength_wwl(LinkNode* L);//�����Ա���

void DispList_wwl(LinkNode* L);//������Ա�

bool GetElem_wwl(LinkNode* L, int i, ElemType& e);//������Ա�

int LocateElem_wwl(LinkNode* L, ElemType e);//Ԫ�ز���

bool Listlnsert_wwl(LinkNode*& L, int i, ElemType e);//��������Ԫ��

bool ListDelete(LinkNode*& L, int i, ElemType& e);//ɾ������Ԫ��
#endif // !LINKLIST_H