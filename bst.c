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
    printf("mirror tree paths:");
    mirrorTree(&head); 
    printPaths(head);
    printf("restore original tree");
    mirrorTree(&head); 
    printPaths(head);
    return 0;
}
