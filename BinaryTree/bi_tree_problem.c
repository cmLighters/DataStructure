/*
 * http://blog.csdn.net/luckyxiaoqiang/article/details/7518888#topic6
 * 9\ 13
 */
#include <stdio.h>
#include <stdlib.h>

#include "bi_tree.h"
#include "queue.h"

#define max(a,b) ((a)>(b)?(a):(b))

// 1. 求二叉树中的节点个数
int nodeNum_BiTree(BiTree root)
{
	static int num = 0;
	if(root) {
		++num;
		nodeNum_BiTree(root->left);
		nodeNum_BiTree(root->right);
	}
	return num;
}

// 2. 求二叉树的深度
int maxDepth_BiTree(BiTree root)
{
	static int leftMaxDepth = 0;
	static int rightMaxDepth = 0;
	if(root) {
		if(root->left) {
			leftMaxDepth++;
			maxDepth_BiTree(root->left);
		}
		if(root->right) {
			rightMaxDepth++;
			maxDepth_BiTree(root->right);
		}
	}
	return leftMaxDepth>rightMaxDepth ? leftMaxDepth : rightMaxDepth;
}

// 3. 前序遍历，中序遍历，后序遍历

// 4.分层遍历二叉树（按层次从上往下，从左往右）

// 5. 将二叉查找树变为有序的双向链表
BiNode * doubleList_BiSearchTree(BiTree root)
{
	if(!root) return NULL;
	else {
		BiNode *p = root->left;
		BiNode *q = root->right;
		if(p) {
			while(p->right != NULL)
				p = p->right;
			p->right = root;
			root->left = p;
			doubleList_BiSearchTree(p);
		}

		if(q) {
			while(q->left != NULL)
				q = q->left;
			q->left = root;
			root->right = q;
			doubleList_BiSearchTree(q);
		}

		if(p) return p;
		else return root;

	}

}
 
// 6. 求二叉树第K层的节点个数
int levelK_nodeNum_BiTree(BiTree root, int K)
{
	if(root && K>0) {
		if(K==1)
			return 1;
		else return levelK_nodeNum_BiTree(root->left, K-1) + levelK_nodeNum_BiTree(root->right, K-1);
	}
	else return 0;
}

// 7. 求二叉树中叶子节点的个数
int leafNum_BiTree(BiTree root)
{
	if(root) {
		return leafNum_BiTree(root->left) + leafNum_BiTree(root->right) + (root->left==NULL && root->right==NULL ? 1 : 0);
	} else return 0;
}

// 8. 判断两棵二叉树是否结构相同
int isEqual_BiTree(BiTree root1, BiTree root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	if(root1 && root2 ) 
		return (root1->value==root2->value ? 1 : 0) && isEqual_BiTree(root1->left, root2->left) && isEqual_BiTree(root1->right, root2->right);
	else return 0;
}

// 9. 判断二叉树是不是平衡二叉树	？？？
int isBanance_BiTree(BiTree root)
{
	if(!root)
		return 1;
	return 0;
}

// 10. 求二叉树的镜像
BiNode * mirror_BiTree(BiTree root)
{
	if(!root)
		return NULL;
	BiNode * temp = root->right;
	root->right = root->left;
	root->left = temp;
	mirror_BiTree(root->left);
	mirror_BiTree(root->right);
	return root;
}

// 11. 求二叉树中两个节点的最低公共祖先节点   //
// 11.1 判断节点是否在子树中，在返回1， 不在返回0
int isNodeInTree(BiTree root, BiNode * p)
{
	if(!root) return 0;
	if(root==p) return 1;
	else return isNodeInTree(root->left, p) || isNodeInTree(root->right, p);
}
	
BiNode * lowestCommonAncestor_BiTree(BiTree root, BiNode * p, BiNode * q)
{
	if(root&&p&&q) {
		if((isNodeInTree(root->left, p) && isNodeInTree(root->right, q)) || (isNodeInTree(root->left, q) && isNodeInTree(root->right, p)) ||(p==root && isNodeInTree(root, q)) || (q==root && isNodeInTree(root, p)))
			return root;
		else if(isNodeInTree(root->left, p) && isNodeInTree(root->left, q)) 
			return lowestCommonAncestor_BiTree(root->left, p ,q);
		else if(isNodeInTree(root->right, p) && isNodeInTree(root->right, q))
			return lowestCommonAncestor_BiTree(root->right, p ,q);
	} else return NULL;
}

// 12. 求二叉树中节点的最大距离
int maxDistance_BiTree(BiTree root, int * maxLeft, int * maxRight)
{
	//maxLeft 是左子树中节点距根节点的最远距离
	//maxRight是右子树中节点距根节点的最远距离
	if(!root) {
		*maxLeft = 0;
		*maxRight = 0;
		return 0;
	}
	int maxLDist, maxLL, maxLR, maxRDist, maxRL, maxRR;
	if(root->left) {
		maxLDist = maxDistance_BiTree(root->left, &maxLL, &maxLR);
		*maxLeft = max(maxLL, maxLR) + 1;
	} else {
		maxLDist = 0;
		*maxLeft = 0;
	}
	if(root->right) {
		maxRDist = maxDistance_BiTree(root->right, &maxRL, &maxRR);
		*maxRight = max(maxRL, maxRR) + 1;
	} else {
		maxRDist = 0;
		*maxRight = 0;
	}

	return max(max(maxLDist, maxRDist), *maxLeft+*maxRight);
}
	
// 13. 由前序遍历序列和中序遍历序列重建二叉树
BiTree createBiTree_PreMiddle_BiTree(BiTree root)
{
	return NULL;
}

// 14.判断二叉树是不是完全二叉树
int isComplete_BiTree(BiTree root)
{
	if(!root)
		return 0;
	myQueue * pQueue = initQueue();
	enQueue(pQueue, root);
	qNode * q = pQueue->front;
	BiNode * p = q->value;
	while(p) {
		enQueue(pQueue, p->left);
		enQueue(pQueue, p->right);
		q = q->next;
		p = q->value;
	}
	while(q) {
		if(q->value) return 0;
		q = q->next;
	}
	return 1;
}
