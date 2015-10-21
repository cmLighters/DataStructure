#ifndef __LIST_PROBLEM_H__
#define __LIST_PROBLEM_H__

ListNode * ListReverse1(ListNode * head);

ListNode * ListReverse2(ListNode * head, ListNode * iter);

ListNode * ListSearchNodeByLastIndex(ListNode * head, int index);

ListNode * ListFindMiddleNode(ListNode * head);

void ListPrintReverseOrder(ListNode * head);

ListNode * ListMerge2SortedList(ListNode * head1, ListNode * head2);  //待解决

int ListHasCircle(ListNode * head);

int ListIsCrossed(ListNode * head1, ListNode * head2);

ListNode * ListFirstCrossNodeOf2List(ListNode * head1, ListNode * head2);

ListNode * ListFirstNodeInCircle(ListNode * head);

void ListDeleteNode(ListNode * head, ListNode * pToBeDeleted);

#endif	/* __LIST_PROBLEM_H__ */
