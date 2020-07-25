import java.util.Scanner;
public class Ej7{
 
    static int var = 0, pos = 1;
    public static int reverse(int num) {
        if (num > 0)
        {
            reverse(num/10);
            var += (num % 10) * pos;
            pos *= 10;
            
        }
        return var;
 
        
}
 
    public static void main (String[] args){ 
        Scanner sc = new Scanner(System.in);
        int num = 0;
        System.out.println("Digit an integer");
            num=sc.nextInt();
        System.out.println("The reverse of the integer is: "+ reverse(num));
 
    } 
}