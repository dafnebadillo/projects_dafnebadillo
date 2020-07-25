/* DOCUMENTACION
Este es un programa escrito en C que abre el archivo de texto 
"programa1.txt" usando las funciones entrada/salida POSIX, y lee
10 caracteres en las posiciones 0, 10, 100 y 1000.
Compilacion: se usa el comando gcc con el nombre del archivo: 
gcc programa2.c
Output:
POSICION O
Se leyeron 10 caracteres. La cadena leída es: hola txtpr

POSICION 1O
Se leyeron 10 caracteres. La cadena leída es: ueba de ta

POSICION 100
Se leyeron 10 caracteres. La cadena leída es: eñora Du

POSICION 1000
Se leyeron 10 caracteres. La cadena leída es: emor era q

DAFNE LINETTE BADILLO CAMPUZANO A01275298
*/


#include <fcntl.h>      /* Modos de apertura */
#include <stdlib.h>     /* Funciones de ficheros */
#include <stdio.h>
#include <unistd.h>


void poscero(char cadena[1000], int leidos){
  int fichero = open ("programa1.txt", O_RDONLY);  
   if (fichero==-1)
   {
        perror("Error al abrir fichero:");
        exit(1);
   }
  /* Coloca el puntero en la posición 0 */
   lseek(fichero,0,SEEK_SET);
   /* Lee diez caracteres */
   leidos = read(fichero, cadena, 10);
   close(fichero);
   cadena[10]=0;

   /* Mensaje para ver qué se leyó */
   printf ("\nPOSICION O\nSe leyeron %d caracteres. La cadena leída es: %s\n", leidos, cadena);

}

void posdiez(char cadena[1000], int leidos){
  int fichero = open ("programa1.txt", O_RDONLY);  
   if (fichero==-1)
   {
        perror("Error al abrir fichero:");
        exit(1);
   }
  /* Coloca el puntero en la posición 10 */
   lseek(fichero,10,SEEK_SET);
   /* Lee diez caracteres */
   leidos = read(fichero, cadena, 10);
   close(fichero);
   cadena[10]=0;

   /* Mensaje para ver qué se leyó */
   printf ("\nPOSICION 1O\nSe leyeron %d caracteres. La cadena leída es: %s\n", leidos, cadena);

}

void poscien(char cadena[1000], int leidos){
  int fichero = open ("programa1.txt", O_RDONLY);  
   if (fichero==-1)
   {
        perror("Error al abrir fichero:");
        exit(1);
   }
  /* Coloca el puntero en la posición 100 */
   lseek(fichero,100,SEEK_SET);
   /* Lee diez caracteres */
   leidos = read(fichero, cadena, 10);
   close(fichero);
   cadena[10]=0;

   /* Mensaje para ver qué se leyó */
   printf ("\nPOSICION 100\nSe leyeron %d caracteres. La cadena leída es: %s\n", leidos, cadena);

}

void posmil(char cadena[1000], int leidos){
  int fichero = open ("programa1.txt", O_RDONLY);  
   if (fichero==-1)
   {
        perror("Error al abrir fichero:");
        exit(1);
   }
  /* Coloca el puntero en la posición 1000 */
   lseek(fichero,1000,SEEK_SET);
   /* Lee diez caracteres */
   leidos = read(fichero, cadena, 10);
   close(fichero);
   cadena[10]=0;

   /* Mensaje para ver qué se leyó */
   printf ("\nPOSICION 1000\nSe leyeron %d caracteres. La cadena leída es: %s\n", leidos, cadena);

}

int main ( int argc, char* argv[] )
{
   char cadena[1000];
   int leidos;
   poscero(cadena, leidos);
   posdiez(cadena, leidos);
   poscien(cadena, leidos);
   posmil(cadena, leidos);
   return 0;
}

