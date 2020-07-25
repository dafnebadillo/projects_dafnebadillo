//Dafne Linette A01275298
//Andrea Muñoz Gris A01733058
import java.util.Scanner;
import java.util.*;

public class Sort {

    public Fracc[] bubble ( Fracc[] r){
        if (r.length > 1){
            for (int a = 0; a < r.length-1; a++) 
                for (int b = 0; b < r.length-a-1; b++) 
                    if (r[b].compare(r[b+1])==1) {  
                        Fracc var = r[b]; 
                        r[b] = r[b+1]; 
                        r[b+1] = var; 
                    } 
        } return r;
    }

    public Fracc[] insert(Fracc[] r){
        if (r.length>1){
            for (int a = 1; a < r.length; a++) { 
                Fracc swap = r[a]; 
                int b = a - 1; 
                while (b >= 0 && r[b].compare(swap)==1) { 
                    r[b + 1] = r[b]; 
                    b = b - 1; 
                } r[b + 1] = swap; 
            } 
        } return r;
    } 

    public Fracc[] select (Fracc[] r){  
        if (r.length>1){
            for (int a = 0; a< r.length; a++){ 
                    Fracc var = r[a]; 
                 for (int b = a+1; b < r.length; b++) 
                    if ((r[b]).compare(r[a])==-1)
                    {
                        a = b; 
                    }
                    r[a] = var;
            }
        } return r;
    } 
    


    
}