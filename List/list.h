#ifndef __LIST_H__
#define __LIST_H__


typedef struct ListNode {
	int value;
	struct ListNode * next;
} ListNode;

ListNode * CreateListNode(int value);

ListNode * CreateList(ListNode * head, int n);

void ListPrint(ListNode * head);

unsigned int ListLength(ListNode * head);

ListNode * ListReverse(ListNode * head, ListNode * iter);

ListNode * ListHeadInsert(ListNode * head, ListNode *node);

ListNode * ListTailInsert(ListNode * head, ListNode * node);

ListNode * ListSearchNodeByValue(ListNode * head, int value);

ListNode * ListSearchNodeByIndex(ListNode * head, int index);


#endif	/* __LIST_H__ */
