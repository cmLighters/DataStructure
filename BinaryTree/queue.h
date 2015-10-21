#ifndef __QUEUE_H__
#define __QUEUE_H__

// 队列的链表实现。 队列由pQueue指向myQueue结构体，该结构体中front指针指向队列头，rear指向队列尾。队列节点类型为QueueNode，其内部存储值类型为QueueNodeElemType

#include "bi_tree.h"	//引入BiNode

typedef BiNode * QueueNodeElemType;	// 将你要设置的栈存储的节点类型设为QueueElemType。即将int改为type of queue node
typedef int Status;

typedef struct QueueNode {
	QueueNodeElemType value;
	struct QueueNode * next;
} qNode;

typedef struct myQueue{
    qNode *front;
    qNode *rear;
    int queueSize;
} myQueue;

void printQueue(myQueue *pQueue);

myQueue* initQueue();

Status isEmptyQueue(myQueue * pQueue);

Status clearQueue(myQueue * pQueue);

Status freeQueue(myQueue * pQueue);

qNode * getQueueFront(myQueue * pQueue);

qNode * getQueueRear(myQueue * pQueue);

Status enQueue(myQueue * pQueue, QueueNodeElemType item);

QueueNodeElemType deQueue(myQueue * pQueue);

#endif /* __QUEUE_H__ */
