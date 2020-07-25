/*
Dafne Linette Badillo Campuzano A01275298
Andrea Muñoz Gris A01733058 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

FILE *input, *output;

struct queue *cola;
struct node {
    char var;
    char str1[1024],str2[1024], id[1024];
    struct node *left,*right;
    int height;
    int disable;
    struct node *next,*prev;
};

struct queue{
    struct node *element;
    struct queue *next,*prev;
};

struct stack{
    struct node *element;
    struct stack *next;
};

int height(struct node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b) {
    if (a > b){
        return a;
    } else {
        return b;
    }
}
struct node* newNode(char id[1024],char word[],char word1[],int var) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->id  , id);
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    node->var=var;
    strcpy(node->str1,word);
    strcpy(node->str2,word1);
    return(node);
}

struct node *rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}

struct node *leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}

int getBalance(struct node *other) {
    if (other == NULL)
        return 0;
    return height(other->left) - height(other->right);
}

struct node* insert(struct node* node,char id[1024],char word[],char word1[],int var){
    if (node == NULL)
    return(newNode(id,word,word1,var));
    if (id < node->id)
    node->left  = insert(node->left, id,word,word1,var);
    else if (id > node->id)
    node->right = insert(node->right, id,word,word1,var);
    else
    return node;

    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && id < node->left->id)
    return rightRotate(node);
    if (balance < -1 && id > node->right->id)
    return leftRotate(node);
    if (balance > 1 && id > node->left->id)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && id < node->right->id)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct queue *newqueue(struct node *newdata){
    struct queue *new;
    new = malloc(sizeof(struct queue));
    new->element = newdata;
    new->next=NULL;
    new->prev=NULL;
    return new;
}

void enQueue(struct queue **ptr,struct node *newdata){
    if (*ptr==NULL)
        *ptr = newqueue(newdata);
    else{
        struct queue *new,*tmpN;
        tmpN = *ptr;
        new = newqueue(newdata);
        new->next=*ptr;
        tmpN->prev = new;
        *ptr = new;
    }
}

struct node *deQueue(struct queue **ptr){
    if ((*ptr)->next==NULL){
        struct node *tmpN = (*ptr)->element;
        memset(*ptr,0,sizeof(struct queue **));
        free(*ptr);
        *ptr=NULL;
        return tmpN;
    }
    else{
        while((*ptr)->next->next)
            (*ptr)=(*ptr)->next;
        struct node *tmpN;
        tmpN = ((*ptr)->next->element);
        memset((*ptr)->next,0,sizeof(struct queue **));
        free((*ptr)->next);
        (*ptr)->next=NULL;
        return tmpN;
    }
}

void pushStack(struct node *newdata, struct stack ** ptr){
    struct stack *new;
    new = malloc(sizeof(struct stack));
    new -> element = newdata;
    new -> next = *ptr;
    *ptr = new;
}

struct node *popStack(struct stack ** ptr){ // delete at the beginning
    struct node *data_tmp;
    if (*ptr == NULL){
        printf("There is no node\n");
    } else {
        data_tmp = (*ptr)->element;
        struct stack *tmp;
        tmp = *ptr;
        *ptr = (*ptr)->next;
        memset(tmp, 0, sizeof(struct stack **));
        free(tmp);
        tmp=NULL;
        return data_tmp;
    }
    return data_tmp;
}


int sizeArray(char other[]){
    int i = 0;
    int tmpN = 0;
    while(other[i] != '\0'){
        tmpN++;
        i++;
    }
    return (tmpN-1);
}

struct node *findId(char a,struct node *ptr){
    if(a > *ptr->id){
        if (ptr->right != NULL){
            return findId(a,ptr->right);
        }
    } else if (a < *ptr->id){
        if (ptr->left != NULL){
            return findId(a,ptr->left);
        }
    }
    return ptr;
}
//compare the string
int CS(char a[],char b[]){
    int set;
    for (int i = 0; i < sizeArray(a); i++){
        if (a[i] == b[i]){
            set = 1;
        } else {
            set = 0;
        }
    }
    return set;
}
//This compare the substring
int CSS (char string[],char subs[]){
   char *ret;
   ret = strstr(string, subs);
   if (ret)
        return 1;
   else
        return 0;
}

struct node *findStr(char a[],struct node *ptr,int x) { 
    int set;
    struct node * tmp;
    if (x == 1){
        if (ptr != NULL){
            if (CS(a,ptr->str1) != 1){
                if (ptr->left != NULL){
                    if (CS(a,ptr->left->str1) != 1){
                        tmp = findStr(a,ptr->left,1);
                        if (tmp != NULL){
                            if(CS(a,tmp->str1) == 1)
                                return ptr->left;
                        }
                        else
                            return NULL;
                    }
                    else
                        return ptr->left;
                }
                if (ptr->right != NULL){
                    if (CS(a,ptr->right->str1) != 1){
                        tmp = findStr(a,ptr->right,1);
                        if (tmp != NULL){
                            if(CS(a,tmp->str1) == 1)
                                return ptr->right;
                        }
                        else
                            return NULL;
                    }
                    else
                        return ptr->right;
                }
            }
            else
                return ptr;
        }
        else
            return NULL;
        }
    else if (x == 2){
        if (ptr != NULL){
            if (CS(a,ptr->str2) != 1){
                if (ptr->left != NULL){
                    if (CS(a,ptr->left->str2) != 1){
                        tmp = findStr(a,ptr->left,2);
                        if (tmp != NULL){
                            if(CS(a,tmp->str2) == 1)
                                return ptr->left;
                        }
                        else
                            return NULL;
                    }
                    else
                        return ptr->left;
                }
                if (ptr->right != NULL){
                    if (CS(a,ptr->right->str2) != 1){
                        tmp = findStr(a,ptr->right,2);
                        if (tmp != NULL){
                            if(CS(a,tmp->str2) == 1)
                                return ptr->right;
                        }
                        else
                            return NULL;
                    }
                    else
                        return ptr->right;
                }
            }
            else
                return ptr;
        }
        else
            return NULL;
    }
    else
       printf("Please digit a valid option...\n");
}


void findStr1(char a[],struct node *ptr,struct queue **cola){
    if (ptr != NULL )
    {
        findStr1(a,ptr->left,cola);
        if (CS(ptr->str1,a)==1 || CS(ptr->str2,a)==1){
           enQueue(cola,ptr);
        }
        findStr1(a,ptr->right,cola);
    }
}

void findSS(char substring[],struct node *ptr,struct queue **cola){
    if (ptr != NULL )
    {
        findSS(substring,ptr->left,cola);
        if (CSS (ptr->str1,substring)==1 || CSS (ptr->str2,substring)==1){
           enQueue(cola,ptr);
        }
        findSS(substring,ptr->right,cola);
    }
}

void parseString(char string[]){
    int tam = strlen(string);
    for(int i=0;i<tam;i++){
        if(string[i]=='\n')
            string[i] = '\0';
    }
}

void printNode(struct node *ptr){
    if (ptr->var==1)
        printf("%s %s %s\n", ptr->id,ptr->str1,ptr->str2);
}

void preOrder(struct node *ptr){
    if (ptr == NULL)
        return;
    printNode(ptr);
    preOrder(ptr->left);
    preOrder(ptr->right);
}

void inOrder(struct node *ptr){
    if (ptr != NULL )
    {
        inOrder(ptr->left);
        printNode(ptr);
        inOrder(ptr->right);
    }
}

void deleteEntity(struct node *ptr){
    printf("\n");
    printf("DELETE AN ENTITY\n");
    printf("-----------------------------------------\n");
    struct node *tmp;
    //inOrder(ptr);
    char var1,op;
    int bol = 0;
    if (ptr == NULL){
        printf("There is no entity...\n\n");
        return;
    } else {
        printf("Digit the ID you want to delete: ");
        scanf("%i",&var1);
        tmp = findId(var1,ptr);
        while(bol == 0 && tmp){
            printf("Do you want to delete the %s entity? Digit Y/N: \n", tmp->id);
            scanf("%c",&op);
            scanf("%c",&op);
            if (op == 'Y' || op == 'y'){
                tmp->var = 0;
                printf("ENTITY ERASED\n");
                bol = 1;
            } 
            else if (op == 'N' || op == 'n'){
                bol = 1;
                printf("ENTITY NOT ERASED\n");   
            } 
            else
            printf("Please digit Y or N, try again.\n");
        }
    }
}


void recoverEntity(struct node *ptr){
    printf("\n");
    printf("RECOVER AN ENTITY\n");
    printf("-----------------------------------------\n");
    printf("\n");
    int var1;
    char op;
    int bol=0;
    if (ptr == NULL){
        printf("There is no entity...\n");
        return;
    } else {
        printf("Digit the ID you want to recover: ");
        scanf("%i",&var1);
        struct node *tmp = findId(var1,ptr);
        while(bol  == 0 && tmp){
            printf("Do you want to recover the %s entity? Digit Y/N:", tmp->id);
            scanf("%c",&op);
            scanf("%c",&op);
            if (op == 'Y' || op == 'y'){
                tmp->var = 1;
                printf("RECOVERED\n");
                bol=1;
            } else if (op == 'N' || op == 'n'){
                bol = 1;
                printf("NOT RECOVERED\n");
            } else {
                printf("Please digit Y or N, try again.\n");
            }
        }
    }
}

void editEntity(struct node *ptr){
    printf("\n");
    printf("EDIT AN ENTITY\n");
    printf("-----------------------------------------\n");
    printf("Current values: \n");
    struct node *tmp;
    char input;
    inOrder(ptr);
    printf(" \n");
    char tmpN[40],aux2[40];
    printf("Digit the ID you want to edit: ");
    scanf("%s",&input);
    //FILTRAR EDIT
    tmp=findId(input,ptr);
    if (tmp)
    {
        int opcion;
        printf("Wich string do you want to edit?\n %s",tmp->id);
        printf("\n");
        printf("1.String 1 \n");
        printf("2.String 2 \n");
        printf(" \n");
        printf("Please select an option: ");
        scanf("%i",&opcion);
        switch(opcion){
            case 1:
                    printf("Digit the new string: ");
                    fgets(tmpN,40,stdin);
                    fgets(tmpN,40,stdin);
                    parseString(tmpN);
                    strcpy(tmp->str1,tmpN);
                    break;
            case 2:
                    printf("Digit the new string: ");
                    fgets(aux2,40,stdin);
                    fgets(aux2,40,stdin);
                    parseString(aux2);
                    strcpy(tmp->str2,aux2);
                    break;

            default: 
                    printf("Please digit a valid option.  \n");
        }
    } 
}
// checa si existe
int noExists(struct node *ptr, int key){
    while(ptr){
        if(*ptr->id == key){
            if(ptr->disable == 0){
                return 0;
            }
            else{
                return -1;
            }
        }
        else{
            if(*ptr->id > key){
                ptr = ptr->left;
            }
            else{
                ptr = ptr->right;
            }
        }
    }
    return 1;
}

void newEntity(struct node **ptr){
    printf("\n");
    printf("INSERT A NEW ENTITY\n");
    printf("-----------------------------------------\n");
    struct node *root = NULL;
    char id[1024];
    char tmpN;
    char idC[1024];
    printf("Digit the ID: ");
    scanf("%s", idC);
    strcpy(id, idC);
    if(noExists(root, *id) == 1){
        printf("Digit the first string: ");
        char str1[1024],str2[1024];
        fgets(str1,1024,stdin);
        fgets(str1,1024,stdin);
        parseString(str1);
        printf("Digit the second string: ");
        fgets(str2,1024,stdin);
        parseString(str2);
        (*ptr)=insert(*ptr,id,str1,str2,1);
    }
    else{
        if(noExists(root, *id) == -1){
            recoverEntity(root);
        }
        else{
            printf("The ID already exists\n");
        }
    }
}

void printSearch(struct node* ptr, char a, int opcion) { 
struct node *tmp;
tmp = calloc(1, sizeof(struct node));
tmp->id;
	if(ptr == NULL){
		printf("\n");
	}
	else{
		if(a > *ptr->id && opcion == 2){
			printSearch(ptr->right, a, opcion); 
		}
		if(a < *ptr->id){
		printf("%s %s %s\n", ptr->id, ptr->str1, ptr->str2);
	    printSearch(ptr->left,a, opcion);   
	    printSearch(ptr->right, a, opcion);
		}
		if(*ptr->id == a|| *tmp->id == a){
			if(opcion == 2){
				printf("%s %s %s\n", ptr->id, ptr->str1, ptr->str2);
				*tmp->id = a;
				ptr = ptr->right;
				opcion = 0;
			}
			printf("%s %s %s\n", ptr->id, ptr->str1, ptr->str2);
   			printSearch(ptr->left, a, opcion);   
     		printSearch(ptr->right, a, opcion); 
		}	
	}
}
///
void search(struct node *ptr){
    int op,search, op1, op2;
    struct queue *cola=NULL;
    char a[1025],b[1025];
    printf("\n");
    printf("SEARCH\n");
    printf("-----------------------------------------\n");
    printf("SELECT AN OPTION \n");
    printf("1.Look for an ID \n");
    printf("2.Look for a String in the other fields \n");
    scanf("%i",&op);
    printf("\n");
    switch (op){
        struct node *tmpN;
        case 1: 
                printf("SELECT AN OPTION \n");
                printf("1.Exact match\n");
                printf("2.Values lesser or equal to id\n");
                printf("3.Values greater or equal to id\n");
                scanf("%d", &op1);
                printf("Digit the ID: ");
                scanf("%i",&search);
                switch(op1){
                            case 1:
                                
                                tmpN=findId(search,ptr);
                                printNode(tmpN);
                                break;
                            case 2:
                                //printSearch(ptr, search, op1);
                                break;
                            case 3:
                                printSearch(ptr, search, op1);
                                break;
                            default:
                                printf("Please select a valid option.\n");
                            break;
                }
                break;
        case 2: 
                printf("SELECT AN OPTION \n");
                printf("1.Exact match\n");
                printf("2.Substring\n");
                scanf("%d", &op2);
                switch(op2){
                            case 1:
                                printf("Digit the string: ");
                                fgets(a,40,stdin);
                                fgets(a,40,stdin);
                                parseString(a);
                                findStr1(a,ptr,&cola);
                                printf("\n");
                                printf("The entity found is: \n");
                                if (!cola)                
                                    printf("There is no entity. \n");
                                else{
                                    while(cola)
                                        printNode(deQueue(&cola));
                                }
                                break;
                            case 2:
                                printf("Digit the substring: ");
                                fgets(a,40,stdin);
                                fgets(a,40,stdin);
                                parseString(a);
                                findSS(a,ptr,&cola);
                                printf("\n");
                                printf("The entity found is: \n");
                                if (!cola)                
                                    printf("There is no entity. \n");
                                else{
                                    while(cola)
                                        printNode(deQueue(&cola));
                                }
                                break;
                            default:
                                printf("Please select a valid option.\n");
                            break;
                }
                break; 
        default:
                printf("Please select a valid option.\n");
    }

}

void printOneF(struct node *ptr){
    fprintf(output,"%s %s %s %i\n", ptr->id,ptr->str1,ptr->str2,ptr->var);
}

struct node *inOrderF(struct node *ptr){
    if (ptr != NULL )
    {
        inOrderF(ptr->left);
        printOneF(ptr);
        inOrderF(ptr->right);
    }
    return ptr;
}

char* toString(int input){
	char *answer;
	int tmp = input;
	int len = 0;
	while(tmp != 0){
		tmp = tmp/10;
		len++;
	}
	answer = calloc(len+1, sizeof(char));
	for(int i = len-1; i >= 0; i--){
		*(answer+i) = input%10 + '0';
		input = input/10;
	}
	return answer;
}
void deleteReturn(char *input){
	for(int i = 0; i < strlen(input); i++){
		if(*(input+i) == '\n'){
			*(input+i) = ' ';
		}
	}
}

void save(struct node *ptr, FILE *str1){
	char *tmp;
	int tempnum;

	if(ptr){
		save(ptr->left, str1);
		tmp = calloc(1025, sizeof(char));
		tempnum = ptr->id;
		tmp = toString(tempnum);
		strcat(tmp, "\n");
		fputs(tmp, str1);
		tmp = calloc(1025, sizeof(char));
		tempnum = ptr->disable;
		if(tempnum == 0){
			fputs("0\n", str1);
		}
		else{
			fputs("1\n", str1);
		}
		tmp = calloc(1025, sizeof(char));
		tmp = ptr->str1;
		deleteReturn(tmp);
		strcat(tmp, "\n");
		fputs(tmp, str1);
		tmp = calloc(1025, sizeof(char));
		tmp = ptr->str2;
		deleteReturn(tmp);
		strcat(tmp, "\n");
		fputs(tmp, str1);
		save(ptr->right, str1);
	}
}


void admintools(struct node *ptr){
    struct node *root = NULL;
    char a[20];
    char *str1, *tmp, confimation, *str2;
    int mainmenu, index, disable, id;
     id = atoi(a);
     printf("\n");
    printf("ADMINISTRATIVE TOOLS\n");
    printf("-----------------------------------------\n");
     printf("SELECT AN OPTION \n");
    printf("1.Save a backup of the information\n");
    printf("2.Load data from a backup file\n");
    scanf("%i",&mainmenu);
    switch(mainmenu){
        case 1: 
                str1 = calloc(1025, sizeof(char));
						printf("Digit the name of the file without the extension '.txt': ");
						scanf("%s", str1);
						strcat(str1, ".txt");
						output = fopen(str1, "w");
						save(ptr, output);
						fclose(output);
						printf("The data was saved correctly in the file.\n");
                        printf("\n");
                break;
        case 2:
                str1 = calloc(1025, sizeof(char));
						printf("Digit the name of the file without the extension '.txt':");
						scanf("%s", str1);
						strcat(str1, ".txt");
						input = fopen(str1, "r");
						if(input == NULL){
							printf("There is no file..\n");
						}
						else{
							printf("Do you want to delete the existing data? Digit Y/N: ");
							scanf("%c", &confimation);
							scanf("%c", &confimation);
							if(confimation == 'Y'){
								root = NULL;
								tmp = calloc(1025, sizeof(char));
								index = 0;
								disable = 0;
								while(fgets(tmp, 1025, input) != NULL){
									if(index%3 == 0){
										id = atoi(tmp);
										tmp = calloc(1025, sizeof(char));
									}
									else{
										if(index%3 == 1){
											disable = atoi(tmp);
											tmp = calloc(1025, sizeof(char));
										}
										else{
											if(index%3 == 2){
												str1 = tmp;
												deleteReturn(str1);
												tmp = calloc(1025, sizeof(char));
											}
											else{
												str2 = tmp;
												deleteReturn(str2);
                                                ptr = insert(ptr,a,str1,str2,1);
												str1 = calloc(1025, sizeof(char));
												str2 = calloc(1025, sizeof(char));
												tmp = calloc(1025, sizeof(char));
												disable = 0;
											}
										}
									}
									index++;
								}
								fclose(input);
								printf("The data was loaded successfully..\n");
							}
							else{
								printf("No changes were made.\n");
							}
						}
            
                break;
        default:
                printf("Please select a valid option\n");
    }
}


void asc(struct node *ptr,struct stack **tmpN) {
    if (ptr != NULL )
    {
        asc(ptr->left,tmpN);
        pushStack(ptr,tmpN);
        asc(ptr->right,tmpN);
    }
}

struct node *newList(struct node *newdata){
    struct node *new;
    new = malloc(sizeof(struct queue));
    strcpy(new->str1,newdata->str1);
    strcpy(new->str2,newdata->str2);
    strcpy(new->id, newdata->id);
    new->next=NULL;
    new->prev=NULL;
    return new;
}

struct node *deleteList(struct node **ptr){
    if ((*ptr)->next==NULL){
        struct node *tmpN = (*ptr);
        memset(*ptr,0,sizeof(struct queue *));
        free(*ptr);
        *ptr=NULL;
        return tmpN;
    }
    else{
        while((*ptr)->next->next)
            (*ptr)=(*ptr)->next;
        struct node *tmpN;
        tmpN = ((*ptr)->next);
        memset((*ptr)->next,0,sizeof(struct node **));
        free((*ptr)->next);
        (*ptr)->next=NULL;
        return tmpN;
    }
}

void swap(struct node *a,struct node *b){
    char tmp[1025];
    char tmp2[1025];
    char tmpint[1025];
    strcpy(tmp,a->str1);
    strcpy(tmp2,a->str2);
    strcpy(tmpint,a->id);

    strcpy(a->str1,b->str1);
    strcpy(a->str2,b->str2);
    strcpy(a->id,b->id);

    strcpy(b->str1,tmp);
    strcpy(b->str2,tmp2);
    strcpy(b->id,tmpint);
}

void sortStr(struct node ** ptr,int op){
    if (*ptr==NULL)
    {
        printf("null\n");
        return;
    }
    if (op==1)
    {
        struct node *sort;
        struct node *sort1;
        struct node *sortT;
        struct node *tmp;
        bool swapbol;
        int tmpN;
        for (sort = *ptr; sort !=NULL;sort=sort->next)
        {
            sortT = sort;
            swapbol=false;
            for (sort1 = sort->next; sort1 !=NULL ; sort1=sort1->next)
            {
                tmp=sort->next;
                tmpN = strcmp(sortT->str1,sort1->str1);
                if (tmpN>0)
                {
                    swapbol = true;
                    sortT=sort1;
                }
            }
            if (swapbol==true)
            {
                swap(sortT,sort);
            }
        }
    }
    else
    {
        struct node *sort,*sort1,*max,*tmp;
        bool swapbol;
        max = *ptr;
        for (sort = *ptr; sort !=NULL ;sort=sort->next)
        {
            max = sort;
            swapbol=false;
            for (sort1 = sort->next; sort1 !=NULL ; sort1=sort1->next)
            {
                tmp=sort->next->next;
                if (strcmp(max->str1,sort1->str1)<0)
                {
                    swapbol = true;
                    max=sort1;
                }
            }
            if (swapbol==true)
            {
                swap(max,sort);
            }
        }
    }
}

void push (struct node **ptr,struct node *newdata){
    if (*ptr==NULL){
        printf("null\n");
        *ptr = newList(newdata);
    }
    else{
        struct node *new,*tmpN;
        tmpN = *ptr;
        new = newList(newdata);
        new->next=*ptr;
        tmpN->prev = new;
        *ptr = new;
    }
}

void list(struct node **ptr,struct stack **tmpN){
    while(*tmpN){
        push (ptr,popStack(tmpN));
    }
}

void printL(struct node *pthp,struct node *ptr){
    struct node *tmpN;
    tmpN=findStr(pthp->str1,ptr,1);
    printNode(tmpN);
}

void totalReport(struct node *ptr){
    struct stack *stackaux=NULL;
    struct node *list=NULL;
    int bol = 0;
    int op;
    printf("\n");
    printf("TOTAL REPORT\n");
    printf("-----------------------------------------\n");
    printf("SELECT AN OPTION FOR THE DISPLATION OF YOUR REPORT\n");
    do{
        printf("\n");
        printf("1.Ascending order by ID\n");
        printf("2.Descending order by ID\n");
        printf("3.Ascending order by field1\n");
        printf("4.Descending order by field1\n");
        printf("5.Ascending order by field2\n");
        printf("6.Descending order by field2\n");
        printf("0.Exit\n");
        scanf("%i",&op);
        switch(op){
            case 1:
                    printf("YOUR TOTAL REPORT IS:\n");
                    inOrder(ptr);
                    break;
            case 2: 
                    printf("YOUR TOTAL REPORT IS:\n");
                    asc(ptr,&stackaux);
                    while(stackaux)
                        printNode(popStack(&stackaux));
                    break;
            /*case 3:
                    printf("YOUR TOTAL REPORT IS:\n");
                    asc(ptr,&stackaux);
                    while(stackaux)
                        printNode(popStack(&stackaux));
                    break;
                    break;
            case 4:
                    printf("YOUR TOTAL REPORT IS:\n");
                    asc(ptr,&stackaux);
                    while(stackaux)
                        printNode(popStack(&stackaux));
                    break;
                    break;
            case 5:
                    printf("YOUR TOTAL REPORT IS:\n");
                    asc(ptr,&stackaux);
                    while(stackaux)
                        printNode(popStack(&stackaux));
                    break;
                    break;
            case 6:
                    printf("YOUR TOTAL REPORT IS:\n");
                    asc(ptr,&stackaux);
                    while(stackaux)
                        printNode(popStack(&stackaux));
                    break;
                    break;*/
            
            case 0: 
                    bol=1;
                    break;
            default: printf("Please digit a valid option");
            break;
        }
        
    }while(bol == 0);
}


