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


void printRecursive(pnode root, int path[], int len) {
    int i = 0;
    if (root->left == NULL && root->right == NULL) {
         // leaf node
        for (i = 0; i < len; i++) {
            printf("%d--", path[i]);
        }
        printf("%d\n", root->data);
    } else {
        path[len++] = root->data;
        if (root->left) printRecursive(root->left, path, len);
        if (root->right) printRecursive(root->right, path, len); 
    }
}

void printPaths(pnode root) {
    int path[1000];
    if (!root) return;
    printf("paths in the tree\n");
    printRecursive(root, path, 0);
}

bool checkSumRecursive(pnode root, int sum, int currSum) {
    if (!root->left && !root->right) {
        if (currSum + root->data == sum) {
            return true;
        } else return false;
    } else {
        currSum += root->data;
        if (root->left
                && checkSumRecursive(root->left, sum, currSum))
            return true;
        else if (root->right
                 && checkSumRecursive(root->right, sum, currSum))
            return true;
        else return false;
    }
}

bool hasPathSum(pnode root, int sum) {
    if (!root) return true;
    else {
        int currSum = 0;
        return checkSumRecursive(root, sum, currSum);
    }
}

void mirrorTree(pnode *root) {
    pnode temp;
    if (*root == NULL) return;
    if ((*root)->left == NULL && (*root)->right == NULL) return;

    mirrorTree(&((*root)->left));
    mirrorTree(&((*root)->right));
    temp = (*root)->left;
    (*root)->left = (*root)->right;
    (*root)->right= temp;
    return;
}
