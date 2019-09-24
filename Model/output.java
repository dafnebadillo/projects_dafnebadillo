// output.java

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class output {

    public void writeData(String outFile, String outText) {
    
    BufferedWriter output = null;
    
    try 

        {
    
            File file = new File(outFile);
            output = new BufferedWriter(new FileWriter(file));
            output.write(outText);
            output.close();
        } 

    catch ( IOException e ) 

        {
            e.printStackTrace();
        }

    }
}