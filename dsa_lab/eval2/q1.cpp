#include <bits/stdc++.h>

using namespace std;

// Binary tree BTNode
class BTNode
{
public:
    int data;
    BTNode *left;
    BTNode *right;

    // constructor
    BTNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int isBSTFunction(BTNode *BTNode, int min, int max)
{
    // base case if tree is empty
    if (BTNode == NULL)
        return 1;

    // check
    if (BTNode->data < min || BTNode->data > max)
        return 0;

    //recursive case
    return isBSTFunction(BTNode->left, min, BTNode->data - 1) &&
           isBSTFunction(BTNode->right, BTNode->data + 1, max);
}

int isBST(BTNode *BTNode)
{
    return (isBSTFunction(BTNode, INT_MIN, INT_MAX));
}

void printOutput(BTNode *root)
{
    if (isBST(root))
        cout
            << "Given tree is a BST" << endl;
    else
        cout << "Given Tree is not a BST" << endl;
}

int main()
{
    // Que no 1
    BTNode *root = new BTNode(10);
    root->left = new BTNode(6);
    root->right = new BTNode(13);
    root->left->left = new BTNode(1);
    root->left->right = new BTNode(8);
    root->right->left = new BTNode(11);
    root->right->right = new BTNode(14);
    cout << "que 1" << endl;
    printOutput(root);

    // Que no 2
    BTNode *root2 = new BTNode(10);
    root2->left = new BTNode(6);
    root2->right = new BTNode(13);
    root2->left->left = new BTNode(1);
    root2->left->right = new BTNode(12);
    root2->right->left = new BTNode(9);
    root2->right->right = new BTNode(14);
    cout << "que 2" << endl;
    printOutput(root2);
    return 0;
}