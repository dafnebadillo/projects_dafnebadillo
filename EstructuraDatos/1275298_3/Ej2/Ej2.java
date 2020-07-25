/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/

import java.util.Scanner;
public class Ej2{
    public static int count (String string, char a)
    {
	    int count = 0; 
        for (int i=0; i<string.length(); i++)
        { 
        	if (string.charAt(i) == a) 
            count++; 
        }  
        return count;
	}
    public static void main(String []args){
	    Scanner sc = new Scanner(System.in);
	    String b, string;
	    System.out.println("Digit the letter");
	        b = sc.nextLine();
	        char a = b.charAt(0);
	    System.out.println("Digit the word");
	        string = sc.nextLine();
        //System.out.println(count(string, a));
        System.out.println("The letter "+b+ " repeats "+ count(string, a) + " times ");
	}
}