
import java.util.*;
import java.lang.Math;

public class Rangos {
    double sumlm;
    double avglm;
    double sumln;
    double avgln;
    double avgln2;
    double var1;
    double sumln2;
    int n;
    double ds;
    double lnvs;
    double lns;
    double lnm;
    double lnl;
    double lnvl;
    double vs;
    double s;
    double m;
    double l;
    double vl;
    double z;

    public double[] getRangos(String[] datax, String[] datay, int n){
        sumlm = getsumlm(datax, datay, n);
        sumln = getsumln(datax, datay, n);
        avgln = sumln/n;
        sumln2 = getsumln2(avgln, datax, datay, n);
        avglm = sumlm/n;
        avgln2 = sumln2/n;
        var1 = sumln2/(n-1);
        ds = Math.sqrt(var1);
        lnvs = avgln-(2*ds);
        lns = avgln-ds;
        lnm = avgln;
        lnl = avgln+ds;
        lnvl = avgln+(2*ds);

        System.out.println("sumlm " +sumlm);
        System.out.println("sumln " +sumln);
        System.out.println("sumln2 " +sumln2);
        System.out.println("avglm " +avglm);
        System.out.println("avgln2 " +avgln2);
        System.out.println("var1 " +var1);
        System.out.println("ds " +ds);
        System.out.println("lnvs " +lnvs);
        System.out.println("lns " +lnm);
        System.out.println("lnl " +lnl);
        System.out.println("lnvl " +lnvl);

        vs = Math.exp(lnvs);
        s = Math.exp(lns);
        m = Math.exp(lnm);
        l = Math.exp(lnl);
        vl = Math.exp(lnvl);

        double[] rangos = new double[5];
        rangos[0] = vs;
        rangos[1] = s;
        rangos[2] = m;
        rangos[3] = l;
        rangos[4] = vl;
        return rangos; 
    }

    public double getsumlm(String[] datax, String[] datay, int n){
        sumlm = 0;
        for(int i=0; i < n; i++){
            sumlm += Double.parseDouble(datax[i])/Double.parseDouble(datay[i]);
        }
        return sumlm;
    }

    public double getsumln(String[] datax, String[] datay, int n){
        sumln = 0;
        for(int i=0; i < n; i++){
            sumln += Math.log(Double.parseDouble(datax[i])/Double.parseDouble(datay[i]));
        }
        return sumln;
    }

    public double getsumln2(double avgln, String[] datax, String[] datay, int n) {

        sumln2 = 0;
        z = 0;

        for (int i = 0; i < n; i++){

        z = Double.parseDouble(datax[i]) / Double.parseDouble(datay[i]);
        double  w = Math.log(z);
        double k = w - avgln;
        sumln2 += Math.pow(k, 2);

        }
        return sumln2;
    } 
                                 
}
