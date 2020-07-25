/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/

import java.util.Scanner;

class Ej6{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		System.out.println(inverted(""+str));
	}

	public static String inverted(String str){
		if(str.length()<=1)
			return str;
		else
			return inverted(str.substring(1, str.length()))+str.charAt(0);
	}
}