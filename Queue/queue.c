/*
 * http://blog.csdn.net/hopeyouknow/article/details/6736987
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"

//traverse the stack from base to top
void printQueue(myQueue * pQueue)
{
    assert(!(pQueue==NULL || isEmptyQueue(pQueue)));	// pQueue为空 或 NULL 则报错退出
	printf("\n\n ************ 打印开始 ************** \n");
	qNode * pQueueNode = pQueue->front;
	while(pQueueNode != NULL) {
		printf("%d\t", pQueueNode->value);
		pQueueNode = pQueueNode->next;
	}
	printf("\n ************ 打印结束 ************** \n\n");
}

// init queue
myQueue * initQueue() 
{
	myQueue * pQueue = (myQueue *)malloc(sizeof(myQueue));
	if(!pQueue) {
		printf("申请myQueue节点空间错误!\n");
		exit(-1);
	}
	pQueue->rear = NULL;
	pQueue->front = NULL;
	pQueue->queueSize = 0;
	return pQueue;
}

// judge queue is empty or not
Status isEmptyQueue(myQueue * pQueue)
{
	if(!pQueue) {
		printf("请先初始化队列!\n");
		exit(-1);
	} else return pQueue->queueSize == 0;
}

// clear queue
Status clearQueue(myQueue * pQueue)
{
	if(!pQueue) {
		printf("队列已被销毁，不需清空!");
		return 0;
	} else {
		while(!isEmptyQueue(pQueue))
			deQueue(pQueue);
		return 1;
	}
}

// free queue
Status freeQueue(myQueue * pQueue) 
{
	if(!pQueue) {
		printf("队列之前已被销毁!");
		return 0;
	} else {
		clearQueue(pQueue);
		free(pQueue);
		return 1;
	}
}

// get queue front 
qNode * getQueueFront(myQueue * pQueue) 
{
	if(!pQueue || isEmptyQueue(pQueue)) {
		printf("栈为初始化或者空！");
		return NULL;
	} else {
		return pQueue->front;
	}
}

// get queue rear
qNode * getQueueRear(myQueue * pQueue)
{
	if(!pQueue || isEmptyQueue(pQueue)) {
		printf("栈为初始化或者空！");
		return NULL;
	} else {
		return pQueue->rear;
	}
}

// inserat node to queue head
Status enQueue(myQueue * pQueue, QueueNodeElemType item)
{
	if(!pQueue) {
		printf("请先初始化队列\n");
		return 0;
	} else {
		qNode * pQueueNode = (qNode *)malloc(sizeof(qNode)); 
		if(pQueueNode != NULL) {
			pQueueNode->value = item;
			pQueueNode->next = NULL;

			if(isEmptyQueue(pQueue)) {
				pQueue->front = pQueueNode;
			} else {
				pQueue->rear->next = pQueueNode;
			}
			pQueue->rear = pQueueNode;
			(pQueue->queueSize)++;
		}
		return 1;
	}
}

// delete node from queue tail
QueueNodeElemType deQueue(myQueue * pQueue)
{
	if(!pQueue || isEmptyQueue(pQueue)) {
		printf("队列为初始化或者为空，无法从队头取元素!\n");
		exit(-1);		
	} else {
		qNode * pQueueNode = pQueue->front;
		pQueue->front = pQueue->front->next;
		(pQueue->queueSize)--;
		return pQueueNode->value;
	}
}

int main() {
	int i;
	myQueue * pQueue = initQueue();

	for(i=0; i<20; i++) {
		int elem = rand()%100;
		printf("%d\t", elem);
		enQueue(pQueue, elem);
	}


	printQueue(pQueue);
	printf("队头：%d\t\t 队尾：%d\n", getQueueFront(pQueue)->value, getQueueRear(pQueue)->value);

	deQueue(pQueue);
	printQueue(pQueue);
	enQueue(pQueue, 1000);
	printQueue(pQueue);

	clearQueue(pQueue);
	if(isEmptyQueue(pQueue)) printf("成功清空队列");
	printQueue(pQueue);

	
	return 0;
}
