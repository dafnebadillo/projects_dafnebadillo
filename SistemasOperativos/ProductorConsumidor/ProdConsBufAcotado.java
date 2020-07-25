import java.util.*;
import java.util.concurrent.*;

class Cocinero extends Thread {

    private Buffer v; 
    Semaphore vacio; 
    Semaphore lleno; 
    Semaphore exmutex;   
    int id;   

    public Cocinero (Buffer buf, Semaphore V, Semaphore LL, Semaphore Ex, int i) {
	v = buf;
	vacio = V;
	lleno = LL;
	exmutex = Ex;
	id = i;
    }

    public void run() {

	int valor;  
	do {
	    valor = (int) (Math.random()*100.0);
	    lleno.acquireUninterruptibly();
	    exmutex.acquireUninterruptibly();
	    v.set(valor);
	    System.out.println("Inserta " + valor + " id " + id);
	    exmutex.release();
	    vacio.release();

	}while (true);
    }
}

class Tribu extends Thread {

    private Buffer v;  
    Semaphore vacio;  
    Semaphore lleno;  
    Semaphore exm;  
    int id;  
    public Tribu(Buffer buf, Semaphore V, Semaphore LL, Semaphore Ex, int i) {
	v = buf;
	vacio = V;
	lleno = LL;
	exm = Ex;
	id = i;
    }
    public void run() {
	int valor;
	do {
	    vacio.acquireUninterruptibly();
	    exm.acquireUninterruptibly();
	    valor = v.get();
	    System.out.println("valor = " + valor + " id " + id);
	    exm.release();
	    lleno.release();
	}while (true);
    }
}
class Buffer {

    int[] valores;   
    int tope;  

    public Buffer (int n) {  
	valores = new int[n];
	tope = 0;
    }

    public void set(int v) {  
	if (tope < valores.length) {  
	    valores[tope] = v;
	    tope++;
	}
    }

    public int get() {
	if (tope > 0) {
		int i = valores[tope-1];  
	    tope--;  
	    return i;  
	}
	else {  
	    System.out.println("Error de pila vacía");
	    System.exit(1);
	    return -100; 
	}
    }
}

public class ProdConsBufAcotado {

    public static void main(String args[]) {

	int n;  
	int c;  
	int p; 
	int i;  
	if (args.length == 3) {

	    n = Integer.parseInt(args[0]);
	    c = Integer.parseInt(args[1]);
	    p = Integer.parseInt(args[2]);
	}
	else {  
	    n = 5;
	    c = 3;
	    p = 2;
	}
	    

	Semaphore Vacio = new Semaphore (0, true);
	Semaphore Lleno = new Semaphore (n, true);
	Semaphore ExMut = new Semaphore (1,true);
	
	Buffer bufer = new Buffer(n);
	Tribu[] tribus = new Tribu[c];
	Cocinero[] cocineros = new Cocinero[p];

	for (i = 0; i < c; i++)
	    tribus[i] = new Tribu(bufer, Vacio, Lleno, ExMut, i);

	for (i = 0; i < p; i++)
	    cocineros[i] = new Cocinero(bufer, Vacio, Lleno, ExMut, i);x

	for (i = 0; i < c; i++)
	    tribus[i].start();

	for (i = 0; i < p; i++)
	    cocineros[i].start();
	    
    }
}