/*
 * 思路是：上面的快排当left与right差距很小时用快排并不好，可以选择
 * 1.当right-left有M值时采用插入排序
 * 2.当right-left有M值时返回，等到所有快排结束后，最后对整个数组采用插入排序
 * 这里采用1所述方法
 */

#include <stdio.h>

#define M_LEN 4

void QuickSort(int a[], int left, int right)
{
	if(right-left < M_LEN ) {
		InsertSort(a, left, right);
	}
	int pivotPos = Partition(a, left, right);
	QuickSort(a, left, pivotPos-1);
	QuickSort(a, pivotPos+1, right);
}

int Partition(int a[], int left, int right)
{
	int pivotPos = left, pivot = a[left];
	int i, temp;
	for(i= pivotPos+1; i<=right; i++)
		if(pivot > a[i]) {
			pivotPos++;
			if(i!=pivotPos) {
				temp = a[i];
				a[i] = a[pivotPos];
				a[pivotPos] = temp;
			}
		}
	a[left] = a[pivotPos]; a[pivotPos] = pivot;
	return pivotPos;
}


int main() 
{
	int arr[] = {1, 7, 5, 3, 8, 6, 15, 13, 14};
	int i, n = sizeof(arr)/sizeof(arr[0]);
	QuickSort(arr, 0, n-1);
	
	for(i=0; i<n; i++) {
		printf("%d\t", arr[i]);
	}

	return 0;
}
