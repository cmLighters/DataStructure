#ifndef __BI_TREE_H__
#define __BI_TREE_H__

typedef char ElemType;	//BinaryTreeNode ElemType

typedef struct BinaryTreeNode {
	ElemType value;
	struct BinaryTreeNode * left;
	struct BinaryTreeNode * right;
} BiNode, * BiTree;

int isEmptyBiTree(BiTree root);

BiTree initBiTree(BiTree root);

BiNode * createBiNode(ElemType value);

BiTree createBiTree(BiTree root, ElemType arr[], int n);

void preOrder1_BiTree(BiTree root);

void preOrder2_BiTree(BiTree root);

void inOrder1_BiTree(BiTree root);

void inOrder2_BiTree(BiTree root);

void postOrder1_BiTree(BiTree root);

void postOrder2_BiTree(BiTree root);

void levelOrder_BiTree(BiTree root);

#endif /* __BTREE_H__ */
