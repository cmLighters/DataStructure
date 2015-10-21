#include <stdio.h>

void SelectSort(int a[], int n)
{
	int i,j;
	int m, min, temp;
	for(i=0; i<n-1; i++) {
		min = a[i];
		m = i;
		for(j=i+1; j<n; j++) {
			if(a[j]<min) {
				min = a[j];
				m = j;
			}		
		}
		temp = a[i];
		a[i] = a[m];
		a[m] = temp;
	}	
}

int main() 
{
	int arr[] = {1, 7, 5, 3, 8, 6, 15, 13, 14};
	int i, n = sizeof(arr)/sizeof(arr[0]);
	/*BubbleSort(arr, n);*/
	SelectSort(arr, n);
	
	for(i=0; i<n; i++) {
		printf("%d\t", arr[i]);
	}

	return 0;
}
