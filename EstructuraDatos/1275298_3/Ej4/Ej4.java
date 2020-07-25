/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/

import java.util.Scanner;
import java.util.*; 

public class Ej4{
	public static int sum (int arr[], int i){
		int sum = arr[0];
		if (i <= 0)
			return 0;
		return (sum(arr,i-1) + arr[i - 1]);
	}
	public static void main (String []args){
		Scanner sc = new Scanner(System.in);
		int num; 
		int i;
		System.out.println("Digit the amount of elements in the array");
		num=sc.nextInt();
		int arr []  = new int [num];
		for( i=0; i<num; i++){
			arr[i] = sc.nextInt();
		}
		System.out.println("The sum of the elements in the array is:  "+ (sum(arr, arr.length)));
	}
}