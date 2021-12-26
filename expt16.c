//Create binary tree and perform in order, preorder ,postorder traversal using recurrsion
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#define COUNT 10
struct btnode
{
  int data;
  struct btnode *left;
  struct btnode *right;
};
struct btnode *newNode(int data)
{
  struct btnode *temp = (struct btnode *)malloc(sizeof(struct btnode));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}
struct btnode *insert(struct btnode *root, int data)
{
  if (root == NULL)
  {
    root = newNode(data);
  }
  else if (data < root->data)
  {
    root->left = insert(root->left, data);
  }
  else
  {
    root->right = insert(root->right, data);
  }
  return root;
}
void preorder(struct btnode *root)
{
  if (root == NULL)
    return;
  printf(" %d ", root->data);
  preorder(root->left);
  preorder(root->right);
}
void inorder(struct btnode *root)
{
  if (root == NULL)
    return;
  inorder(root->left);
  printf(" %d ", root->data);
  inorder(root->right);
}
void postorder(struct btnode *root)
{
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf(" %d ", root->data);
}
void print(struct btnode *root, int space)
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
  struct btnode *root = NULL;
  int ch;
  int num;
  int val;
  system ("cls");
  while (1)
  {
    printf("\n 1. Create ");
    printf("\n 2. inorder traversal ");
    printf("\n 3. preorder traversal ");
    printf("\n 4. postorder traversal ");
    printf("\n 5.Exit \n");
    scanf("\n %d", &ch);
    switch (ch)
    {
    case 1:
      printf("\n Enter no. of elements ");
      scanf("%d", &num);
      for (int i = 0; i < num; i++)
      {
        printf("\n Enter the value ");
        scanf("%d", &val);
        root = insert(root, val);
      }
      print(root, 0.5);
      break;
    case 2:
      printf("\n Inorder Traversal : ");
      inorder(root);
      break;
    case 3:
      printf("\n Preorder Traversal : ");
      preorder(root);
      break;
    case 4:
      printf("\n Postorder Traversal : ");
      postorder(root);
      break;
    case 5:
      printf("\n Harmehar Kaur (CSE-1 04613202720)\n");
      exit(0);
    default:
      printf(" wrong choice ");
    }
  }
}
