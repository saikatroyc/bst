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
    return 0;
}
