
import java.util.*;

/**
 * 
 */
public class Input {
	int  data;
    public static double valoresX(int b[][]) {
		Scanner entrada = new Scanner(System.in);
        int x,a=0, sumx=0;
        System.out.println("Ingrese los valores de X");
        for(x=0; x < b.length; x++){
            System.out.print(" \n x \n" +x);
            b[a][x] = entrada.nextInt();
            sumx = sumx + b[a][x];
        }System.out.println("SUMATORIA" + sumx);
          return sumx;
	}
	public static double valoresY(int c[][]){
        Scanner entrada = new Scanner(System.in);
        int a=0,y, sumy=0;
        System.out.println("Ingrese los valores de Y");
        for(y=0; y < c.length; y++){
            System.out.print(" \n y \n " +y);
            c[a][y] = entrada.nextInt();
            sumy = sumy + c[a][y];
        }System.out.println("SUMATORIA" +sumy);
        entrada.close();
        return sumy;
    }
    public static void main(String[] args){
     
        int b[][] = new int [10][10];
        int c[][] = new int [10][10];
        double sumx =  valoresX(b);
        double sumy =  valoresY(c);
    }

}