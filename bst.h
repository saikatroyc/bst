#include<stdio.h>
#include<stdlib.h>
typedef struct a {
	int data;
	struct a  *left;
	struct a  *right;
} node, *pnode;

void insert(pnode *, int);
void printTreeInorder(pnode); 
int size(pnode );
int maxDepth(pnode ); 
