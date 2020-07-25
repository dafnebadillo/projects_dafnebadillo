/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/

#include<stdio.h> 
#include<stdlib.h> 

struct node{
	struct node *tree;
	struct node *right;
	struct node *left; //izq
	int data;
    int heightTree;
};

int heightTree(struct node *H) { 
    if (H== NULL) 
    return 0; 
    return H->heightTree; 
} 

int max (int a, int b){
    return a > b ? a: b;
}

struct node *create_node( int value){
    struct node *newN = malloc(sizeof(struct node));
    newN -> data = value;
    newN -> left = newN ->right = NULL;
    newN-> heightTree = 1;
    return newN;
}

struct node *rightRotation ( struct node *rotateY){
    struct node *temp = rotateY->left;
    rotateY->left = temp -> right;
    temp -> right = rotateY;

    rotateY->heightTree = max(heightTree(rotateY->left), heightTree(rotateY->right))+1;
    temp->heightTree = max(heightTree(temp->left),heightTree(temp->right))+1;

    rotateY = temp;
    return temp;
    
}
struct node *leftRotation ( struct node *rotateX){
    struct node *temp = (rotateX)->right;
    rotateX->right = temp -> left;
    temp -> left = rotateX;

    rotateX->heightTree = max(heightTree(rotateX->left), heightTree(rotateX->right))+1;
    temp->heightTree = max(heightTree(temp->left),heightTree(temp->right))+1;

    rotateX = temp;
    return temp;
}

int balance(struct node *B) 
{ 
    if (B == NULL) 
    return 0; 
    return heightTree(B->left) - heightTree(B->right); 
} 

struct node *insertTree(struct node* node, int value) 
{ 
    if (node == NULL) 
        return(create_node(value)); 
    if (value < node->data) 
        node->left  = insertTree(node->left, value); 
    else if (value > node->data) 
        node->right = insertTree(node->right, value); 
    else 
        return node; 
    node->heightTree = max(heightTree(node->left),heightTree(node->right))+1; 
    int var = balance(node); 
    if (var > 1 && value < node->left->data) 
        return rightRotation(node); 
    if (var < -1 && value > node->right->data) 
        return leftRotation(node); 
    if (var > 1 && value > node->left->data) { 
        node->left =  leftRotation(node->left); 
        return rightRotation(node); 
    } 
    if (var < -1 && value < node->right->data){ 
        node->right = rightRotation(node->right); 
        return leftRotation(node); 
    }return node; 
} 
  
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
void inOrderCon(struct node *tree){
	if(tree != NULL){
		inOrderCon(tree->right);
		printf("%d ", tree->data);   
		inOrderCon(tree->left);
	}
}

void preOrderCon(struct node *tree){
	if(tree != NULL){
		printf("%d ", tree->data);
		preOrderCon(tree->right);
		preOrderCon(tree->left);
	}
}

void postOrderCon(struct node *tree){
	if(tree != NULL){
		postOrderCon(tree->right);
		postOrderCon(tree->left);
		printf("%d ", tree->data);
		
	}
}

int byLevelTraversal(struct node *tree, int line){
    while (tree == NULL){
        return(tree);
    }
    if(line == 1)
        printf("%d ", tree->data);
    else if(line > 1){
        byLevelTraversal(tree ->left, line-1);
        byLevelTraversal(tree -> right, line-1);
    }
}

void order(struct node *tree){
    int var = root(tree);
    for (int i = 1; i <= var; ++i){
        byLevelTraversal(tree, i);
    }
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
		tree = insertTree(tree,value);
	}
	
    printf("\nPreOrden\n "); 
	preOrderTraversal(tree);
	printf("\nInOrden\n "); 
	inOrderTraversal(tree);
	printf("\nPostOrden\n "); 
	postOrderTraversal(tree);
	printf("\nPorNiveles\n "); 
	order(tree);
    printf("\n"); 
    printf("\nPreOrden Convexo R D I\n "); 
	preOrderCon(tree);
	printf("\nInOrden Convexo D R I\n "); 
	inOrderCon(tree);
	printf("\nPostOrden Convexo D I R\n "); 
	postOrderCon(tree);
    

	return 0;
}