int main(int argc, char const *argv[]) {
    struct node *head;
    head = NULL;
    int file=0;
    struct node *root = NULL;
    char a[1025];
    char *str1, *tmp, *str2;
    int mainmenu, index, disable, id;
    int element;
    id = atoi(a);
    char y[1025];
    FILE *input, *output;
    input = fopen("data.txt", "r");
    if(input == NULL){
		printf("There is no data, a data.txt will be created\n");
	}
	else{
		tmp = calloc(1025, sizeof(char));
		index = 0;
		disable = 0;
		while(fgets(tmp, 1025, input) != NULL){
			if(index%4 == 0){
				id = atoi(tmp);
				tmp = calloc(1025, sizeof(char));
			}
			else{
				if(index%4 == 1){
					disable = atoi(tmp);
					tmp = calloc(1025, sizeof(char));
				}
				else{
					if(index%4 == 2){
						str1 = tmp;
						deleteReturn(str1);
						tmp = calloc(1025, sizeof(char));
					}
					else{
						str2 = tmp;
						deleteReturn(str2);
                        root = insert(root,a,str1,str2,disable);
						str1 = calloc(1025, sizeof(char));
						str2 = calloc(1025, sizeof(char));
						tmp = calloc(1025, sizeof(char));
						disable = 0;
					}
				}
			}
			index++;
		}
		fclose(input);
		printf("The data was loaded successfully.\n");
	}
     printf("-----------------------------------------\n");
    printf("                 WELCOME\n");
    printf("-----------------------------------------\n");
    do{
        printf("                  MENU\n");
        printf("1.Insert a new entity\n");
        printf("2.Delete an entity\n");
        printf("3.Edit an entity\n");
        printf("4.Recover a deleted entity\n");
        printf("5.Total Report\n");
        printf("6.Search\n");
        printf("7.Administrative Tools\n");
        printf("0.Exit\n");
        printf("-----------------------------------------\n");
        scanf("%i",&mainmenu);
        switch(mainmenu){
        case 1:
                newEntity(&head);
                break;
        case 2:
                deleteEntity(head);
                break;
        case 3:
                editEntity(head);
                break;
        case 4:
                recoverEntity(head);
                break;
        case 5:
                totalReport(head);
                break;
        case 6:
                search(head);
                break;
        case 7:
                admintools(head);
                break;
        case 0:
                admintools(head);
                printf("Bye\n");
                break;
        default:
                printf("Invalid option\n");
        }
    }while(mainmenu!=0);
    return 0;
}
