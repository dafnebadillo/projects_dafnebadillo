/* DOCUMENTACION
Este programa es el Problema 1 de Proyectos Finales
presenta algunas de las funciones que provee Linux(Unix)
para hacer operaciones en archivos. Implementa una biblioteca 
propia para acceso a archivos en lenguaje de programación C
Para ejecutar el programa en la terminal/consola
se debe hacer de la siguiente forma:
gcc problema1.c
./a.out
----
Se desplegara un MENU que incluye las funciones para hacer
operaciones en archivos, se debe seleccionar el numero de operacion 
deseado y asi se ira repitiendo hasta que sea ejecutado el numero 0
para que el programa se termine.

Funcion 1: elegir 1. Leer 2. Esribir
Al seleccionar la 1 se debe iniciar el programa de nuevo ya que solo
abre el fichero
Funcion 2: Cerrar un archivo
Funcion 3: Leer un caracter de un archivo
Funcion 4: Escribir un caracter en un archivo
Funcion 5: Leer una cadena 
Funcion 6: Escribir una cadena
Funcion 7: Leer un numero entero
Funcion 8: Escribir un numero entero
Funcion 9: Leer un numero flotante
Funcion 10: Escribir un numero flotante

Cada funcion ejecuta su propio archivo txt, ya sea para leer o escribir
respectivamente

Funcion 0: Exit

Dafne Linette Badillo Campuzano A01275298
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#define BUFSIZE 128

void printMenu(){
	printf("-------Elija la funcion que desea ejecturar-------\n");
	printf("1. Una función para abrir un archivo. Debe admitir al menos tres modos para la apertura: leer, escribir y extender.\n");
	printf("2. Una función para cerrar un archivo que esté abierto.\n");
	printf("3. Una función para leer un caracter de un archivo.\n");
	printf("4. Una función para escribir un caracter a un archivo.\n");
	printf("5. Una función para leer una cadena de caracteres de un archivo.\n");
	printf("6. Una función para escribir una cadena de caracteres a un archivo.\n");
	printf("7. Una función para leer un número entero de un archivo.\n");
	printf("8. Una función para escribir un número entero a un archivo.\n");
	printf("9. Una función para leer un número de punto flotante de un archivo.\n");
	printf("10. Una función para escribir un número de punto flotante a un archivo.\n");
	printf("0. EXIT\n");
}


int funcion1(){
	int opcion, file;
	const char* cadena = "Hola mundo";
	printf("1. Leer\n");
	printf("2. Escribir\n");
	printf("3. Extender\n");
	scanf("%d", &opcion);
	do{
		switch(opcion){
		case 1:
			file = open("programa1.txt", O_RDONLY);
		break;
		case 2:
			file = open("fichero1.txt", O_CREAT|O_WRONLY,0644);
			//COMPROBACION DE ERRORES
			if(file == -1){
				printf("Error al abrir el fichero\n");
			}
			//ESCRITURA DE CADENA
			write(file, cadena, strlen(cadena));
			close(file);
		break;
		/*case 3:
		break;*/
		case 0:
			printf("BYE\n");
		break;
		default:
		printf("Opcion no válida\n");
		}
	}while(opcion != 0);
	return 0;
}

int funcion2(){
	int file;
	file = open("programa1.txt", O_RDONLY);
	close(file);
	return 0;
}

int funcion3(){
	char cadena[BUFSIZE];
	int leidos, pos;
	int file = open("programa1.txt", O_RDONLY);
	if(file==-1){
		perror("ERROR al abrir fichero");
		exit(1);
	}
	printf("Ingrese la posicion donde será leído el caracter:\n");
	scanf("%d", &pos);
	lseek(file, pos, SEEK_SET);
	leidos = read(file, cadena, 1);
	close(file);
	cadena[1] = 0;
	printf("Se leyó %d caracter. El caracter leído es: %s\n",leidos, cadena);
	return 0;
}

