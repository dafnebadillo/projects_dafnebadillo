import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class Output{

    public void writeData(String outFile, String outText) {
        BufferedWriter Output = null;
        try
        {
            File file = new File(outFile);
            Output = new BufferedWriter(new FileWriter(file));
            Output.write(outText);
            Output.close();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }

}