import java.util.*;

public class Algo extends Thread{
	public String Id;

	public Algo(String i){
		Id = i;
	}

	public void run(){
		for(int c1=0; c1<=100; c1++){
			System.out.println("cont: " +c1);
			System.out.println("ID: " +Id);
		}
	}

	public static void main(String[] args) {
		Algo a1 = new Algo("uno");
		Algo a2 = new Algo("dos");
		Algo a3 = new Algo("tres");
			a1.start();
			a2.start();
			a3.start();
		System.out.println("Se acabo");
	}
}