#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *left, *right;
} Node;

Node *createBST()
{
    int n;
    printf("Enter how many nodes wants to create :");
    scanf("%d", &n);
    Node *root = NULL;
    Node *newnode = NULL;
    Node *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        newnode = (Node *)malloc(sizeof(Node));
        printf("Enter value in node :");
        scanf("%d", &newnode->val);
        newnode->left = newnode->right = NULL;

        if (root == NULL)
        {
            root = temp = newnode;
        }
        else
        {
            temp = root;
            while (1)
            {
                if (newnode->val < temp->val)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = newnode;
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                if (newnode->val > temp->val)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = newnode;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }
    return root;
}
Node *createNode(int val)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->val = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}
Node *insertNode(Node *root, int val)
{
    if (root == NULL)
    {
        return createNode(val);
    }
    else
    {
        if (val < root->val)
            root->left = insertNode(root->left, val);
        else
            root->right = insertNode(root->right, val);
    }
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int countTotalLeafNode(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countTotalLeafNode(root->left) + countTotalLeafNode(root->right);
}
int countTotalNonLeafNode(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;
    return 1 + countTotalNonLeafNode(root->left) + countTotalNonLeafNode(root->right);
}

int search(Node *root, int val)
{
    if (root == NULL)
        return 0;
        
    if (root->val == val)
        return 1;
    else if (val < root->val)
        search(root->left, val);
    else
        search(root->right, val);
}