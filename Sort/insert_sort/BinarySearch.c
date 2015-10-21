#include <stdio.h>

// 返回在数组中的位置，如a[0],则返回1，a[3],则返回4
int BinarySearch(int a[], int n, int value)
{
	int left=0, right=n-1, mid;
	while(left<=right) {
		mid = (left+right)/2;
		if(a[mid] == value) return mid+1;
		else if(a[mid] > value) right = mid-1;
		else left = mid+1;
	}
	return 0;
}

int main() 
{
	int arr[] = {1, 3, 5, 6, 7, 8, 13, 14, 15};
	int i, n = sizeof(arr)/sizeof(arr[0]);
//	BinarySearch(arr, n, 13);
	
	printf("%d\t", BinarySearch(arr, n, 9));

	return 0;
}

