/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/

import java.util.Scanner;

class Ej8{
		public static int sum(int num){
			if(num<0){
				System.out.println("The number is negative and can not be solved");
				return -1;
			}
			if(num==0) return 0;
			else return num % 10 + sum(num/10);
		}
		public static void main(String[] args) {
			Scanner sc = new Scanner(System.in);
			int num = sc.nextInt();
			sum(num);
			System.out.println(sum(num));
		}
	}
