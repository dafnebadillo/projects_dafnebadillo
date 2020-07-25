//Dafne Linette Badillo Campuzano A01275298
//Andrea Munoz Gris A01733058
public class Frac{
    int num, den; 
    int x1, y1;
    int x2, y2;

   public void Matrix1(int x1, int y1){
        this.x1 = x1;
        this.y1 = y1;
    }


    public void Matrix2(int x2, int y2){
        this.x2 = x2;
        this.y2 = y2;
    }

    public int getMatrixx1(){
        //System.out.println("Rows in the first matrix: ");
        return x1;
    }
    public int getMatrixy1(){
        return y1;
    }

    public int getMatrixx2(){
       
       // System.out.println("Rows in the second matrix: ");
        return x2;
    }
    public int getMatrixy2(){
        return y2;
    }


    public Frac(int num, int den){ //constructor
        this.num = num;
		this.den = den;
    }

    public int getNum(){
		return num;
	}

	public int getDen(){
		return den;
	}

    public Frac multi (Frac var){
        Frac multi1 = new Frac(num*var.num, den * var.den);
        multi1.simpl();
        return multi1;
    }
    public Frac sum (Frac var){
        Frac sum1 = new Frac((num*var.den)+(den*var.num), den * var.den);
        sum1.simpl();
        return sum1;
    }


    public int mcd (){
        int var_num = num;
        int var_den = den;

        if (var_num==0){
            return 1;
        }else{
            int mcd=1;
            while (var_den!=0){  
                mcd = var_den;
                var_den = var_num % var_den; //modulo de la division
                var_num = mcd;
            }
            return mcd;
        }
    }

    public void simpl(){
        int mcd = mcd();
        num = num / mcd;
        den = den /mcd;
    }


    public String toString(){
        simpl();
        return num +"/"+den; 
    }

    String toString(int n){
		//El numero es la extension del string
		int i, j;
		String num1 = "";
		String den1 = "";
		String snum = String.valueOf(num);
		String sden = String.valueOf(den);
		if(snum.length()<n){
			for(i=snum.length(); i<n; i++){
				num1 = num1+" ";
			}
		}
		if(sden.length()<n){
			for(j=sden.length(); j<n; j++){
				den1 = den1+" ";
			}
		}
		return (num1+num+"/"+den1+den);
	}
}