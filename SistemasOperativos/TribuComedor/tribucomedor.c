#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

/** Este archivo contiene una solución del problema de un tribu y
 * el comedor, implementando un solución usando hilos, semaforos 
 * y mutex POSIX en C.
 * Utilizando una variable local NR_LOOP definida en 100, para que
 * el programa termine en 100, con dos contadores en dos funciones
 * que una corresponde a la tribu que come y la otra el comedor que sirve
 * Para compilar este programa: gcc tribucomedor.c
 * Para correr el programa:  ./a.out
 * El resultado de correr el programa es una serie de letreros de la siguiente
 * forma: "Cocinero llenando", "Tribu sirviendose" donde "Valor perol: nn" 
 * es un número entero entre 0 y 100. El
 * programa terminará cuando se produzca el número 100.
 * Autor: Dafne Linette Badillo Campuzano 
 */


#define NR_LOOP 100

static void * thread_1_function(void* arg);
static void * thread_2_function(void* arg);
static int counter = 0;
sem_t sem1;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


int main(void)
{
	pthread_t thread_1, thread_2;
	sem_init(&sem1, 0, 1);

	pthread_create(&thread_1, NULL, *thread_1_function, NULL);
	pthread_create(&thread_2, NULL, *thread_2_function, NULL);

	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);

	printf("valor perol %d\n", counter);	
	return 0;
}

static void * thread_1_function(void* arg){
	for (int i = 0; i < NR_LOOP; ++i){
		pthread_mutex_lock(&mutex);
		sem_wait(&sem1);
		counter += 1;
		pthread_mutex_unlock(&mutex);
		sem_post(&sem1);
		printf("Cocinero llenando\n");
		printf("valor perol %d\n", counter);	
	}
}

static void * thread_2_function(void* arg){
	for (int i = 0; i < NR_LOOP; ++i){
		sem_wait(&sem1);
		pthread_mutex_lock(&mutex);
		counter -= 1;
		pthread_mutex_unlock(&mutex);
		sem_post(&sem1);
		printf("Tribu Sirviendose \n");
		printf("valor perol %d\n", counter);	
	}
}