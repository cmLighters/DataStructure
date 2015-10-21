#include <stdlib.h>
#include "list.h"
#include "stack.h"

//非递归反转
ListNode * ListReverse1(ListNode * head)
{
	if(head == NULL || head->next == NULL) return head;
	ListNode * p = head;
	ListNode * ReversedListHead = NULL;
	while(p != NULL) {
		ListNode * temp = p;
		p = p->next;
		temp->next = ReversedListHead;
		ReversedListHead = temp;
	}
	return ReversedListHead;
}

//递归将链表反转， 还有问题？？？？？？
ListNode * ListReverse2(ListNode * head, ListNode * tail)
{
	/*ListNode * tail = head;*/
	/*while(tail->next) tail = tail->next;*/
	if(head == tail) return head;
	ListNode * temp = head;
	head = head->next;
	temp->next = tail->next;
	tail->next = temp;
	return ListReverse2(head, tail);
}

//查找单链表中的倒数第K个结点（k > 0）
ListNode * ListSearchNodeByLastIndex(ListNode * head, int index) 
{
	if(index <= 0 || index > ListLength(head)) return NULL;

	return ListSearchNodeByIndex(head, ListLength(head)-index);
}

// 查找链表的中间结点（n/2 + 1）
ListNode * ListFindMiddleNode(ListNode * head) 
{
	/* return ListSearchNodeByIndex(head, ListLength(head)/2);
	 */

	// 设置两个指针，第一个指针p每次走一步，第二个指针q每次走两步。
	ListNode *p, *q;
	p = head;
	if(p == NULL || p->next == NULL ) return head;
	q = p->next->next;	// q 起点即是p的后两个指针
	while(q != NULL) {
		p = p->next;
		q = q->next;
		if(q == NULL) break;
		else q = q->next;
	}
	return p;
}

// 从尾到头打印单链表
void ListPrintReverseOrder(ListNode * head)
{
	/* 递归解法 
	if(head == NULL) {
		return ;
	} else {
		ListPrintReverseOrder(head->next);
		printf("%d\t", head->value);
	}
	*/

	// 压栈解法开始
	SqStack * s;
	s = InitStack(s);

	ListNode * p = head;
	while(p != NULL) {
		Push(s, *p);
		p = p->next;
	}

	print(s);

	ElemType node;
	while(s->top != s->base) {
		Pop(s, &node);
		printf("%d\t", node);
	}
	printf("\n");

	FreeStack(s);
	// 压栈解法结束
}

// 6. 已知两个单链表pHead1 和pHead2 各自有序，把它们合并成一个链表依然有序
ListNode * ListMerge2SortedList(ListNode * head1, ListNode * head2) 
{

}

// 7. 判断一个单链表中是否有环
int ListHasCircle(ListNode * head)
{
	if(head == NULL || head->next == NULL) return 0;
	ListNode *p, *q;
	p = head;
	q = head->next->next;
	while( p!=NULL && q!=NULL && p != q ) {
		p = p->next;
		q = q->next;
		if(q == NULL) break;
		else q = q->next;
	}
	if(p==NULL || q==NULL) return 0;
	else if( p == q) return 1;
	return 0;
}
	
// 8. 判断两个单链表是否相交
int ListIsCrossed(ListNode * head1, ListNode * head2)
{
	if(head1==NULL || head2==NULL ) return 0;
	ListNode *p = head1;
	while(p->next != NULL) {
		p = p->next;
	}
	ListNode *q = head2;
	while(q->next != NULL) {
		q = q->next;
	}
	if(p == q) return 1;
	else return 0;
}

// 9. 求两个单链表相交的第一个节点
ListNode * ListFirstCrossNodeOf2List(ListNode * head1, ListNode * head2)
{
	if(head1 == NULL || head2 == NULL) return NULL;
	if(!ListIsCrossed(head1, head2)) return NULL;

	int len1 = ListLength(head1);
	int len2 = ListLength(head2);
	ListNode * p = head1;
	ListNode * q = head2;
	if(len1 > len2) {
		int m = len1 - len2;
		while(m > 0) {
			p = p->next;
			m--;
		}
	} else {
		int n = len2 - len1;
		while(n > 0) {
			q = q->next;
			n--;
		}
	}

	while(p != q) {
		p = p->next;
		q = q->next;
	}

	return p;
}

// 10. 已知一个单链表中存在环，求进入环中的第一个节点
ListNode * ListFirstNodeInCircle(ListNode * head) 
{
	if(head == NULL || !ListHasCircle(head)) return NULL;
	ListNode *pFast, *pSlow;
	pFast = pSlow = head;
	while(pFast != NULL && pFast->next != NULL) {
		pSlow = pSlow->next;
		pFast = pFast->next->next;
		if(pSlow == pFast)
			break;
	}
	if(pFast == NULL || pFast->next == NULL) return NULL;

	pSlow = pFast->next;
	pFast->next = NULL;	// 将环断开，这样就出现了两个链表，且链表相交

	ListNode * pNode = ListFirstCrossNodeOf2List(head, pSlow);
	
	return pNode;
}

// 11. 给出一单链表头指针pHead和一节点指针pToBeDeleted，O(1)时间复杂度删除节点pToBeDeleted
// 思路： 若a->b->c->d，现在想删除b，即给出的节点指针指向b。则只需将c值赋给b，然后删除c节点就行了
// 难点是注意可能是最后一个节点
void ListDeleteNode(ListNode * head, ListNode * pToBeDeleted)
{
	if(head == NULL || pToBeDeleted == NULL) return;
	if(pToBeDeleted->next != NULL) {
		pToBeDeleted->value = pToBeDeleted->next->value;
		ListNode * temp = pToBeDeleted->next;
		pToBeDeleted->next = pToBeDeleted->next->next;
		free(temp);
	} else {
		ListNode * pPreDeletedNode = head;
		if(pPreDeletedNode->next == NULL) {
			head = NULL;
			free(pToBeDeleted);
		}
		while(pPreDeletedNode->next != pToBeDeleted)
			pPreDeletedNode = pPreDeletedNode->next;
		pPreDeletedNode->next = NULL;
		free(pToBeDeleted);
	}
}
		

		







