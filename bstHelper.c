#include "bst.h"

pnode createNode(int item);
int invalid = 0xdeadbeef;
void insert(pnode *root, int item) {
   pnode a  = createNode(item);
   if (*root == NULL) {
       *root = a;
   } else {
       if ((*root)->data < item) {
           insert(&((*root)->right), item);
       } else insert(&((*root)->left), item);
   }
}


void printTreeInorder(pnode root) { 
    if (root == NULL) return;
    
    printTreeInorder(root->left);
    printf("%d\n", root->data);
    printTreeInorder(root->right);
}
// helper functions private to bstHelpher.c
pnode createNode(int item) {
    pnode a = (pnode)malloc(sizeof(node));
    a->data = item;
    a->left = NULL;
    a->right = NULL;
    return a; 
}

int size(pnode root) {
    if (!root) return 0;
    else return(size(root->left) + 1 + size(root->right));
}

int maxDepth(pnode root) {
    if (!root) return 0;
    else {
        int ldepth = maxDepth(root->left);
        int rdepth = maxDepth(root->right);
        return ((ldepth > rdepth) ? ldepth + 1 : rdepth + 1);
    }
}

int minValue(pnode root) {
    if (!root) return invalid;
    pnode temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
   
    return temp->data;
}
