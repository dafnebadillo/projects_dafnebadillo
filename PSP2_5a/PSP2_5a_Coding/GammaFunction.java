import java.util.*;
import java.lang.Math;

public class GammaFunction{
	public static double gamma(double x) {
        double result = 1;
        if(x % (int)x == 0) {
            x-=1;
            while(x > 1) {
                result *= x;
                x--;
            }
        }
        else {
            double n = x*2-2;
            int c = 0;
            while(n >= 1) {
                result *= n;
                n-=2;
                c++;
            }
            result *= (Math.sqrt(Math.PI) / Math.pow(2, c));
        }
        return result;
	}	
}