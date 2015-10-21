#ifndef __STACK_H__
#define __STACK_H__

#include "list.h"	//引入ListNode

//typedef int ElemType;
typedef ListNode ElemType;
typedef int Status;

typedef struct SqStack{
    ElemType *base;
    ElemType *top;
    int stackSize;
}SqStack;

void print(SqStack *s);

SqStack* InitStack(SqStack *s);

Status FreeStack(SqStack *s);

Status Push(SqStack *s, ElemType e);

Status Pop(SqStack *s, ElemType *e);

#endif /* __STACK_H__ */
