/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/

import java.util.Scanner;

class Ej9{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		base2(num);
		System.out.println(base2(num));
	}

	public static String base2(int num){
		if(num/2 == 0) return "" + num;
		else return base2(num/2) + "" + num%2;
	}
}