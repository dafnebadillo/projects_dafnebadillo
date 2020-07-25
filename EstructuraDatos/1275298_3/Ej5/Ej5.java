/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/
import java.util.Scanner;
import java.util.*; 
 
public class Ej5{
    
    public static void reverse (int arr[], int num){
        int arr1 [] = new int[num];
        int var = num;
        for(int i=0; i<num; i++)
        {
            arr1 [var-1] = arr[i];
            var--;
        }
        System.out.println("The reverse is: ");
        for(int rev=0; rev<num; rev++)
        {
            System.out.println(arr1[rev]);
        }
}
 
 
    public static void main (final String []args){
        Scanner sc = new Scanner(System.in);
        int num = 0;
        System.out.println("Digit the amount of elements in the array");
            num=sc.nextInt();
            int arr[] = new int[num];
            for(int i = 0; i<num; i++){
                arr[i] = sc.nextInt();
            }
            reverse(arr, num);
    }
}
 