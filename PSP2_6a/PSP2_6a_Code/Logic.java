import java.util.*;
import java.lang.Math;

public class Logic {
	static Scanner input = new Scanner(System.in);
	static SimpsonIntegration integral = new SimpsonIntegration();
	private int n = 0;

	public void logic1a() {

		Output myOut = new Output();
		double result = getUserInput();

		myOut.writeData("out3.txt", "Result = " + result);
	}

	public static double getUserInput() {
		int seg = 10;
		double e = 0.00001;
		System.out.println("Enter the value of dof");
		double dof = input.nextInt();
		System.out.println("Enter the value of p");
		double p = input.nextDouble();
		double result = reverseIntegration(seg, e, dof, p);
		return result;
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