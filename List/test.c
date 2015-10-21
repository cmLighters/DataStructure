#include <stdio.h>
#include "list.h"

int main() 
{
	ListNode temp = {12345, NULL};
	ListNode * p = &temp;
	printf("%d\n", *p);
	printf("%d\n", temp);
	return 0;
}
	
