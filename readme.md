# Graph
[![C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

This branch contains the implementation of a Graph in C. A Graph is a Non linear data structure where elements are stored as nodes, each containing a value and a pointer to the left node and right node. It allows for efficient searching value.


## Graph
A Graph is a Non linear data structure consisting of a collection of nodes, where each node contains a value and a pointer to the left node and right node
```c
//Node structure of Graph 
typedef struct Graph
{
    int val;
    struct Node *left ,*right;
}Node;
```

### Functionality

The following table provides an overview of the functions available in the Graph implementation:

| Function          | Description                                       |Link|
|-------------------|---------------------------------------------------|-----|
| `createNode`          | Create the node with given value Tree. |[click here](#createnode) |
| `createBST`     | Create the Graph           |[click here](#createbst)|
|`inorder`|Inorder Traversal of Graph.|[click here](#inorder)|
|`preorder`|Preorder Traversal of Graph.|[click here](#preorder)|
|`postorder`|Postorder Traversal of Graph.|[click here](#postorder)|
| `insertNode` | Inserts a new node  in to the Graph. |[click here](#insertnode)|
| `CountTotalLeafNodes` | Count the total number of leaf nodes from Graph.     |[click here](#counttotalleafnode)|
| `CountTotalNonLeafNodes` | Count the total number of Non leaf nodes from Graph.     |[click here](#counttotalnonleafnode)
| `search`          | Searches for a given value in the Graph.     |[click here](#search)|


| File         | Description                                       |Link|
|-------------------|---------------------------------------------------|-----|
| `tree.h`          | Contain all the functions  |[click here](src/tree.h) |
| `main.c`          | Usage of all function  |[click here](src/main.c) |

---
<a name="createnode"></a>
#### createNode()

```c
Node *createNode(int val)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->val = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}
```
---
<a name="createbst"></a>
#### createBST()

```c

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
```
---

<a name="inorder"></a>
#### inorder()

```c
void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}
```
---
<a name="preorder"></a>
#### preorder()

```c
void preorder(Node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}
```
---
<a name="postorder"></a>
#### postorder()

```c
void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}
```
---
<a name ="insertnode"></a>
### insertNode()

```c
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
```
---
<a name ="counttotalleafnode"></a>
#### countTotalLeafNode()

```c
int countTotalLeafNode(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countTotalLeafNode(root->left) + countTotalLeafNode(root->right);
}
```
---
<a name="counttotalnonleafnode"></a>
#### countTotalNonLeafNode()

```c
int countTotalNonLeafNode(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;
    return 1 + countTotalNonLeafNode(root->left) + countTotalNonLeafNode(root->right);
}
```

---
<a name = "search"></a>
### search()

```c
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
```

---

## Contributing

Contributions, bug reports, and suggestions are welcome! If you encounter any issues, have ideas for improvement, or would like to contribute to this project, please follow the guidelines in [CONTRIBUTE.md](https://github.com/Harish-Kushwah/Data-Structures-and-Algorithms-C/blob/Tree/contribute.md).

## License

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Contact
For any questions or feedback, feel free to reach out to us at harishkushwah54321@gmail.com

