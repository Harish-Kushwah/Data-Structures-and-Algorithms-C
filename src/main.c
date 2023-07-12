#include "tree.h"

int main()
{
    Node *root =createBST();
    inorder(root);
    printf("\nTotal leaf nodes are : %d " ,countTotalLeafNode(root));
    printf("\nTotal Non leaf nodes are : %d " ,countTotalNonLeafNode(root));
     
}