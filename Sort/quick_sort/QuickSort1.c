/*
 * 思路是： 用arr数组的left作为初始pivotPos，a[left]作为pivot。从left到right比较a[left]与a[i]大小，若小于，则pivotPos++，然后a[pivotPos] = a[i]。最终将a[left]与a[pivotPos]值对调；
 * 返回pivotPos作为下次快排的边界值。
 */

#include <stdio.h>

void QuickSort(int a[], int left, int right)
{
	if(left>=right) return;
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
