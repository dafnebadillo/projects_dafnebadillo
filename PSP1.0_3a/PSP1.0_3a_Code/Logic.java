
import java.util.*;

public class Logic {
	
   double sumx;
   double sumy;
   double sumxx;
   double sumyy;
   double sumxy;
   double xavg;
   double yavg;
   double b01;
   double vrxy;
   double b00;
   double vyk;
    public void logic1a() {
        //Input myInput = new Input();
		Output myOut = new Output();
		//myInput.main();


		EstimacionCorLineal myEst = new EstimacionCorLineal();
        myEst.main();
		myOut.writeData("Out.txt", "SUMX " +sumx+ " SUMY " +sumy+ " SUMXX " +sumxx+ " SUMYY " +sumyy+ " SUMXY " +sumxy+ " xavg " +xavg+ " yavg " +yavg+ " b1 " +b01+ " b0 " +b00+ " rxy " +vrxy+ " yk " + vyk);
    }

}