#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "list.h"

ListNode * CreateListNode(int value) 
{
	ListNode * p = (ListNode *)malloc(sizeof(ListNode));
	p->value = value;
	p->next = NULL;
	return p;
}
	

ListNode * CreateList(ListNode * head, int n) 
{
	srand(time(NULL));

	int i;
	int * arr = (int *)malloc(n * sizeof(int));
	for(i=0; i<n; i++) {
		arr[i] = random()%(n*10) + 1;
		printf("%d\n", arr[i]);
	}

	
	head = NULL;
	ListNode * p = NULL;
	for(i=0; i<n; i++) {
		ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
		if(head == NULL) {
			temp->value = arr[i];
			temp->next = NULL;
			p = temp;
			head = p;
		} else {
			temp->value = arr[i];
			temp->next = NULL;
			p->next = temp;
			p = p->next;
		}
	}
	free(arr);
	p = head;
	return head;
}

// 打印链表
void ListPrint(ListNode * head)
{
	printf("\n打印开始\n");
	ListNode * p = head;
	while(p != NULL) {
		printf("%d\t", p->value);
		p = p->next;
	}
	printf("\n打印结束\n");
}

// 求链表长度
unsigned int ListLength(ListNode * head)
{
	if(head == NULL) return 0;
	int length = 0;
	ListNode * p = head;
	while(p != NULL) {
		length++;
		p = p->next;
	}
	return length;
}

// 通过位置值index查找节点
ListNode * ListSearchNodeByIndex(ListNode * head, int index)
{
	
	if(index < 0) return NULL;
	
	int i = 0;
	ListNode * p = head;
	while(i < index && p != NULL) {
		p = p->next;
		i++;
	}
	if(p!=NULL)
		return p;
	else {
		printf("index 超出链表索引范围!\n");
		return NULL;
	}
}

// Insert node to head
ListNode * ListHeadInsert(ListNode * head, ListNode *node) 
{
	if(head == NULL || node == NULL) return head;

	node->next = head;
	head = node;
	return head;
}

// Insert node to tail
ListNode * ListTailInsert(ListNode * head, ListNode * node)
{
	if(head == NULL || node == NULL) return head;

	ListNode * p = head;
	while(p->next != NULL) { p=p->next;}
	p->next = node;
	return head;
}

// Search node by node value
ListNode * ListSearchNodeByValue(ListNode * head, int value)
{
	if(head == NULL) return NULL;

	ListNode *p = head;
	while(p->value != value && p != NULL) {
		p = p->next;
	}
	return p;
}