int funcion4(){
   char nombre[BUFSIZE]="fichero4.txt";
   FILE *fichero;
   int i;

   fichero = fopen( nombre, "a" );
   printf( "Fichero: %s -> ", nombre );
   if( fichero )
      printf( "existe o ha sido creado (ABIERTO)\n" );
   else
   {
      printf( "Error (NO ABIERTO)\n" );
      return 1;
   }

   printf( "Escribimos la primera letra del abecedario en el fichero: %s\n\n", nombre );
   for( i=0; i<1; i++)   
   printf( "%c", fputc('a'+i, fichero) );

   if( !fclose(fichero) )
      printf( "\nFichero cerrado\n" );
   else
   {
      printf( "\nError: fichero NO CERRADO\n" );
      return 1;
   }

   return 0;
}

int funcion5(){
   	char nombre[BUFSIZE]="programa1.txt";
   	FILE *fichero;
   	int i;

   	fichero = fopen( nombre, "r" );
   	printf( "Fichero: %s -> ", nombre );
   	if( fichero )
    	  printf( "Existe (ABIERTO)\n" );
   	else{
    	printf( "Error (NO ABIERTO)\n" );
      	return 1;
   	}
   	printf( "Los 18 primeros caracteres del fichero: %s\n\n", nombre );
   	for( i=1; i<=18; i++)   printf( "%c", fgetc(fichero) );
   		if( !fclose(fichero) )
   			printf( "\nFichero cerrado\n" );
   		else
   		{
   			printf( "\nError: fichero NO CERRADO\n" );
   			return 1;
   		}
   	return 0;
}

void funcion6(){
	FILE *fichero;
	char caracter[BUFSIZE];
	printf("Escribe la cadena que deseas escribir en el fichero: \n");
	scanf("%s", caracter);
	fichero = fopen("fichero6.txt", "wt");
	if(fichero == NULL) {
		printf("Error: No se ha podido crear el fichero fichero6.txt");
	} else {
		fwrite(&caracter, sizeof(caracter), 1, fichero);
		fclose(fichero);
	}

	fflush(stdin);
	getchar();
}

void funcion7(){
	int datoExtraido[1]; 
	char numExtraido [50];
    FILE* fichero;
    fichero = fopen("fichero7.txt", "rt");
    fgets (numExtraido, 50, fichero);
    fscanf (fichero, "%d", &datoExtraido[0] );
    printf ("Numero entero extraido es: %s", numExtraido);
    fclose(fichero);
    printf("Proceso de lectura completado\n");
}

void funcion8(){
	FILE *file;
	int valor[1];
	float promedio;
	file = fopen("fichero8.txt", "w");
	for (int i = 0; i < 1; ++i){
		printf("Escriba el valor %d\n", i+1);
		scanf("%d", &valor[i]);
		fprintf(file, "%d\n", valor[i]);
	}
	fclose(file);
}

void funcion9(){
	char cadena[BUFSIZE];
	int leidos;
	int file = open("fichero9.txt", O_RDONLY);
	if(file == -1){
		perror("Error al abrir el fichero");
		exit(1);
	}
	lseek(file,0,SEEK_SET);
	leidos = read(file, cadena,10);
	close(file);
	cadena[10]=0;
	printf("Se leyo el flotante: %s", cadena);
}



void funcion10(){
	FILE *file;
	float valor[1];
	file = fopen("fichero10.txt", "w");
	for (int i = 0; i < 1; ++i){
		printf("Escriba el valor %d\n", i+1);
		scanf("%f", &valor[i]);
		fprintf(file, "%f\n", valor[i]);
	}
	fclose(file);
}


int main(int argc, char const *argv[]){
	
	int operacion;
	char *name;

	do{
		printMenu();
		scanf("%d", &operacion);
		switch(operacion){
			case 1:
				funcion1();
			break;
			case 2:
				funcion2();
			break;
			case 3:
				funcion3();
			break;
			case 4:
				funcion4();
			break;
			case 5:
				funcion5();
			break;
			case 6:
				funcion6();
			break;
			case 7:
				funcion7();
			break;
			case 8: 
				funcion8();
			break;
			case 9:
				funcion9();
			break;
			case 10:
				funcion10();
			break;
			case 0:
				printf("BYE\n");
			break;
			default:
				printf("Opción no válida\n");
		}
	}while(operacion!=0);
	return 0;
}