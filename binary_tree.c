//source code binary tree in C
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>

//typedef NULL null;
typedef unsigned char BYTE;

typedef struct TreeNode {
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
	//struct TreeNode *parent;
} Tnode;

Tnode * makeTreeNode(int d) {  //d = new node's data; this method creates a new tree node, this node we don't know its parent and its children
	Tnode *newNode = NULL;
	newNode = (Tnode *)malloc(sizeof(Tnode));
	if(newNode == NULL) {
		printf("Out of memory\n");
		exit(1);
	} else {
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->data = d;
	}
	
	return newNode;
}

Tnode * randomInsert(Tnode *tree, int d) {  //create new node and we know its children, and its parent. Note that Tnode *tree means tree is the root. Note that this method only insert new node into the most left child or the most right child: chi chen vao vi tri con trai nhat hoac vi tri con phai nhat ma thoi!
	Tnode *newNode, *p;
	newNode = makeTreeNode(d);
	
	if ( tree == NULL ) return newNode;
	if ( rand()%2 ==0 ){
		p=tree;
		while (p->left !=NULL) p=p->left;
		
		p->left=newNode;
		printf("Node %d is left child of %d \n",d,(*p).data); 
	}
	else {
		p=tree;
		while (p->right !=NULL) p=p->right;
		p->right=newNode;
		printf("Node %d is right child of %d \n",d,(*p).data);
	}
	return tree;
}

Tnode *insertIntoLeftChild(Tnode *tree, int d) {
	
}

Tnode *insertIntoRightChild(Tnode *tree, int d) {
	
}

int countNodes(Tnode *tree) {
	if(tree == NULL) return 0;
	else {
		int leftNodes = countNodes(tree->left);
		int rightNodes = countNodes(tree->right);
		return 1+leftNodes+rightNodes;
	}
}

int countDepth(Tnode *tree) {
	if(tree == NULL) return 0;
	else {
		int leftDepths = countDepth(tree->left);
		int rightDepths = countDepth(tree->right);
		return 1+(leftDepths > rightDepths ? leftDepths : rightDepths);
	} 
}

void freeTree(Tnode *tree) {
	if(tree==NULL) return;
	freeTree(tree->left);
	freeTree(tree->right);
	freeTree(tree);  //tree is also a node
	return;
}

void printPreOrder(Tnode *tree) {  //Note that "Tnode *tree" means tree is the root
	if(tree == NULL) return;
	printf("%d ", tree->data);
	printPreOrder(tree->left);
	printPreOrder(tree->right);
}

void printInOrder(Tnode *tree) {
	if(tree == NULL) return;
	printInOrder(tree->left);
	printf("%d ", tree->data);
	printInOrder(tree->right);
}

void printPostOrder(Tnode *tree) {
	if(tree == NULL) return;
	printPostOrder(tree->left);
	printPostOrder(tree->right);
	printf("%d ", tree->data);
}

int main() {
	Tnode * myTree = NULL;
	int i;
	for(i=0; i<20; i++) {
		myTree = randomInsert(myTree, i);
	}
	
	printf("\nPrint my tree in preorder:\n");
	printPreOrder(myTree);
	printf("\nPrint my tree in inorder:\n");
	printInOrder(myTree);
	printf("\nPrint my tree in postorder:\n");
	printPostOrder(myTree);
	
	printf("\n\nthe depth of tree is %d\n",countDepth(myTree));
	printf("the amount of nodes of tree is %d\n",countNodes(myTree));
	
}
