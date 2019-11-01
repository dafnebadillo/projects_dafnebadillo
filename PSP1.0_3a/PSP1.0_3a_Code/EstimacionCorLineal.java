
import java.util.Scanner;

public class EstimacionCorLineal{


    public static void valoresN(int a[][]){
    int n, x=0, y=0;
    for(n=0; n<10; n++){
            a[n][x] = 0;
            System.out.print(" \n n \n" +n);    
        }System.out.println(" ");   
    }

    public static double valoresX(int b[][]){
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

    public static double valoresXX(int[][] arrsumx, int d[][]){
        int x, a, sumxx=0;
        for(x=0; x<10; x++){
            for(a=0; a<1; a++){
                d[a][x] = arrsumx[a][x] * arrsumx[a][x];
                sumxx = sumxx + d[a][x];
                System.out.println("\n x^2  \n" +d[a][x]);
            }System.out.println("SUMATORIA" +sumxx);
        }return sumxx;
    }
    public static double valoresXY(int[][] arrsumx, int[][] arrsumy, int e[][]){
        int x, y, a=0, sumxy=0;
        for(x=0; x<1; x++){
            for(y=0; y<10; y++){
                e[x][y] = arrsumx[x][y] * arrsumy[x][y];
                sumxy = sumxy + e[x][y];
                System.out.println("\n xy \n" +e[x][y]);
            }System.out.println("SUMATORIA" +sumxy);
        }
        return sumxy;
    }
    public static double valoresYY(int[][] arrsumy, int f[][]){
        int y, a, sumyy=0;
        for(y=0; y<10; y++){
            for(a=0; a<1; a++){
                f[a][y] = arrsumy[a][y] * arrsumy[a][y];
                sumyy = sumyy + f[a][y];
                System.out.println("\n y^2 \n" +f[a][y]);
            }System.out.println("SUMATORIA" +sumyy);
        }
        return sumyy;
    }

    public static double xavg(double sumx, double nn){
    	double xavg=0;
    	nn=10;
    	xavg = sumx/nn;
    	System.out.println("\n xavg \n" +xavg);
    	return xavg;
    }

    public static double yavg(double sumy, double nn){
    	double yavg;
    	nn=10;
    	yavg = sumy / nn;
    	System.out.println("\n yavg \n" +yavg);
    	return yavg;
    }

    public static double b1(double sumxy, double yavg, double sumxx, double xavg){
        double b01 = 0, barr=0, baba=0;
        barr = ((sumxy)-(10*yavg));
        baba = ((sumxx)- (10*(xavg*xavg)));
        b01 = barr / baba;
        System.out.println("B1 = " +b01);
        return b01;
    }

    public static double rxy(double sumxy, double sumx, double sumy, double sumxx, double sumyy){
        double vrxy = 0, r2 = 0, s=0, m1=0, m2=0, m3=0;
        //r2 = 0;
        s = ((10*sumxy)-(sumx*sumy));
        m1 = ((10*sumxx)-(sumx*sumx));
        m2 = ((10*sumyy)-(sumy*sumy));
        m3 = m1*m2;
        t = Math.sqrt(m3);
        vrxy = s/t;
        //r2 = rxy * rxy;
        System.out.println("\n rxy \n" +vrxy);
        //System.out.println(" \n r^2 \n" +r2);
        return vrxy;
        //return r2;
    }

    public static double b0(double yavg, double xavg, double b1){
        double b00 = 0;
        b00 = yavg - (b1*xavg);
        System.out.println("\n b0 \n");
        return b00;
    }

    public static double yk(double b0, double b1){
        double vyk=0, xk=386;
        vyk = b0 + (b1*xk);
        System.out.println("\n yk \n");
        return vyk;
    }

    public static void main(){
        int n[][] = new int [10][1];
        int b[][] = new int [10][10];
        int c[][] = new int [10][10];
        int d[][] = new int [10][10];
        int e[][] = new int [10][10];
        int f[][] = new int [10][10];
        
        valoresN(n);
        double nn = 10;

        double sumx =  valoresX(b);
        double sumy =  valoresY(c);
        double sumxx = valoresXX(b, d);
        double sumyy = valoresYY(c, f);
        double sumxy = valoresXY(b, c, e);
        double xavg = xavg(sumx, nn);
        double yavg = yavg(sumy, nn);
        double b01 = b1(sumxy, yavg, sumxx, xavg); 
        double vrxy=  rxy(sumxy, sumx, sumy, sumxx, sumyy);
        double b00 = b0(yavg, xavg, b01);
        double vyk = yk(b00, b01);
        /*System.out.println(" SUMX " +sumx);
        System.out.println(" SUMY " +sumy);
        System.out.println(" SUMXX " +sumxx);
        System.out.println(" SUMYY " +sumyy);
        System.out.println(" SUMXY " +sumxy);
        System.out.println(" xavg " +xavg);
        System.out.println(" yavg " +yavg);
        System.out.println(" b1 " +b01);
        System.out.println(" b0 " +b00);
        System.out.println(" rxy " +vrxy);
        System.out.println(" yk " +vyk);*/

        
    }
}