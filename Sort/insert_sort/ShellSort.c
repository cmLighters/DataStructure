#include <stdio.h>


// 希尔排序的思路是数组中每隔gap长度的元素组成一小组，对这一小组进行插入排序。然后增加i使得另一间隔为gap的小组进行插入排序。
// 外层循环则是进行gap的逐渐减小，直到减为1.
void ShellSort(int a[], int n)
{
	int left=0, right=n-1, gap=right-left+1;
	int temp, i, j;
	while(gap>1) {
		gap = gap/3 + 1;

		for(i=left+gap; i<=right; i++) {
			if(a[i] < a[i-gap]) {
				temp = a[i]; j = i-gap;
				do {
					a[j+gap] = a[j];
					j = j-gap;
				} while(j>=left && a[j]>temp);
				a[j+gap] = temp;
			} // end if
		} // end for

	} // end while
}

int main() 
{
	int arr[] = {10, 7, 5, 3, 8, 6, 15, 13, 14};
	int i, n = sizeof(arr)/sizeof(arr[0]);
	ShellSort(arr, n);
	
	for(i=0; i<n; i++) {
		printf("%d\t", arr[i]);
	}

	return 0;
}

