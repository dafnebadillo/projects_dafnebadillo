//Andrea Munoz Gris A01733058
// Dafne Linette Badillo Campuzano A01275298


#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int Palindrome(char* string){ 
    
    char *ptr, *ptr2; 
    int num1; 

    for(ptr=string ; *ptr!= '\0'; ptr++)
        ;
        ptr--; 
    
    for(ptr2=string, ptr-- ; ptr>=ptr2;){
        if(*ptr==*ptr2){
            ptr--;
            ptr2++;
        }else
    break;
    }
    if(ptr2>ptr)
       return num1 = 1 ;
    else{
        return 0;
        }   
  return 0;
}



int main(){

    char str[1025], * ptr_str;
    ptr_str = str;
    char num[1025];
    int *ptr_num; 
    int var = 0;

    
    printf("How many words? \n" );
    fgets(num, 1025, stdin);
    int num_i = atoi(num); //convierte el string a entero
    int arr[num_i];
    ptr_num = arr;
    int *pointer = arr;

    for(int i = 0; i < num_i; i++){
        char *ptr, *ptr2;
        fgets(str,1025,stdin);
        (*ptr_num) = Palindrome(ptr_str);
        ptr_num++;
    }
    

    while (var < num_i){
        if ((*pointer) == 1){
            printf("YES\n");
            pointer++;
        }
        else{
            printf("NO\n");
            pointer++;
        } var++;
    }       
return 0;   
}
