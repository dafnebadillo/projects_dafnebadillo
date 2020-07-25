//Andrea Munoz Gris A01733058
// Dafne Linette Badillo Campuzano A01275298

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char string[1024];
	struct node *next;
    struct node *prev;
};


void insertATB(struct node **head, char *str){
    struct node *temp = NULL;
    temp = malloc(sizeof(struct node));
    strcpy(temp->string, str);
    if (temp != NULL ){ //si se creo el nodo
        temp -> next = *head;
        temp -> prev = NULL;
        if (*head != NULL){// ve si la lista tiene un dato, ligar el dato que tienen al nuevo  
            (*head)->prev = temp;
            *head = temp;
        }
    }
}
void insertATE(struct node **head, char *str){
    struct node *temp = NULL;
    temp = malloc(sizeof(struct node));
    struct node *tempAux = *head;
    strcpy(temp->string, str);
    if (temp !=NULL){
        while (tempAux->next != NULL){
            tempAux = tempAux -> next;
        }
        temp -> prev = tempAux;
        tempAux -> next = temp;
    }
}
void deleteATB(struct node **head){
    struct node *temp = *head;
    *head = temp->next;
    if (temp -> next != NULL){
        temp -> next -> prev = NULL;
    }
	free(temp);
}

void deleteATE(struct node **head){
	while((*head)->next) {
      head = &(*head) -> next;
    }
    free(*head);
    *head = NULL;
}
void printBackwards(struct node *head){
    if(head == NULL)
    	return;
    printBackwards(head->next);
    printf("%s \n", head->string);
}
void printRecursive(struct node *head){
	struct node *temp = head;
    if (temp != NULL){
        printf("%s \n", temp->string);
        printRecursive(temp->next);
    } 
}
struct node *search(struct node *head,char *str){
	struct node *temp = head;
    struct node *ptr_s;
	while (temp != NULL){
		if(strcmp(temp->string, str) == 0){
			return temp;
		}
		temp = temp -> next;
	}
    if(ptr_s != NULL){
        printf("Not in the list\n");
    }
	return NULL;
}
void descendingSort(struct node **head){
	struct node *temp = *head;
	struct node *arr[1024];
	char str[1024];
	int cont=0;
	while(temp){
		arr[cont] = temp;
		temp = temp -> next;
		cont++;
	}
	for(int i=0; i<cont; i++){
		for(int j=0; j<(cont-1-i); j++){
			if(strcmp(arr[j]->string,arr[j+1]->string)<0){
				strcpy(str, arr[j]->string);
				strcpy(arr[j]->string, arr[j+1]->string);
				strcpy(arr[j+1]-> string, str);
			}
		}
	}
}
void ascendingSort(struct node **head){
	struct node *temp = *head;
	struct node *arr[1024];
	char str[1024];
	int cont = 0;
	while(temp){
		arr[cont] = temp;
		temp = temp -> next;
		cont++;
	}
	for(int i = 0; i < cont; i++){
		for(int j = 0; j< (cont-1-i);j++){
			if(strcmp(arr[j]->string,arr[j+1]->string)>0){
				strcpy(str, arr[j]->string);
				strcpy(arr[j]->string, arr[j+1]->string);
				strcpy(arr[j+1]-> string, str);
			}
		}
	}
}

int main(){
    struct node *head = NULL;
    head = malloc(sizeof(struct node));
    int option;
    char string[1024];
    printf("\n 1. Insert at the beginning\n 2. Insert at the end\n 3. Delete at the beginning\n 4. Delete at the end\n 5. Recursive print\n 6. Recursive backwards print\n 7. Search\n 8. Ascending sort the elements\n 9. Descending sort the elements\n 0. Quit\n");
    do{
        scanf("%d", &option);  
		if(option==1){
		    fgets(string,1024,stdin);
		    insertATB(&head,string);
		}
		if(option==2){
		    fgets(string,1024,stdin);
		    insertATE(&head,string);
		}
        if(option==3){
		    fgets(string,1024,stdin);
		    deleteATB(&head);
		}
        if(option==4){
		    fgets(string,1024,stdin);
		    deleteATE(&head);
		}
        if(option==5){
            printf("The list is: \n");
		    printRecursive(head);
		}
        
        if(option==6){
            printf("The list backward is: \n");
		    printBackwards(head);
		}
        
        if(option==7){
		    fgets(string,1024,stdin);
		    search(head, string);
		}
        
        if(option==8){
		    ascendingSort(&head);
		}
        if(option==9){
		    descendingSort(&head);
		}
    }while (option!=0);
    return 0;
}

