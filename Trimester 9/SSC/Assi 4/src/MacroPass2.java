import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Hashtable;

public class MacroPass2 {
    public static void main(String[] args) throws IOException {

        Hashtable<String, String> ala = new Hashtable<String, String>();
        Hashtable<String, String> mnt = new Hashtable<String, String>();

        String inputfilename = "F:\\T9\\SSC\\Assi 4\\src\\Output.txt";       //Input File
        FileReader fr1 = new FileReader(inputfilename);
        BufferedReader br1 = new BufferedReader(fr1);

        String MNT = "F:\\T9\\SSC\\Assi 4\\src\\MNT.txt";       //Input File MNT
        FileReader fr2 = new FileReader(MNT);
        BufferedReader br2 = new BufferedReader(fr2);

        String MDT = "F:\\T9\\SSC\\Assi 4\\src\\MDT.txt";       //Input File MDT
        FileReader fr3 = new FileReader(MDT);
        BufferedReader br3 = new BufferedReader(fr3);

        String ALA = "F:\\T9\\SSC\\Assi 4\\src\\ALA.txt";       //Input File ALA
        FileReader fr4 = new FileReader(ALA);
        BufferedReader br4 = new BufferedReader(fr4);

        String f1 = "F:\\T9\\SSC\\Assi 4\\src\\ExpandedCode.txt";
        FileWriter fw1 = new FileWriter(f1);
        BufferedWriter bw1 = new BufferedWriter(fw1);

        String f2 = "F:\\T9\\SSC\\Assi 4\\src\\UpdatedALA.txt";
        FileWriter fw2 = new FileWriter(f2);
        BufferedWriter bw2 = new BufferedWriter(fw2);

        LineNumberReader lineNumberReader =
                new LineNumberReader(new FileReader("F:\\T9\\SSC\\Assi 4\\src\\MDT.txt"));

        String sCurrentLine,s0,s1,s2;
        boolean macro=false;
        int line_number=0;


        while ((sCurrentLine = br4.readLine()) != null){
            s0 = sCurrentLine.split(" |\\,")[1];
            s1 = sCurrentLine.split(" |\\,")[0];
            ala.put(s0,s1);
        }

        while ((sCurrentLine = br2.readLine()) != null){
            s0 = sCurrentLine.split(" |\\,")[1];
            s1 = sCurrentLine.split(" |\\,")[2];
            mnt.put(s0,s1);
        }

        while ((sCurrentLine = br1.readLine()) != null){
            s0 = sCurrentLine.split(" |\\,")[0];
            s1 = Files.readAllLines(Paths.get("F:\\T9\\SSC\\Assi 4\\src\\MDT.txt")).get(line_number);
            s1 = s1.split(" |\\,")[1];

            if (mnt.containsKey(s0)){
                macro = true;
                line_number = (Integer.parseInt(mnt.get(s0)) - 1);

                for (int i = 0; i < (sCurrentLine.split(" |\\,").length); i++){

                    String mdt_words = Files.readAllLines(Paths.get("F:\\T9\\SSC\\Assi 4\\src\\MDT.txt")).get(line_number);
                    mdt_words = mdt_words.split(" |\\,")[i+1];

                    String output_word = sCurrentLine.split(" |\\,")[i];

                    if(mnt.containsKey(mdt_words) != true){
                        String parameter = ala.get(mdt_words);
                        ala.remove(mdt_words);
                        ala.put(parameter,output_word);
                    }

                }
                line_number++;

                while (macro == true){
                    String mdt_line = Files.readAllLines(Paths.get("F:\\T9\\SSC\\Assi 4\\src\\MDT.txt")).get(line_number);
                    s1 = mdt_line.split(" |\\,")[1];
                    if(s1.equals("MEND")){
                        macro = false;
                        line_number = 0;
                    }
                    else{
                        for (int i = 1; i < (mdt_line.split(" |\\,").length); i++){
                            String temp = mdt_line.split(" |\\,")[i];
                            if(ala.containsKey(temp)){
                                bw1.write(ala.get(temp)+ " ");
                            }
                            else {
                                bw1.write(temp+" ");
                            }
                        }
                        bw1.write("\n");
                        line_number++;
                    }
                }
            }

            else {
                bw1.write(sCurrentLine+ "\n");
            }

        }

        String ALA2 = "F:\\T9\\SSC\\Assi 4\\src\\ALA.txt";
        FileReader fr5 = new FileReader(ALA2);
        BufferedReader br5 = new BufferedReader(fr5);

        while ((sCurrentLine = br5.readLine()) != null){
            s0 = sCurrentLine.split(" |\\,")[0];
            s1 = sCurrentLine.split(" |\\,")[1];

            fw2.write(s0 + " " + s1 + " " + ala.get(s0) + "\n");
        }

        bw1.close();
        bw2.close();
    }
}
