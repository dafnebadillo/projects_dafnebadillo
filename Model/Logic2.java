// Logic.java

public class Logic2 {

    private int n = 0;
    private String data;
    private String[] arrData;
    private String line;

    public void logic2a() {

        Input myInput = new Input();
        output myOut = new output();
        Data myData = new Data();
        //lineCounter myLine = new lineCounter();

        data = myInput.readData("set.java");
        arrData = myData.saveData(data);
        n = arrData.length;
        //line = myLine.getLineCounter(arrData, media, n);
        System.out.print("" +n);
        //myOut.writeData("out1.txt", "Lineas = " + linea);
    }
}
