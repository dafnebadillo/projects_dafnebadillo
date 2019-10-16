import java.util.Scanner;

public class PSP1_3a{
	public static void valoresN(int a[][]){
	int n, x=0, y=0;
	for(n=0; n<10; n++){
			a[n][x] = 0;
			System.out.print(" \n n \n" +n);	
		}System.out.println(" ");	
	}
	public static void valoresX(int b[][]){
		Scanner entrada = new Scanner(System.in);
		int x,a=0, sum=0;
		float xavg=0;
		System.out.println("Ingrese los valores de X");
		for(x=0; x < b.length; x++){
			System.out.print(" \n x \n" +x);
			b[a][x] = entrada.nextInt();
			sum = sum + b[a][x];
		}System.out.println("SUMATORIA" + sum);
		xavg = sum/10;
		System.out.println("Xavg = " +xavg);
		
	}
	public static void valoresY(int c[][]){
		Scanner entrada = new Scanner(System.in);
		int a=0,y, sum=0;
		float yavg = 0;
		System.out.println("Ingrese los valores de Y");
		for(y=0; y < c.length; y++){
			System.out.print(" \n y \n " +y);
			c[a][y] = entrada.nextInt();
			sum = sum + c[a][y];
		}System.out.println("SUMATORIA" +sum);
		entrada.close();
		yavg = sum/10;
		System.out.println("Yavg = " +yavg);
	}

	public static void valoresXX(int b[][], int d[][]){
		int x, a, sum=0;
		for(x=0; x<10; x++){
			for(a=0; a<1; a++){
				d[a][x] = b[a][x] * b[a][x];
				sum = sum + d[a][x];
				System.out.println("\n x^2  \n" +d[a][x]);
			}System.out.println("SUMATORIA" +sum);
		}
	}
	public static void valoresXY(int b[][], int c[][], int e[][]){
		int x, y, a=0, sum=0;
		for(x=0; x<1; x++){
			for(y=0; y<10; y++){
				e[x][y] = b[x][y] * c[x][y];
				sum = sum + e[x][y];
				System.out.println("\n xy \n" +e[x][y]);
			}System.out.println("SUMATORIA" +sum);
		}
	}
	public static void valoresYY(int c[][], int f[][]){
		int y, a, sum=0;
		for(y=0; y<10; y++){
			for(a=0; a<1; a++){
				f[a][y] = c[a][y] * c[a][y];
				sum = sum + f[a][y];
				System.out.println("\n y^2 \n" +f[a][y]);
			}System.out.println("SUMATORIA" +sum);
		}
	}

	/*public static void valoresB1(int e[][], int c[][], int b[][]){
		int b1=0, l, m;
		b1[l][m] = ((e[x][y])-(10 * ))
	}*/
	




	public static void main(String[] args){
		int n[][] = new int [10][1];
		int b[][] = new int [10][10];
		int c[][] = new int [10][10];
		int d[][] = new int [10][10];
		int e[][] = new int [10][10];
		int f[][] = new int [10][10];
		
		valoresN(n);
		valoresX(b);
		valoresY(c);
		valoresXX(b,d);
		valoresXY(b,c,e);
		valoresYY(c,f);

		
	}
}