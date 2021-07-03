#include <stdio.h>
#include <stdlib.h>
//avl tree

struct node
{
    int key;
    int height;
    struct node *left;
    struct node *right;
};

int height(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct node *newnode(int key)
{
    struct node node = (struct node)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
};

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
};

struct node *leftRotate(struct node *x)
{
    struct node *y = x->left;
    struct node *t2 = y->right;
    y->left = x;
    x->right = t2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
};

int getBalance(struct node *n)
{
    int left_h, right_h;
    if (n == NULL)
    {
        return 0;
    }
    if (n->left == NULL)
    {
        left_h = 0;
    }
    else
    {
        left_h = height(n->left) + 1;
    }
    if (n->right == NULL)
    {
        right_h = 0;
    }
    else
    {
        right_h = height(n->right) + 1;
    }
    return (left_h - right_h);
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return (newnode(key));
    }
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
};

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("| %d |", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("| %d |", root->key);
        inOrder(root->right);
    }
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
};
//DELETE A PARTICULAR VALUE
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                root = NULL;
            }
            else
            {
                *root = *temp;
                free(temp);
            }
        }
        else
        {
            struct node *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (root == NULL)
    {
        return root;
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        root->right = leftRotate(root->right);
        return leftRotate(root);
    }
    return root;
};

int main()
{
    int choice = 0;
    int temp, n;
    struct node *root;
    while (choice != 5)
    {
        printf("----------MENU---------\n");
        printf("\t1.CREATE AVL\n");
        printf("\t2.INSERT VALUE\n");
        printf("\t3.DELETE \n");
        printf("\t4.DISPLAY\n");
        printf("\t5.EXIT\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            root = NULL;
            printf("Enter no. of Elements= ");
            scanf("%d", &n);
            printf("Enter the %d Elements ", n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d", &temp);
                root = insert(root, temp);
            }
            printf("AVL TREE SUCCESSFULLY CREATED\n");
            break;
        case 2:
            printf("\nENTER THE VALUE TO INSERT ");
            scanf("%d", &temp);
            root = insert(root, temp);
            printf("SUCCESSFULLY INSERTED\n");
            break;
        case 3:
            printf("\nENTER THE VALUE TO DELETE ");
            scanf("%d", &temp);
            root = deleteNode(root, temp);
            printf("\n ELEMENT DELETED SUCCESSFULLY\n");
            break;
        case 4:
            printf("\nPREORDER SEQUENCE ~ ");
            preOrder(root);
            printf("\nINORDER SEQUENCE ~ ");
            inOrder(root);
            break;
        case 5:
            break;
        }
    }
    return 0;
}