#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *CreateNode(int data)
{
    Node *newNode = new Node();
    if (!newNode)
    {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *InsertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = CreateNode(data);
        return root;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = CreateNode(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = CreateNode(data);
            return root;
        }
    }
}
void inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
void postOrder(Node *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}
void preOrder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}
bool searchNode(struct Node *node, int key)
{
    if (node == NULL)
        return false;

    if (node->data == key)
        return true;
    bool res1 = searchNode(node->left, key);

    if (res1)
        return true;

    bool res2 = searchNode(node->right, key);

    return res2;
}
void deletDeepest(struct Node *root,
                  struct Node *d_node)
{
    queue<struct Node *> q;
    q.push(root);
    struct Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == d_node)
        {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right)
        {
            if (temp->right == d_node)
            {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }

        if (temp->left)
        {
            if (temp->left == d_node)
            {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}
Node *deletion(struct Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
            return NULL;
        else
            return root;
    }

    queue<struct Node *> q;
    q.push(root);

    struct Node *temp;
    struct Node *key_node = NULL;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == key)
            key_node = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (key_node != NULL)
    {
        int x = temp->data;
        deletDeepest(root, temp);
        key_node->data = x;
    }
    return root;
}

int main()
{
    Node *root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);
    while (true)
    {
        cout << "Select from the following:\n";
        cout << "1. Insertion\n2. Inorder Traversal\n3. Preorder Traversal\n4. Postorder Traversal\n5. Level Order Traversal\n6. Search\n7. Deletion\n8. Exit\n";
        int x, n;
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "Enter value:";
            cin >> n;
            InsertNode(root, n);
            break;
        case 2:
            inOrder(root);
            cout << endl;
            break;
        case 3:
            preOrder(root);
            cout << endl;
            break;
        case 4:
            postOrder(root);
            cout << endl;
            break;
        case 5:
            levelOrder(root);
            cout << endl;
            break;
        case 6:
            cout << "Enter value to be searched:";
            cin >> n;
            if (searchNode(root, n))
            {
                cout << n << " is present in the binary tree\n";
            }
            else
            {
                cout << n << " is not present in the binary tree\n";
            }
            break;
        case 7:
            cout << "Enter value to be deleted:";
            cin >> n;
            root = deletion(root, n);
            break;
        case 8:
            exit(0);
        }
    }
    return 0;
}