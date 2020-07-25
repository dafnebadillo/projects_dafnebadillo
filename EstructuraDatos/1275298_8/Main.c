//Andrea Munoz Gris A01733058
// Dafne Linette Badillo Campuzano A01275298

#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *tree;
	struct node *right;
	struct node *left;
	int data;
};

struct node *create_node(struct node *tree, int value){
	if(tree==NULL){
		tree = (struct node *)malloc(sizeof(struct node));
		tree -> left = tree ->right = NULL;
		tree -> data = value;
		return tree;
	}else{
		if(value < tree->data)
			tree ->left = create_node(tree->left,value);
	else if(value > tree->data)
		tree->right=create_node(tree->right,value);
	else
		printf("ERROR\n");
	return(tree);
	}
};

void inOrderTraversal(struct node *tree){
	if(tree != NULL){
		inOrderTraversal(tree->left);
		printf("%d ", tree->data); 
		inOrderTraversal(tree->right);
	}
}

void preOrderTraversal(struct node *tree){
	if(tree != NULL){
		printf("%d ", tree->data);
		preOrderTraversal(tree->left);
		preOrderTraversal(tree->right);
	}
}

void postOrderTraversal(struct node *tree){
	if(tree != NULL){
		postOrderTraversal(tree->left);
		postOrderTraversal(tree->right);
		printf("%d ", tree->data);
	}
}

int byLevelTraversal(struct node* tree, int line) { 
	while (tree == NULL){
		return(tree);
	}
	if (line == 1) 
        printf("%d ", tree->data); 
    else if (line > 1){ 
        byLevelTraversal(tree->left, line-1); 
        byLevelTraversal(tree->right, line-1); 
    }
} 

void order(struct node* tree) { 
    int var = root(tree); 
    for (int i=1; i<=var; i++) 
        byLevelTraversal(tree, i); 
} 

int root(struct node* tree){ 
    if (tree==NULL) 
        return 0; 
    else{ 
        int leftL, rightL;
		leftL = root(tree->left); 
        rightL = root(tree->right); 
        if (leftL > rightL){
			return(leftL+1); 
		}  
        else 
		return(rightL+1); 
    } 
} 

int main(int argc, char const *argv[])
{	
	int value;
	int values=0;
	struct node *tree = NULL;
	scanf("%i", &values);
	for (int i = 0; i < values; ++i){
		scanf("%d", &value);
		tree = create_node(tree,value);
	}
	printf("\nInOrder: "); 
	inOrderTraversal(tree);
    printf("\nPreOrder: "); 
	preOrderTraversal(tree);
	printf("\nPostOrder: "); 
	postOrderTraversal(tree);
	printf("\nby-Level: ");
	order(tree);
	return 0;
}










