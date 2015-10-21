#include <stdio.h>

void BubbleSort(int a[], int n)
{
	int i,j;
	int temp;
	for(i=n-1; i>0; i--) {
		for(j=0; j<i; j++) {
			if(a[j]>a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
}

int main() 
{
	int arr[] = {1, 7, 5, 3, 8, 6, 15, 13, 14};
	int i, n = sizeof(arr)/sizeof(arr[0]);
	BubbleSort(arr, n);
	
	for(i=0; i<n; i++) {
		printf("%d\t", arr[i]);
	}

	return 0;
}
