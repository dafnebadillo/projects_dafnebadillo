//Dafne Linette A01275298
//Andrea Muñoz Gris A01733058
public class Fracc {
    int num, den; 

    public Fracc(int num, int den){ 
        this.num = num;
		this.den = den;
    }

    public int getNum(){
		return num;
	}

	public int getDen(){
		return den;
	}

    public Fracc multi (Fracc var){
        Fracc multi1 = new Fracc(num*var.num, den * var.den);
        multi1.simpl();
        return multi1;
    }
    public Fracc sum (Fracc var){
        Fracc sum1 = new Fracc((num*var.den)+(den*var.num), den * var.den);
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
                var_den = var_num % var_den; 
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

    public String toString(int var1){

		String sum_num = String.valueOf(num);
        String sum_den = String.valueOf(den);
        String nume = " ";
		String deno = " ";
        
		if (sum_num.length()<var1){
			for(int i=sum_num.length(); i<var1; i++){
				nume = nume + " ";
			}
		}
		if (sum_den.length()<var1){
			for(int j=sum_den.length(); j<var1; j++){
				deno = deno + " ";
			}
		}
        return nume + num +"/"+ deno + den;
        
    }

    public int compare (Fracc r){
		int var1 = this.num * r.den;
		int var2 = this.den * r.num;
		if(var1>var2)
			return 1;
		if(var2>var1)
			return -1;
		return 0;
	}
    


}