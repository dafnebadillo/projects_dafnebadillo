/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/

import java.util.Scanner;

class Ej1{
	public static void palabra(String palabra1, String palabra2){
		int i=0;
		if(palabra1.length()==palabra2.length()){
			for(int j=0; j<palabra1.length(); j++){
				if(palabra1.charAt(j) == palabra2.charAt(j))
					i++;
			}
		}
		if(i==palabra1.length())
			System.out.println("YES");
		else 
			System.out.println("NO");
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String palabra1 = sc.nextLine();
		String palabra2 = sc.nextLine();
		palabra(palabra1, palabra2);
	}
}