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

void CreateList_wwl(LinkNode*& L, char a[], int n);//建立单列表

void InitList_wwl(LinkNode*& L);//初始化链表

void DestroyList_wwl(LinkNode*& L);//销毁线性表

bool ListEmpty_wwl(LinkNode* L);//判断空表

int ListLength_wwl(LinkNode* L);//求线性表长度

void DispList_wwl(LinkNode* L);//输出线性表

bool GetElem_wwl(LinkNode* L, int i, ElemType& e);//输出线性表

int LocateElem_wwl(LinkNode* L, ElemType e);//元素查找

bool Listlnsert_wwl(LinkNode*& L, int i, ElemType e);//插入数据元素

bool ListDelete(LinkNode*& L, int i, ElemType& e);//删除数据元素
#endif // !LINKLIST_H