#ifndef __STACK_H__
#define __STACK_H__

//#include "bi_tree.h"	//引入BiNode

typedef int StackElemType;	// 将你要设置的栈存储的节点类型设为StackElemType。即将int改为type of stack node
typedef int Status;

typedef struct SqStack{
    StackElemType *base;
    StackElemType *top;
    int stackSize;
}SqStack;

void printStack(SqStack *s);

SqStack* initStack();

Status freeStack(SqStack *s);

Status pushStack(SqStack *s, StackElemType e);

Status popStack(SqStack *s, StackElemType *e);

#endif /* __STACK_H__ */
