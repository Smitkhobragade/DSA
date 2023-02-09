#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node * left;
	struct Node * right;
}Node;

Node * createNode(){
	Node * new = (Node *)malloc(sizeof(Node));
	if(new!=NULL)
		return new;
	else
		return NULL;
}

Node * search1(Node * root,int key){
	if(root == NULL)
		return root;
	else if(root->data < key)
		return search1(root->right,key);
	else if(root->data > key)
		return search1(root->left,key);
	else if(root->data == key){
		printf("THE DATA IS PRESENT\n");
		return (root);
	}
}

Node * search(Node * root,int key){
	Node * temp = search1(root,key);
	if(temp == NULL)
		printf("THE DATA IS NOT PRESENT\n");
	return temp;
}

Node * deleteNode(Node * root,int key){
	if(root == NULL)
		return NULL;
	else if(key < (root->data))
		root -> left = deleteNode(root->left,key);
	else if(key > (root->data))
		root -> right = deleteNode(root->right,key);
	else{
		if(root->left == NULL && root->right == NULL){
			free(root);
			return NULL;
		}else if(root->left == NULL){
			Node * temp = root->right;
			free(root);
			return (temp);
		}else if(root->right == NULL){
			Node * temp = root->left;
			free(root);
			return (temp);
		}else{
			Node * temp = root->right;
			while(temp->left != NULL)
				temp = temp -> left;
			
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
	}
	return (root);
}

Node * insertNode(Node * root,int key){
	if(root == NULL){
		root = createNode();
		if(root == NULL){
			printf("ALLOCATION FAILED\n");
			return (root);
		}else{
			root->data = key;
			root->left = NULL;
			root->right = NULL;
			return (root);
		}
	}else{
		if(key < (root -> data))
			root -> left = insertNode(root->left,key);
		else if(key > (root -> data))
			root -> right = insertNode(root->right,key);
	}
	return (root);
}

void inorder(Node * root){
	if(root == NULL)
		return;
		
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
void preorder(Node * root){
	if(root == NULL)
		return;
		
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(Node * root){
	if(root == NULL)
		return;
		
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);
}
void print_inorder(Node * root){
	printf("---------- INORDER SEQUENCE ----------\n");
	inorder(root);
	printf("\n");
}
void print_preorder(Node * root){
	printf("---------- PREORDER SEQUENCE ----------\n");
	preorder(root);
	printf("\n");
}
void print_postorder(Node * root){
	printf("---------- POSTORDER SEQUENCE ----------\n");
	postorder(root);
	printf("\n");
}
void print_level(Node * root , int level){
	if(root == NULL)
		return ;
	else if(level == 1)
		printf("%d\t",root -> data);
	else if(level > 1){
		print_level(root->left,level-1);
		print_level(root->right,level-1);
	}
}
int countNodes(Node * root){
	if(root == NULL)
		return 0;
	else
		return countNodes(root->left) + countNodes(root->right) + 1;
}
int heightTree(Node * root){
	if(root == NULL)
		return 0;
	else{
		int lh = heightTree(root->left);
		int rh = heightTree(root->right);
		
		if(lh<rh)
			return (rh+1);
		else
			return (lh+1);
	}
}
void print_Height(Node * root){
	printf("The Height of the Tree is : %d\n",heightTree(root));
}
void print_Nodes(Node * root){
	printf("The No. of Nodes in the Tree is : %d\n",countNodes(root));
}
void print_levelOrder(Node * root){
	printf("---------- LEVEL-ORDER SEQUENCE ----------\n");
	int h = heightTree(root);
	for(int i = 1; i <= h; i++)
		print_level(root,i);
	printf("\n");
}
void legend(){
	printf("Enter 1 to Insert \n");
	printf("Enter 2 to Delete \n");
	printf("Enter 3 to Search \n");
	printf("Enter 4 to display No. of Nodes\n");
	printf("Enter 5 to display Height of Tree\n");
	printf("Enter 6 to Display Inorder\n");
	printf("Enter 7 to Display Preorder\n");
	printf("Enter 8 to Display Postorder\n");
	printf("Enter 9 to Display Level-Order\n");
	printf("Enter 10 to End program\n");
	printf("Enter Any Number to print legend\n");
}
void menu(Node * root){
	int c;
	while(1){
		printf("ENTER YOUR CHOICE :");
		scanf("%d",&c);
		int key;
		switch(c){
			case 1:
				printf("Enter Data : ");
				scanf("%d",&key);
				root = insertNode(root,key);
				break;
			case 2:
				printf("Enter Data : ");
				scanf("%d",&key);
				root = deleteNode(root,key);
				break;
			case 3:
				printf("Enter Data : ");
				scanf("%d",&key);
				search(root,key);
				break;
			case 4:
				print_Nodes(root);
				break;
			case 5:
				print_Height(root);
				break;
			case 6:
				print_inorder(root);
				break;
			case 7:
				print_preorder(root);
				break;
			case 8:
				print_postorder(root);
				break;
			case 9:
				print_levelOrder(root);
				break;
			case 10:
				return ;
			default:
				legend();
				
		}
	}
}
int main(){
	Node * root;
	legend();
	menu(root);
	/*root = insertNode(root,5);
	root = insertNode(root,3);
	root = insertNode(root,8);
	root = insertNode(root,10);
	root = insertNode(root,4);
	root = insertNode(root,12);
	root = insertNode(root,1);
	root = insertNode(root,9);
	root = insertNode(root,11);
	print_Nodes(root);
	print_Height(root);
	print_levelOrder(root);*/
	/*print_level(root , 1);
	print_level(root , 2);
	print_level(root , 3);
	print_level(root , 4);*/
	/*print_inorder(root);
	print_preorder(root);
	print_postorder(root);*/
	/*root = deleteNode(root,3);
	print_inorder(root);
	search(root,800);
	search(root,5);*/
	return 0;
}
