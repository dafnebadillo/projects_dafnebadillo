/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/
import java.util.Scanner; 
import java.util.InputMismatchException;
import java.util.EmptyStackException;
import java.util.Stack;


public class Test1  { 
    
    public String infixToPostfix(String exp) {
        Stack <Character> stack = new Stack<Character>();
        String postfix = "";
        char ch[] = exp.toCharArray();
        for (char c: ch){
            if (c != '+' && c != '-' && c != '*' && c != '/' &&  c != '(' && c != ')'&&  c != '(' && c != ')'&&  c != '(' && c != ')'){
                postfix = postfix + c;
            }else if ( c =='('){
                stack.push(c);//add
            }else if (c ==')'){
                while (!stack.isEmpty()){
                    char t = stack.pop(); //take off
                    if (t != '('){
                        postfix = postfix + t;
                    }else
                     {  
                        break;
                    }
    
                }
            }
                else if (c=='+' || c=='-' || c=='*' ||  c=='/'){
                    if (stack.isEmpty()){
                        stack.push(c);
                    }else{
                        while (!stack.isEmpty()){
                            char t = stack.pop();
                            if (t == '('){
                                stack.push(t);
                                break;
                            }else if (t =='+' || t =='-' || t =='*' ||  t =='/'){
                                if (getP(t) < getP(c)){
                                    stack.push(t);
                                    break;
                                }else {
                                    postfix = postfix + t;
                                }
                            }
                        }
                        stack.push(c);
                    }
                }
            }
            while (!stack.isEmpty()){
                postfix = postfix + stack.pop();
            }
            return postfix;
        }
    public int getP(char c){
        if (c == '+' || c== '-'){
            return 1;
        }else {
            return 2;
        }
    }
    public int postfixToEvaluation(String exp) 
    { 
          Stack<Integer> stack=new Stack<Integer>(); 
          int var1=0;
          int var2 =0;
          char ch[] = exp.toCharArray();

          for (char c: ch){
            if (c >= '0' && c <= '9') { 
            stack.push((int)(c - '0'));
            }
            else
            { 
                 var1 = stack.pop(); 
                 var2 = stack.pop(); 
                  
                switch(c) 
                { 
                    case '+': 
                    stack.push(var1+var2); 
                    break; 
                      
                    case '-': 
                    stack.push(var1-var2); 
                    break; 

                    case '*': 
                    stack.push(var1*var2); 
                    break; 
                      
                    case '/': 
                    stack.push(var1/var2); 
                    break;       
              } 
            } 
        } return stack.pop(); 
    }
    
}