#include <stdio.h>

void merge(int arr1[], int arr2[], int left, int mid, int right)
{
	int i;
	for(i=left; i<=right; i++) arr2[i] = arr1[i];

	int s1=left, s2=mid+1, t=left;
	while(s1<=mid && s2<=right) {
		if(arr2[s1] <= arr2[s2]) { arr1[t++] = arr2[s1++]; }
		else { arr1[t++] = arr2[s2++]; }
	}
	while(s1<=mid) arr1[t++] = arr2[s1++];
	while(s2<=right) arr1[t++] = arr2[s2++];
}

void MergeSort(int arr1[], int arr2[], int left, int right)
{
	if(left>=right) return;
	int mid = (left+right)/2;
	MergeSort(arr1, arr2, left, mid);
	MergeSort(arr1, arr2, mid+1, right);
	merge(arr1, arr2, left, mid, right);
}


int main() 
{
	int arr[] = {1, 7, 5, 3, 8, 6, 15, 13, 14};
	int arr2[10];
	int i, n = sizeof(arr)/sizeof(arr[0]);
	MergeSort(arr, arr2, 0, 8);
	
	for(i=0; i<n; i++) {
		printf("%d\t", arr[i]);
	}

	return 0;
}
