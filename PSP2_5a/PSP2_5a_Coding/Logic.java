import java.util.*;

public class Logic{
	private int NumSeg;
	private double e;
	private int dof;
	private double x;
	private double SimpsonIntegration;
	static SimpsonIntegration integral = new SimpsonIntegration();

	public void logic1a(){
		Output myOut = new Output();
		double z = integral.getSimpsonIntegration();
		myOut.writeData("out1.txt", "" +z);
	}

	public static double reverseIntegration(int seg, double e, double dof, double p) {
		double x = 1;
		double d = 0.5;
		double result = 0;
		ArrayList<Boolean> signs = new ArrayList<Boolean>();
		do {
		result = integral.integrate(seg, e, dof, x);
		if(result > p) {
			x -= d;
			signs.add(true);
		}
		else if(result < p) {
			x += d;
			signs.add(false);
		}
		System.out.println(x);
		if(signs.size() >= 2) {
			if(signs.get(signs.size()-1) != signs.get(signs.size()-2)) {
				d /= 2;
			}
		}
	} while(Math.abs(result - p) > e);
		return x;
	}
}