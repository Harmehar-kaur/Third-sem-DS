#include <stdlib.h>
#include <stdio.h>
#define COUNT 10
struct bstnode
{
    int data;
    struct bstnode *left;
    struct bstnode *right;
};

struct bstnode *newNode(int data)
{
    struct bstnode *temp = (struct bstnode *)malloc(sizeof(struct bstnode));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct bstnode *insert(struct bstnode *root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

struct bstnode *findmin(struct bstnode *root)
{
    if (root == NULL)
        return NULL;
    else
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }
}

struct bstnode *Delete(struct bstnode *root, int del_data)
{
    if (root == NULL)
        return root;
    else if (del_data < root->data)
    {
        root->left = Delete(root->left, del_data);
    }
    else if (del_data > root->data)
    {
        root->right = Delete(root->right, del_data);
    }
    else
    {
        // case 1: no child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // case 2: only one child
        else if (root->left == NULL)
        {
            struct bstnode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct bstnode *temp = root;
            root = root->left;
            free(temp);
        }
        // case 3: 2 children
        else
        {
            struct bstnode *temp = findmin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void inorder(struct bstnode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf(" %d ", root->data);
    inorder(root->right);
}

void print(struct bstnode *root, int space)
{
    if (root == NULL)
        return;
    space = space + COUNT;
    print(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    print(root->left, space);
}

int main()
{
    struct bstnode *root = NULL;
    int ch;
    int num;
    int val;
    system("cls");
    while (1)
    {
        printf("\n 1. Create a binary Search Tree ");
        printf("\n 2. Deletion in bst");
        printf("\n 3. Inorder Traversal ");
        printf("\n 4. Tree display ");
        printf("\n 5. Exit ");
        scanf("\n %d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter no. of elements: ");
            scanf("%d", &num);
            for (int i = 0; i < num; i++)
            {
                printf("\n Enter the value: ");
                scanf("%d", &val);
                root = insert(root, val);
            }
            printf("\n The tree has been created.\n");
            print(root, 0.5);
            
            break;

        case 2:
            printf("\n Enter value to be deletion :");
            scanf("%d", &val);
            Delete(root, val);
            printf("\n");
            inorder(root);
            break;

        case 3:
            printf("\n Inorder Traversal : ");
            inorder(root);
            break;

        case 4:
            printf("\n4) Tree Display\n");
            print(root, 0.5);
            break;

        case 5:
            printf("\n Harmehar Kaur (CSE-1 04613202720)");
            exit(0);

        default:
            printf(" wrong choice ");
        }
    }
}
