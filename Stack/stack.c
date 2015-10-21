/*implement a stack in c*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 10


//traverse the stack from base to top
void printStack(SqStack *s){
    assert(s);
    StackElemType *elem = s->base;
    if(s->base == s->top){
	printf("This is an empty stack!\n");
    }
    for(elem ; elem != s->top ; elem++){
	printf("element is %d", *elem);
	printf("\n");
    }
    
}

//init statck 
SqStack* initStack(){
    SqStack * s = (SqStack*)malloc(sizeof(SqStack));
    if(!s)
	exit(0);
    s->base = (StackElemType*)malloc(STACK_INIT_SIZE*sizeof(StackElemType));
    s->top = s->base;
    s->stackSize = STACK_INIT_SIZE;
    printf("Init stack successfully!\n");
    return s;
} 

// judge stack is empty or not
Status isEmptyStack(SqStack *s) {
	if(s->top < s->base) {
		printf("栈顶在栈底下面，出错!!!\n");
		exit(-1);
	} else return s->top == s->base;
}

//free stack 
Status freeStack(SqStack *s){
    if(!s){
	printf("Stack is null no need to free!\n");
	return 0;
    }else{
	free(s->base);
   	free(s);
	return 1;
    }
}


//push element into stack
Status pushStack(SqStack *s, StackElemType e){
    assert(s);
    //stack is full, need more space
    if(s->top - s->base >= s->stackSize){
	s->base = (StackElemType*)realloc(s->base, (s->stackSize + STACK_INCREMENT)*sizeof(StackElemType));
        if(!s->base){
	    printf("realloc failed!\n");
	    exit(1);
	}
	s->top = s->base + s->stackSize;
 	s->stackSize += STACK_INCREMENT;
    }
	*(s->top) = e;
	++(s->top);
	return 1;
}

//pop out elem from stack,  调用方式是Pop(s, &Elem)，将pop后结果放在Elem中
Status popStack(SqStack *s, StackElemType *e){
    assert(s);
    if(s->base == s->top){
	printf("It's a empty stack\n");
	return 0;
    }
    --(s->top);
	*e = *(s->top);
    return 1;
}


int main()
{
    int i;
    SqStack *s;
    s = initStack();
    for(i = 0 ; i < 20 ; i++){
        int elem = rand()%100;
		printf("%d\t", elem);
	//	StackElemType temp = {elem, NULL};
		pushStack(s, elem);
    }
	printf("\n");
    printStack(s);
	StackElemType pPopNode;
	popStack(s, &pPopNode);
	printf("%d\n", pPopNode);
	popStack(s, &pPopNode);
	printf("%d\n", pPopNode);
	
    freeStack(s);
}

