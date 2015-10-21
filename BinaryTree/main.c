#include <stdio.h>

#include "bi_tree.h"
#include "bi_tree_problem.h"

int main() 
{
	BiNode * p = createBiNode(14);
	BiTree pTree = NULL;
	BiTree pTree1 = NULL;
	ElemType arr[] = "abde**f**g**ch**i**";		// 主意这样初始化，数组最后一个元素是'\0'
	//ElemType arr1[] = "abde**f**gj***ch**i**";		// 主意这样初始化，数组最后一个元素是'\0'
	ElemType arr1[] = "abde***gj***ch**i**";
	pTree = createBiTree(pTree, arr, sizeof(arr)/sizeof(arr[0])-1);
	pTree1 = createBiTree(pTree1, arr1, sizeof(arr1)/sizeof(arr1[0])-1);
	printf("%d\n", maxDepth_BiTree(pTree));
	/*
	while(pTree->left!=NULL) {
		printf("%c\t", pTree->value);
		pTree = pTree->left;
	}
	printf("\n%c\n", pTree->value);
	if(pTree->right == NULL) printf("\nhaha\n");
*/
	/*postOrder1_BiTree(pTree);*/
	/*preOrder2_BiTree(pTree);*/
	/*preOrder2_BiTree(pTree1);*/
	/*postOrder2_BiTree(pTree);*/
	levelOrder_BiTree(pTree);
	levelOrder_BiTree(pTree1);
	/*printf("num of biTree node: %d\n", nodeNum_BiTree(pTree));*/
	/*printf("max depth of biTree node: %d\n", maxDepth_BiTree(pTree));*/
	/*p = doubleList_BiSearchTree(pTree);*/
	/*while(p) printf("%c\t\t", p->value);*/
	/*printf("levelK BiTree node num: %d\n", levelK_nodeNum_BiTree(pTree, 4));*/
	/*printf("levelK BiTree node num: %d\n", leafNum_BiTree(pTree));*/
	/*printf("pTree is equal to pTree1: %d\n", isEqual_BiTree(pTree, pTree1));*/
/*
	BiNode *q, *temp;
	p = pTree->left->left->left;
	q = pTree->right->right;
	temp = lowestCommonAncestor_BiTree(pTree, p, q);
	printf("node is in tree? %c\n", temp->value);
*/
	int maxLeft, maxRight;
//	printf("树中节点最大距离： %d\n", maxDistance_BiTree(pTree, &maxLeft, &maxRight));

	printf("Is complete tree? : %d\n", isComplete_BiTree(pTree1));

	return 0;
}
