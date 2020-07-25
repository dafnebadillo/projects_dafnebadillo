/* DOCUMENTACION
Este es un programa escrito en C que copia un archivo en otro en sentido contrario, 
el cual deberá ser creado al momento de copiar.
El segundo archivo tiene exactamente el contenido del primero.
Usando las funciones de entrada/salida POSIX
Compilacion: se usa el comando gcc con el nombre del archivo: 
gcc programa3.c
Output:
creacion del archivo "programa3.txt", con la data 
del archivo "programa1.txt" en sentido contrario.

DAFNE LINETTE BADILLO CAMPUZANO A01275298
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 128

int main(int argc, char * args[]) {
	char buf[BUFSIZE];
	if (argc < 1) {  // No se dio un archivo a mostrar
    printf("Debe haber el nombre de un archivo\n");
    exit(1);
	}
	else {
        int file = open ("programa1.txt", O_RDONLY);  //Abre archivo para solo lectura
        int n;
        int file2 = open("programa3.txt", O_CREAT|O_WRONLY, 0700); // Crea el archivo
        /* Coloca el puntero en la ultima posición */
        lseek(file,2662,SEEK_SET);
        while ((n = read(file, &buf, sizeof(char))) < 0){ //copia el texto 
            write(file2, &buf, n-1);
        }
        if (file == -1) {  // Error al abrir el archivo
            printf("No encontré el archivo\n");
            exit(1);
        }
        close(file);
        close(file2);
        return 0;
  	}
}