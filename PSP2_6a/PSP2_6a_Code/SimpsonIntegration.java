import java.lang.Math;
//import org.apache.commons.math3.special.Gamma;

public class SimpsonIntegration {
    public double integrate(int seg, double e, double dof, double x) {

        double w = computeW(seg, x);
        double[] Xi = computeXi(seg, w);
        double[] BaseTerms = computeBaseTerms(Xi ,dof);
        double[] Exponent = computeExponent(BaseTerms ,dof);
        double[] Coefficient = computeCoefficient(seg ,dof);
        double[] Fxi = computeFxi(Exponent, Coefficient);
        double[] FinalTerms = computeFinalTerms(Fxi, w);
        double FinalValue = computeFinalValue(FinalTerms);
        return FinalValue;
    }

    public double computeW(int seg, double x) {
        double result = x/seg;
        return result;
    }

    public double[] computeXi(int seg, double w) {
        double[] result = new double[seg+1];
        for(int i = 0; i < result.length; i++) {
            result[i] = i*w;
        }
        return result;
    }

    public double[] computeBaseTerms(double[] Xi, double dof) {
        double[] result = new double[Xi.length];
        for(int i = 0; i < result.length; i++) {
            result[i] = 1 + (Xi[i]*Xi[i]/dof);
        }
        return result;
    }

    public double[] computeExponent(double[] BaseTerms, double dof) {
        double[] result = new double[BaseTerms.length];
        for(int i = 0; i < result.length; i++) {
            result[i] = Math.pow(BaseTerms[i], -((dof+1)/2));
        }
        return result;
    }

    public double[] computeCoefficient(int seg, double dof) {
        double[] result = new double[seg+1];
        for(int i = 0; i < result.length; i++) {
            result[i] = GammaFunction.gamma((dof+1)/2) / (Math.sqrt(dof*Math.PI)*GammaFunction.gamma(dof/2));
        }        return result;
    }

    public double[] computeFxi(double[] Exponent, double[] Coefficient) {
        double[] result = new double[Exponent.length];
        for(int i = 0; i < result.length; i++) {
            result[i] = Exponent[i]*Coefficient[i];
        }
        return result;
    }

    public double[] computeFinalTerms(double[] Fxi, double w) {
        double[] result = new double[Fxi.length];
        int m = 0;
        for(int i = 0; i < result.length; i++) {
            if(i == 0 || i == result.length-1) {
                m = 1;
            }
            else if(i%2 == 0) {
                m = 2;
            }
            else m = 4;

            result[i] = (w/3)*m*Fxi[i];
        }
        return result;
    }

    public double computeFinalValue(double[] FinalTerms) {
        double result = 0;
        for(int i = 0; i < FinalTerms.length; i++) {
            result += FinalTerms[i];
        }
        return result;
    }
}