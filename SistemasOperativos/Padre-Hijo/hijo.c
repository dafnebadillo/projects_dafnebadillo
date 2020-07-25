#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	pid_t id;
	int i;
	printf("Este es el ID de este proceso %d\n", (int) getpid());
	for (i = 0; i<3; i++){
		id = fork();
		if(id != 0){
			printf("Este es el proceso padre, con ID %d\n", (int) getpid());
			printf("El ID del hijo es %d\n", (int) id);
		}
		else{
			printf("Este es el proceso hijo, con ID %d\n", (int) getpid());
			i=3;
		}
	}
	return 0;
}
