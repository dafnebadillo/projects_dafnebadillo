
import java.util.*;

public class Logic {

    private String datax;
    private String datay;
    private int n;
    private String[] arrDatax;
    private String[] arrDatay;
    private double[] rangos;
    private String resultados;



    public void logic1a() {
        Input myInput = new Input();
        Data myData = new Data();
        Rangos myRangos = new Rangos();
        Output myOut = new Output();
        datax = myInput.readData("setxx.txt");
        datay = myInput.readData("setyy.txt");

        arrDatax = myData.saveData(datax);
        arrDatay = myData.saveData(datay);
        n = arrDatax.length;
        rangos = myRangos.getRangos(arrDatax, arrDatay, n);
        resultados = "Rangos: vs = " +rangos[0]+ "\nRangos: s= " +rangos[1]+ "\nRangos: m = " +rangos[2]+ "\nRangos: l= " + rangos[3] + "\nRangos: vl= " + rangos[4];
        myOut.writeData("out2.txt", resultados);
        }

}