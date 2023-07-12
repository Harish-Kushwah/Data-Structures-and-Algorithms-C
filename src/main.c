#include "tree.h"

int main()
{
    //Create the binary search tree
    Node *root =createBST();

    //inorder traversal of BST
    printf("\nInorder traversal : ");
    inorder(root);

    //preorder traversal of BST
    printf("\npreorder traversal : ");
    preorder(root);
    
    //postorder traversal of BST
    printf("\npostorder traversal : ");
    postorder(root);


    //Insert the 10 into BST
    insertNode(root,10);

    //After inserting printf the inorder traversal
    printf("\nInorder traversal : ");
    inorder(root);

    //Find the numer in BST    
    printf("\nEnter number to search in BST : ");
    int num;
    scanf("%d" ,&num);
    if(search(root,num)==1){
        printf("Number is found");
    }
    else{
        printf("Number is not found");
    }

    //prints the total leaf node from BST
    printf("\nTotal leaf nodes are : %d " ,countTotalLeafNode(root));

    //prints the total non leaf node from BST
    printf("\nTotal Non leaf nodes are : %d " ,countTotalNonLeafNode(root));
     
}