import java.util.Random;

/** Este archivo contiene una solución del problema de un tribu y
 * el comedor, implementando un solución usando hilos y monitores 
 * en Java.
 * Utilizando un buffer definido en 100, para que
 * el programa termine en 100, con dos contadores en dos for
 * que una corresponde a iniciar el programa y otra a obtener los valores
 * Para compilar este programa: javac Main.java
 * Para correr el programa:  java Main
 * El resultado de correr el programa es una serie de letreros de la siguiente
 * forma: "Cocinero llenando", "Tribu sirviendose" donde 
 * "Perol lleno: nn" indica si esta lleno y
 * "Perol vacio: nn" indica si esta vacio. El
 * programa terminará cuando se produzca el número 100.
 * Autor: Dafne Linette Badillo Campuzano 
 */

class Buffer{
	public char []buffer;
	private int count=0; 
	private int in=0; 
	private int out=0;
	Buffer(int size){
		buffer = new char[size];
	}
	public synchronized void Put(char c){
		while(count == buffer.length){
			System.out.println("Perol lleno");
			try{wait();}
			catch(InterruptedException e){}
			finally{}
		}
		System.out.println("Cocinero llenando " +c);
		buffer[in] = c;
		in = (in+1) % buffer.length;
		count++;
		notify();
	}

	public synchronized char Get(){
		while(count == 0){
			System.out.println("Perol vacio");
			try {wait();}
			catch(InterruptedException e){}
			finally{}
		}
		char c = buffer[out];
		out = (out+1) % buffer.length;
		count --;
		System.out.println("Tribu sirviendose "+c);
		notify();
		return c;
	}
}

class multi extends Thread{
	char c; 
	Buffer b;
	public multi(char c, Buffer b){
		this.c = c;
		this.b = b;
	}
	public void run(){
		b.Put(c);
	}
}

public class Main{
	public static void main(String[] args) {
		Buffer b = new Buffer(100);
		Random r; 
		char c;
		for(int i = 0; i<100; i++){
			r = new Random();
			c = (char)(r.nextInt(26)+'a');
			multi m = new multi(c,b);
			m.start();
		}
		for (int i=0;i<100;i++) {
			b.Get();
		}
	}
}