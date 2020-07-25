//Dafne Linette Badillo Campuzano A01275298
//Andrea Munoz Gris A01733058
import java.util.Scanner;
class Main1{
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=0, b=0, c;
        int num = 0;
        int den = 0;
        System.out.println("Rows in the first matrix: ");
		int x1 = sc.nextInt(); 
        System.out.println("Columns in the first matrix");
        int y1 = sc.nextInt(); 
		Frac p1 = new Frac(x1, y1);
        System.out.println("Rows in the second matrix: ");
		int x2 = sc.nextInt();
        System.out.println("Columns in the first matrix");
        int y2 = sc.nextInt();
		Frac p2 = new Frac(x2, y2);
	
        Frac m1 [][] = new Frac [x1][y1];
        Frac m2 [][]= new Frac [x2][y2];
        Frac r [][] = new Frac [x1][y2];
		
        ArrC mat1 = new ArrC(x1, y1, m1);
        ArrC mat2 = new ArrC(x2, y2, m2);
        ArrC resul = new ArrC(x1, y2, r);
      
        if (y1 == x2){
            System.out.println();
            System.out.println("Enter the values of the first matrix: ");
            for (int mx1 = 0; mx1 < m1.length; mx1++){
                for(int my1 = 0; my1 < m1.length; my1++){
                    System.out.println("Values [" +mx1+ "][" +my1+"]");
                    System.out.println("Numerator: ");
                    num = sc.nextInt();
                    System.out.println("Denominator: ");
                    den = sc.nextInt();
                    m1[mx1][my1] = new Frac (num, den);
                    m1[mx1][my1].simpl();
                }
            }
            System.out.println();
            System.out.println("Enter the values of the second matrix: ");
            for (int mx2 = 0; mx2 < m2.length; mx2++){
                for(int my2 = 0; my2 < m2.length; my2++){
                    System.out.println("Values [" +mx2+ "][" +my2+"]");
                    System.out.println("Numerator: ");
                    num = sc.nextInt();
                    System.out.println("Denominator: ");
                    den = sc.nextInt();
                    m2[mx2][my2] = new Frac (num, den);
                    m2[mx2][my2].simpl();
                    
                }
            }System.out.println();

           System.out.println("MATRIX 1");
           for(int mx1 = 0; mx1 < m1.length; mx1++){
                for(int my1 = 0; my1 < m1.length; my1++){
                    System.out.print(" " + m1[mx1][my1].toString(mat1.matrixLength()));
                }
                System.out.println();
            }
                System.out.println();
                System.out.println();
                System.out.println("    X    ");
                System.out.println();
                System.out.println();
                System.out.println("MATRIX 2");

                for(int mx2 = 0; mx2 < m2.length; mx2++){
                    for(int my2 = 0; my2 < m2.length; my2++){
                        System.out.print(" " + m2[mx2][my2].toString(mat2.matrix1Length()));
                    }
                    System.out.println();
                }

                System.out.println();
                System.out.println();
                System.out.println("    =    ");
                System.out.println();
                System.out.println();
                System.out.println("RESULT MATRIX");


                Frac [][] difr = new Frac [a][b];
                for(a=0; a<m1.length; a++){
                    for( b=0; b<m2.length; b++){
                        Frac sum1 = new Frac (0, 1);
                        for ( c=0; c<m1.length; c++){
                            Frac mul = m1[a][c].multi(m2[c][b]);
                            sum1 = sum1.sum(mul);
                        }
                            r[a][b] = sum1;
                            r[a][b].simpl();
                    }
                }

                ArrC resulting = new ArrC(a, b, r);
                for( a=0; a<m1.length; a++){
                    for( b=0; b<m2.length; b++){
                        System.out.print(" " + r[a][b].toString(resul.matrix2Length()));
                    }
                    System.out.println();
                }
        }else{
                System.out.println();
                System.out.println("The operation is impossible");
                System.out.println();
            }
	}
}