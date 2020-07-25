
/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/

import java.util.Scanner;
import java.util.Stack;


class Main{
    public static void main(String[] args) 
    
    { 
    	Stack pila = new Stack();
    	int num_stack;
    	String oper; 
        Scanner sc = new Scanner(System.in);
        Test1 p = new Test1 ();
        System.out.println("How many operations? ");
        num_stack = sc.nextInt();
        for(int i=1; i<=num_stack; i++){
        	oper = sc.nextLine();
        	System.out.println("Operation");
        	String operation =sc.nextLine();
        	String exp = p.infixToPostfix(""+operation); 
        	System.out.println(p.postfixToEvaluation(exp)); 
        }
    } 
}