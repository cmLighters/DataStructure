#include <stdio.h>
#include "list.h"
#include "list_problem.h"


int main() {
	ListNode * head;
	head = CreateList(head, 10);
	printf("%d\n", ListLength(head));
	ListPrint(head);

	ListNode * tail = head;
	while(tail->next) tail = tail->next;
	head = ListReverse2(head, tail);
	ListPrint(head);
	
	ListNode * p =  CreateListNode(100);
	printf("haha: %d\n", p->value);
	head = ListTailInsert(head, p);

	
	ListPrint(head);

	p = ListSearchNodeByIndex(head, 3);
	if(p != NULL) printf("hehe\t %d\n", p->value); else printf("p is NULL!\n");

	
	ListNode * q = ListSearchNodeByLastIndex(head, 3);
	if(q != NULL) printf("hehe\t %d\n", *q); else printf("q is NULL!\n");

	//ListPrintReverseOrder(head);	// 5.从尾到头打印单链表
	ListPrint(head);
	ListDeleteNode(head, q);
	ListPrint(head);

	return 0;
}


/*  两个链表的问题
int main() 
{
	ListNode *head1, *head2, *p, *q;
	head1 = CreateList(head1, 10);
	head2 = CreateList(head2, 20);
	ListPrint(head1);
	ListPrint(head2);

	p = ListSearchNodeByIndex(head1, 5);
	q = ListSearchNodeByIndex(head2, 13);

	p->next = q;
	ListPrint(head1);
	ListPrint(head2);

	if(ListIsCrossed(head1, head2)) printf("链表相交\n");
	else printf("链表不相交\n");
	
	ListNode * FirstCrossNode;
	FirstCrossNode = ListFirstCrossNodeOf2List(head1, head2);
	printf("第一个相交点： %d\n", FirstCrossNode->value);

	return 0;
}
*/
