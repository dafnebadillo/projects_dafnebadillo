//Dafne Linette A01275298
//Andrea Muñoz Gris A01733058
import java.util.Scanner;
import java.util.*;
public class Main{
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Sort op1 = new Sort();
        Sort op2 = new Sort();
        Sort op3 = new Sort();

        int num = 0;
        int den = 0;
        System.out.println("How many fractions? ");
        int x = sc.nextInt();
        Fracc [] r = new Fracc [x];
        
        for (int a = 0; a < x; a++){
            num = sc.nextInt();
            den = sc.nextInt();
                r[a] = new Fracc (num, den); 
        }

        long begin = System.currentTimeMillis();
        op1.bubble (r);
        System.out.println("Bubble: ");
            for(int i = 0; i < r.length; i++){
                System.out.println(r[i]);
            }  
        long end = System.currentTimeMillis();
        double time = (double) ((end - begin));

        long begin1 = System.currentTimeMillis();
        op2.insert (r);
        System.out.println("Insertion: ");
            for(int i = 0; i < r.length; i++){
                System.out.println(r[i]);
            }  
        long end1 = System.currentTimeMillis();
        double time1 = (double) ((end1 - begin1));

        long begin2 = System.currentTimeMillis();
        op3.select (r);
        System.out.println("Selection: ");
            for(int i = 0; i < r.length; i++){
                System.out.println(r[i]);
            }  
        long end2 = System.currentTimeMillis();
        double time2 = (double) ((end2 - begin2));

        
    
        System.out.println("Selection sort: " +time2+ " ms");
        System.out.println("Insertion sort: " +time1+ " ms");
        System.out.println("Bubble sort: " +time+ " ms");
       

        
        
          
    }

}