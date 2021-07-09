
#include <bits/stdc++.h>

// Binary tree BTNode
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

// depth of left tree
int findADepth(Node *node)
{
    int d = 0;
    while (node != NULL)
    {
        d++;
        node = node->left;
    }
    return d;
}
//Check for
//  All leaves are at same level
//  All internal nodes have two children
bool isPerfectRec(struct Node *root, int d, int level = 0)
{
    // an empty tree always perfect //base case
    if (root == NULL)
        return true;

    // For leaf node,  its depth must be same as
    // depth of all other leaves.
    if (root->left == NULL && root->right == NULL)
        return (d == level + 1);

    // If internal node and one child is empty
    if (root->left == NULL || root->right == NULL)
        return false;

    // Left and right subtrees must be perfect.
    return isPerfectRec(root->left, d, level + 1) &&
           isPerfectRec(root->right, d, level + 1);
}

bool isPerfect(Node *root)
{
    int d = findADepth(root);
    return isPerfectRec(root, d);
}

struct Node *newNode(int k)
{
    struct Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

int main()
{
    struct Node *root = NULL;
    root = newNode(110);
    root->left = newNode(120);
    root->right = newNode(130);
    root->left->left = newNode(140);
    root->left->right = newNode(150);
    root->right->left = newNode(160);
    root->right->right = newNode(170);

    if (isPerfect(root))
        printf("Given tree is Perfect\n");
    else
        printf("Given tree is not Perfect\n");

    return (0);
}
