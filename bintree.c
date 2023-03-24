#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
} Node;

Node *createTreeNode()
{
	Node *new = (Node *)malloc(sizeof(Node));
	if (new != NULL)
		return new;
	else
		return NULL;
}

void instree(Node **root, int key)
{
	*root = createTreeNode();
	(*root)->data = key;
	//(*root) -> left = createTreeNode();
	(*root)->left = NULL;
	//(*root) -> right = createTreeNode();
	(*root)->right = NULL;
}

void inorder(Node *root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	printf("%d\t", root->data);
	inorder(root->right);
}

void postorder(Node *root)
{
	if (root == NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	printf("%d\t", root->data);
}

void preorder(Node *root)
{
	if (root == NULL)
		return;

	printf("%d\t", root->data);
	preorder(root->left);
	preorder(root->right);
}

int main()
{
	Node *root = createTreeNode();
	instree(&root, 1);
	instree(&root->left, 2);
	instree(&root->right, 3);
	instree(&root->left->left, 4);
	instree(&root->left->right, 5);
	instree(&root->right->left, 6);
	instree(&root->right->right, 7);
	instree(&root->left->left->left, 8);
	instree(&root->left->left->right, 9);
	printf("\n---------------Inorder---------------\n");
	inorder(root);
	printf("\n---------------Preorder---------------\n");
	preorder(root);
	printf("\n---------------Postorder---------------\n");
	postorder(root);
	printf("\n\n");

	return 0;
}
