/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/

import java.util.Scanner;
import java.util.*; 
public class Ej3{
	public static void min (int x[], int i, int num){
		int minimum = 0;
		minimum = x[0];
		for(i=0; i<num; i++){
			if (minimum >= x[i]){
				minimum = x[i];
			}
		}
		System.out.println("The minimum value is:  "+ minimum);
	}
	public static void main (String []args){
		Scanner sc = new Scanner(System.in);
		int num; 
		int i;
		System.out.println("Digit the amount of elements in the array");
		num=sc.nextInt();
		int [] x = new int [num];
		for( i=0; i<num; i++){
			x[i] = sc.nextInt();
		}
		min ( x, i, num);
	}
}