/*
 * http://blog.csdn.net/chenhanzhun/article/details/19768567
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bi_tree.h"
#include "stack.h"
#include "queue.h"

// 判断二叉树是否为空
int isEmptyBiTree(BiTree root)
{
	return root == NULL;
}

// 初始化二叉树
BiTree initBiTree(BiTree root)
{
	return root;
}

// 创建二叉树节点
BiNode * createBiNode(ElemType value)
{
	BiNode * p = (BiNode *)malloc(sizeof(BiNode));
	if(!p) {
		printf("Malloc New Node ERROR!\n");
		exit(1);
	}
	p->value = value;
	p->left = NULL;
	p->right = NULL;
	return p;
}

// 创建二叉树, n为要创造的二叉树节点的数量
BiTree createBiTree(BiTree root, ElemType arr[], int n)
{
	static int iter = 0;	//iter 必须是static类型!!!
	ElemType value = arr[iter];
	printf("节点的值为：%c\t", value);
	printf("\n");

	if(value == '*') {
		root = NULL;
	} else {
		root = createBiNode(value);
		++iter;
		root->left = createBiTree(root->left, arr, n);
		++iter;
	    root->right = createBiTree(root->right, arr, n);	
	}
	if(iter == n-1) iter = 0;
	return root;
}

// 先序递归遍历二叉树
void preOrder1_BiTree(BiTree root) 
{
	if(root != NULL) {
		printf("%c\t\t", root->value);
		preOrder1_BiTree(root->left);
		preOrder1_BiTree(root->right);
	} else printf("*\t\t");
}

// 先序非递归遍历二叉树
void preOrder2_BiTree(BiTree root)
{
	if(root == NULL) {
		printf("*\t\t");
	} else {
		SqStack *s;
		s = initStack(s);
		pushStack(s, *root);
		while(!isEmptyStack(s)) {
			StackElemType temp;
			popStack(s, &temp);
			printf("%c\t\t", temp.value);	// 前序
			if(temp.right == NULL) {
				printf("*\t\t");
			} else {
				pushStack(s, *(temp.right));
			}
			if(temp.left == NULL) {
				printf("*\t\t");
			} else {
				pushStack(s, *(temp.left));
			}
		} // end of while
	}
}

// 中序递归遍历二叉树
void inOrder1_BiTree(BiTree root)
{
	if(root != NULL) {
		inOrder1_BiTree(root->left);
		printf("%c\t\t", root->value);
		inOrder1_BiTree(root->right);
	} else printf("*\t\t");
}

// 中序非递归遍历二叉树
void inOrder2_BiTree(BiTree root)
{
	if(root == NULL) {
		printf("*\t\t");
	} else {
		SqStack *s;
		s = initStack(s);
		BiNode * p = root;
		while(p != NULL) {	// 二叉树最左边沿依次入栈
			pushStack(s, *p);
			p = p->left;
		}
		while(!isEmptyStack(s)) {
			StackElemType temp;
			popStack(s, &temp);
			if(temp.left == NULL) printf("*\t\t");
			printf("%c\t\t", temp.value);	// 中序

			if(temp.right == NULL) {
				printf("*\t\t");
			} else {
				p = temp.right;
				while(p != NULL) {
					pushStack(s, *p);
					p = p->left;
				}
			}
		} // end of while
	}
}

// 后序递归遍历二叉树
void postOrder1_BiTree(BiTree root)
{
	if(root != NULL) {
		postOrder1_BiTree(root->left);
		postOrder1_BiTree(root->right);
		printf("%c\t\t", root->value);
	} else printf("*\t\t");
}

// 后续非递归遍历二叉树
void postOrder2_BiTree(BiTree root)
{
	if(root == NULL) {
		printf("*\t\t");
	} else {
		SqStack * s;
		s = initStack(s);
		BiNode * p = root, *top;
		while(p != NULL) {
			pushStack(s, *p);
			p = p->left;
		}
		while(!isEmptyStack(s)) {
			top = (s->top)-1;	// top 指向栈顶元素
			if(top->left == NULL)
				printf("*\t\t");

			if(top->right == NULL) {
				printf("*\t\t");
				
				StackElemType temp;
				popStack(s, &temp);
				printf("%c\t\t", temp.value);
			} else if(top->right == NULL + 0xffff) {
				StackElemType temp;
				popStack(s, &temp);
				printf("%c\t\t", temp.value);
			} else {
				p = top->right;
				top->right = NULL+0xffff;		// 此处将top->right指向一个特殊地址，程序运行时不可能指向的地址。这种top志向的节点是在二叉树中需要遍历两次的节点！因此可以设置节点访问次数变量来解决这个问题。
				while(p != NULL) {
					pushStack(s, *p);
					p = p->left;
				}
			}

		} // end of while
	}
}

// /***后序遍历的非递归实现***/  ？？？需理解
/*
void postOrder3_BiTree(BiTree root)  
{  
    PStack stack = Create_Stack();  //创建一个空栈    
    BinTree pCurrent;                      //当前结点   
    BinTree pre=NULL;                 //前一次访问的结点   
    Push_Stack(stack,Ptr);  
    while(!SIs_Empty(stack))  
    {  
        pCurrent = Get_Item_Stack(stack);   
        if((pCurrent->L_Child==NULL&&pCurrent->R_Child==NULL)||  
           (pre!=NULL&&(pre==pCurrent->L_Child||pre==pCurrent->R_Child)))  
        {  
            printf("%c ", pCurrent->data);    
            Pop_Stack(stack);  
            pre=pCurrent;   
        }  
        else  
        {  
            if(pCurrent->R_Child!=NULL)  
                Push_Stack(stack,pCurrent->R_Child);  
            if(pCurrent->L_Child!=NULL)      
                Push_Stack(stack,pCurrent->L_Child);  
        }  
    }      
}  
	*/


// 层序遍历二叉树
// 要点是队列的元素存储的是指向树节点的指针，这在后来判断二叉树为完全二叉树时也有用
void levelOrder_BiTree(BiTree root)
{
	if(root == NULL) {
		printf("*\t\t");
	} else {
		myQueue * pQueue = initQueue();
		BiNode * p = root;
		enQueue(pQueue, p);
		while(!isEmptyQueue(pQueue)) {
			QueueNodeElemType temp = deQueue(pQueue);
			if(!temp) printf("*\t\t");
			else {
				printf("%c\t\t", temp->value);
				enQueue(pQueue, temp->left);
				enQueue(pQueue, temp->right);
			}				
		} // end for while		
	} // end for else
	printf("\n\n");
}

