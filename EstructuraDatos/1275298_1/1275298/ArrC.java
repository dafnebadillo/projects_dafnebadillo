//Dafne Linette Badillo Campuzano A01275298
//Andrea Munoz Gris A01733058
class ArrC{
    Frac arr[];
    int f;
    int c;
    Frac m[][];

    ArrC(int n){
        arr = new Frac[n];
    }

    void print(){
      for(int i=0; i<arr.length; i++)
          System.out.println(arr[i]);
    }

    void insert(int pos, Frac p){
        arr[pos] = p;
    }

    ArrC(int f,  int c, Frac m[][]){
      this.f = f;
      this.c = c;
      this.m = m;
    }

    int getF(){
      return f;
    }
    
    int getC(){
      return c;
    }
    
  
    public int matrixLength(){
        
          int cont = 0;
          int arrcLength [] = new int [f*c];
      for(int mx1=0; mx1<f; mx1++){
        for(int my1=0; my1<c; my1++){
           String sum_num = String.valueOf(m[mx1][my1].getNum());
           String sum_den = String.valueOf(m[mx1][my1].getDen());
           if(sum_num.length()>sum_den.length()){
             arrcLength[cont] = sum_num.length();
           }else{
             arrcLength[cont] = sum_den.length();
           }cont++;
        }
      }
          int var = arrcLength[0];
      for(int i=0; i<(f*c); i++){
          if(arrcLength[i]>var)
              var = arrcLength[i];
      }
      return var;
    }

    public int matrix1Length(){
      int cont = 0;
      int arrcLength [] = new int [f*c];
      for(int mx2=0; mx2<f; mx2++){
          for(int my2=0; my2<c; my2++){
            String sum_num = String.valueOf(m[mx2][my2].getNum());
            String sum_den = String.valueOf(m[mx2][my2].getDen());
            if(sum_num.length()>sum_den.length()){
                arrcLength[cont] = sum_num.length();
            }else{
         arrcLength[cont] = sum_den.length();
                 }cont++;
          }
      }
      int var = arrcLength[0];
      for(int i=0; i<(f*c); i++){
          if(arrcLength[i]>var)
              var = arrcLength[i];
      } return var;
}

    public int matrix2Length(){
      int cont = 0;
      int arrcLength [] = new int [f*c];
      for(int a=0; a<f; a++){
        for(int b=0; b<c; b++){
          String sum_num = String.valueOf(m[a][b].getNum());
          String sum_den = String.valueOf(m[a][b].getDen());
          if(sum_num.length()>sum_den.length()){
            arrcLength[cont] = sum_num.length();
          }else{
            arrcLength[cont] = sum_den.length();
          }
          cont++;
        }
      }
      int var = arrcLength[0];
      for(int i=0; i<(f*c); i++){
        if(arrcLength[i]>var)
          var = arrcLength[i];
      }
      return var;
    }
  }