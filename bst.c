#include "bst.h"

int main(){
    pnode head = NULL;
    insert(&head, 10); 
    insert(&head, 8); 
    insert(&head, 7); 
    insert(&head, 6); 
    insert(&head, 20); 
    insert(&head, 13); 
    insert(&head, 9); 
    insert(&head, 21); 
    printTreeInorder(head);
    printf("size of tree = %d\n", size(head));
    printf ("depth = %d\n", maxDepth(head)); 
    printf ("minvalue = %d\n", minValue(head));
    printPaths(head); 
    printf("%s", hasPathSum(head, 27) ? "true\n" : "false\n"); 
    printf("%s", hasPathSum(head, 43) ? "true\n" : "false\n"); 
    printf("%s", hasPathSum(head, 55) ? "true\n" : "false\n");
    printf("mirror tree paths:\n");
    mirrorTree(&head); 
    printPaths(head);
    printf("restore original tree\n");
    mirrorTree(&head); 
    printPaths(head);
#if 0
    printf("double tree\n");
    doubleTree(&head); 
    printPaths(head);
#endif
    printf("build a new tree\n");
    pnode head1 = NULL;
    insert(&head1, 10); 
    insert(&head1, 8); 
    insert(&head1, 7); 
    insert(&head1, 6); 
    insert(&head1, 20); 
    insert(&head1, 13); 
    insert(&head1, 9); 
    insert(&head1, 21); 
    printPaths(head);

    printf("comapre trees:");
    printf("%s\n", isSameTree(head, head1) ? "true" : "false");
    printf("%s\n", isBST(head) ? "true" : "false");
    printf("%s\n", isBST(head1) ? "true" : "false");
    mirrorTree(&head1); 
    printf("%s\n", isBST(head1) ? "true" : "false");
    return 0;
}
