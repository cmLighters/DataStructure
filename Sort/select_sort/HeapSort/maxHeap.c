/* 堆排关键是建立最小堆（或最大堆）。本实现方法以完全二叉树形式存放在数组中
 */

#include <stdio.h>
#include <stdlib.h>

#define MaxHeapSize 50

typedef int ElemType;

typedef struct HeapHeader {
	int currentSize;
	ElemType * point;
} * pHeapHeader; // pHeap 指向的结构体包含了当前堆所含元素个数和指向堆所在数组的首地址

void initHeap(pHeapHeader pHH, int sz)
{
	if(sz > MaxHeapSize) {
		printf("申请堆大小超过堆最大空间，请重设堆最大空间值\n");
	}
	ElemType * pHeap = (ElemType *)malloc(MaxHeapSize*sizeof(ElemType));
	
	if(!pHeap) {
		printf("开辟存储空间失败！\n");
		exit(-1);
	}

	pHH->currentSize = 0;
	pHH->point = pHeap;
//	return pHH;
}

static void siftDown(pHeapHeader pHH, int start, int size)
{
	int i=start, j=2*i+1;
	ElemType temp = (pHH->point)[i];
	while(j<size) {
		if(j<size-1 && (pHH->point)[j] < (pHH->point)[j+1]) j++;
		if(temp > (pHH->point)[j]) break;
		else {
			 (pHH->point)[i] = (pHH->point)[j];
			 i = j;
			 j = 2*j+1;
		}
	}
	(pHH->point)[i] = temp;
}

void createHeap(pHeapHeader pHH, ElemType arr[], int n)
{
	// 完善的代码需要判断n是否小于DefaultSize
	int i;
	for(i=0; i<n; i++) {
		(pHH->point)[i] = arr[i];
		(pHH->currentSize)++;
	}
	int currentPos = (pHH->currentSize-2)/2;
	while(currentPos >= 0) {
		siftDown(pHH, currentPos, pHH->currentSize);
		currentPos--;
	}
}

static void siftUp(pHeapHeader pHH, int start)
{
	int i=start, j=(i-1)/2;
	ElemType temp = (pHH->point)[i];
	while(j>=0) {
		if(temp < (pHH->point)[j]) break;
		else {
			(pHH->point)[i] = (pHH->point)[j];
			i = j;
			j = (j-1)/2;
		}
	}
	(pHH->point)[i] = temp;

}

int InsertHeap(pHeapHeader pHH, ElemType value)
{
	if(pHH->currentSize >= MaxHeapSize) {
		printf("没有足够堆空间！\n");
		return 0;
	}
	(pHH->point)[pHH->currentSize] = value;
	siftUp(pHH, pHH->currentSize);
	(pHH->currentSize)++;
	return 1;
}

ElemType RemoveMax(pHeapHeader pHH)
{
	if(pHH->currentSize <= 0) {
		printf("堆已经没有元素！\n");
		return 0;
	}
	ElemType temp = (pHH->point)[0];
	(pHH->point)[0] = (pHH->point)[pHH->currentSize-1];
	(pHH->currentSize)--;
	siftDown(pHH, 0, pHH->currentSize);
	return temp;
}

int main() 
{
	ElemType arr[] = {1, 7, 5, 3, 8, 6, 15, 13, 14};
	int i, n = sizeof(arr)/sizeof(arr[0]);

	pHeapHeader pHH = (pHeapHeader)malloc(sizeof(struct HeapHeader));
	initHeap(pHH, n);
    createHeap(pHH, arr, n);	

	InsertHeap(pHH, 10);
	for(i=0; i<pHH->currentSize; i++) {
		printf("%d\t", (pHH->point)[i]);
	}
	printf("\nMaxHeap value: %d\n", RemoveMax(pHH));
	for(i=0; i<pHH->currentSize; i++) {
		printf("%d\t", (pHH->point)[i]);
	}



	return 0;
}
