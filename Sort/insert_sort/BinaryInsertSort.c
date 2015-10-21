#include <stdio.h>

// 思路与直接插入排序相同，所不同的是寻找插入的正确位置的方法是用二分法，而不是从i-1 ~ 0 追个进行比较
void BinaryInsertSort(int a[], int n)
{
	int left, right, mid, i, j;
	int temp;
	for(i=1; i<n; i++) {
		temp = a[i];
		left=0;
		right = i-1;
		while(left<=right) {
			mid = (left+right)/2;
			if(a[mid]>temp) right = mid-1;
			else left = mid+1;
		}

		for(j=i-1; j>=left; j--) {
			a[j+1] = a[j];
		}

		a[left] = temp;
	}
	
}

int main() 
{
	int arr[] = {10, 7, 5, 3, 8, 6, 15, 13, 14};
	int i, n = sizeof(arr)/sizeof(arr[0]);
	BinaryInsertSort(arr, n);
	
	for(i=0; i<n; i++) {
		printf("%d\t", arr[i]);
	}

	return 0;
}
