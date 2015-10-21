#include <stdio.h>

void InsertSort(int a[], int n)
{
	int i,j;
	int temp;
	for(i=1; i<n; i++) {
		temp = a[i];
		for(j=i-1; j>=0; j--) {
			if(a[j]>temp) {
				a[j+1] = a[j];
			} else {
				a[j+1] = temp;
				break;
			}
		}
	}
	
}

int main() 
{
	int arr[] = {1, 7, 5, 3, 8, 6, 15, 13, 14};
	int i, n = sizeof(arr)/sizeof(arr[0]);
	InsertSort(arr, n);
	
	for(i=0; i<n; i++) {
		printf("%d\t", arr[i]);
	}

	return 0;
}
