#include<stdio.h>
#include<stdlib.h>
#define bool int
#define true 1
#define false 0
typedef struct a {
	int data;
	struct a  *left;
	struct a  *right;
} node, *pnode;


void insert(pnode *, int);
void printTreeInorder(pnode); 
int size(pnode );
int maxDepth(pnode ); 
int minValue(pnode );
void printPaths(pnode ); 
bool hasPathSum(pnode , int ); 
void mirrorTree(pnode *); 
void doubleTree(pnode *root); 
bool isSameTree(pnode , pnode ); 
bool isBST(pnode root); 
