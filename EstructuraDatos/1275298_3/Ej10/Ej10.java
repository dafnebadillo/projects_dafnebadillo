/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/

import java.util.Scanner;

class Ej10{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String palabra = sc.nextLine();
		palindrome(palabra);
		System.out.println(palindrome(palabra));
	}

	public static boolean palindrome(String palabra){
		if(palabra == null) return true;
		else return palindrome1(palabra, 0, palabra.length()-1);
	}

	public static boolean palindrome1(String palabra, int d, int i){
		if(d == i) return true;
		else if(palabra.charAt(i) != palabra.charAt(d)) return false;
		else if(i<d + 1){
			return palindrome1(palabra, i+1, d-1);
		} return true;
	}
}