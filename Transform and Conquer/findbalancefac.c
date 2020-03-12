#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}Node;

Node *root;

Node *create(Node *root,int x)
{
	if(root==NULL)
	{
		root=(Node*)malloc(sizeof(Node));
		root->data=x;
		root->left=root->right=NULL;
	}
	else if(x>root->data)
			root->right=create(root->right,x);
	else if(x<root->data)
			root->left=create(root->left,x);
	else
	{
		printf("Duplicates found");
		exit(0);
	}
	return root;						
} 

int max(int a, int b)
{
    return (a>b)?a:b;
}

int getHeight(Node* t)
{
    if(t == NULL)
        return 0;
    return 1 + max(getHeight(t->left), getHeight(t->right));
}

int balance(Node *root)
{
	return (getHeight(root->left)-getHeight(root->right));
}


void inorder(Node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("%d\t%d\n",ptr->data,balance(ptr));
		inorder(ptr->right);
	}
}

void postorder(Node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d\t%d\n",ptr->data,balance(ptr));
	}	
}

void preorder(Node *ptr)
{
	if(ptr!=NULL)
	{
		printf("%d\t%d\n",ptr->data,balance(ptr));
		preorder(ptr->left);
		preorder(ptr->right);
		
	}
}	



int main ()
{
	int choice,x;
	root=NULL;
	do
	{
		printf("1.Insert\n");
		printf("2.All Traversals\n");
		printf("Choice: ");
		scanf(" %d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the element : ");
				scanf("%d",&x);
				root=create(root,x);
				break;
			case 2:
				printf("Inorder Traversal:\n");
				inorder(root);
				printf("Preorder Traversal:\n");
				preorder(root);
				printf("Postorder Traversal:\n");
				postorder(root);
				break;
		}
	}while(choice==1||choice==2);
	return 0;
}	
