import java.util.*;
import java.lang.Math;

public class SimpsonIntegration{

	public double getSimpsonIntegration(){
		int numSeg = 10;
		double w=0.11;
		double e = 0.00001;
		double dof = 9.0;
		double x = 1.1;		
		double[] xi = computeXi(w, numSeg);
		double[] FirstBaseTerms = computefirstBaseTerms(dof, xi);
		double[] exponent = getexponent(FirstBaseTerms, dof);
		double[] coeff = coeff(numSeg, dof);
		double[] Fxi = getFxi(exponent, coeff);
		double[] FinalTerms = getFinalTerms(Fxi, w);
		double FinalValue = FinalValue(FinalTerms);

		return FinalValue;
	}

	public double computeW(int numSeg, double x){
		double w=0;
		w = x/numSeg;
		return w;
	}

	public double[] computeXi(double w, int numSeg){
		double[] xi = new double[numSeg+1];
		for(int i=0; i < xi.length ; i++){
			xi[i] = w*i;
			System.out.println("xi = " +xi[i]);
		}
		return xi;
	}

	public double[] computefirstBaseTerms(double dof, double[] xi){
		double[] totXi = new double[xi.length];
		for(int i = 0; i < totXi.length; i++){
			totXi[i] = 1+((xi[i]*xi[i])/dof);
			System.out.println("totXi = " +totXi[i]);
		}
		return totXi;
	}

	public double[] getexponent(double[] FirstBaseTerms, double dof){
		double[] e = new double[FirstBaseTerms.length];
		for(int i=0; i < e.length; i++){
			e[i] = (Math.pow(FirstBaseTerms[i],-(dof+1)/2));
			System.out.println("e = " +e[i]);
		}
		return e;
	}

	public double[] coeff(int numSeg, double dof){
		double[] coeff = new double[numSeg+1];
		for(int i=0; i<coeff.length; i++){
			coeff[i] = GammaFunction.gamma((dof+1)/2) / (Math.sqrt(dof*Math.PI)*GammaFunction.gamma(dof/2));
			System.out.println("Coeff = " +coeff[i]);
		}
		return coeff;
	}

	public double[] getFxi(double[] getexponent, double[] coeff){
		double[] fxi = new double[getexponent.length];
		for(int i=0; i < fxi.length; i++){
			fxi[i] = getexponent[i]*coeff[i];
			System.out.println("Fxi = " +fxi[i]);
		}
		return fxi;
	}

	public double[] getFinalTerms(double[] Fxi, double w){
		double[] finalt = new double[Fxi.length];
		int y = 0;
        for(int i = 0; i < finalt.length; i++) {
            if(i == 0 || i == finalt.length-1) {
                y = 1;
            }
            else if(i%2 == 0) {
                y = 2;
            }
            else y = 4;

            finalt[i] = (w/3)*y*Fxi[i];
           System.out.println("FinalTerms = " +finalt[i]);
        }
        return finalt;
	}

	public double FinalValue(double[] FinalTerms){
		double finalValue = 0.0;
		for(int i = 0; i < FinalTerms.length; i++){
			finalValue += FinalTerms[i];
			System.out.println("Final Value = " +FinalTerms[i]);
		}

		return finalValue;
	}

}