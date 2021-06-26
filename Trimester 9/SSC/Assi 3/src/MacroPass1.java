/*
Name : Vasu Kalariya
Roll : PE29
Sub  : SSC ( Macro Pass 1)
*/

import java.io.*;
import java.util.Hashtable;

public class MacroPass1 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = null;
        FileReader fr = null;

        Hashtable<String, String> ala = new Hashtable<String, String>();

        boolean macrodef = false;               // flag for macro definition
        boolean alaParameter = false;           // flag for macro inserting ala parameters name
        boolean endMacro = false;               // flag for end of macro definition
        boolean macroName = false;              // flag for name of macro definition

        int mdtptr = 1, mntptr = 1, alaptr = 1;     // pointers for MDT, MNT, ALA

        String inputfilename = "F:\\T9\\SSC\\Assi 3\\src\\Input.txt";       //Input File
        fr = new FileReader(inputfilename);
        br = new BufferedReader(fr);

        String f1 = "F:\\T9\\SSC\\Assi 3\\src\\MDT.txt";               // MDT file
        FileWriter fw1 = new FileWriter(f1);
        BufferedWriter bw1 = new BufferedWriter(fw1);

        String f2 = "F:\\T9\\SSC\\Assi 3\\src\\MNT.txt";               // MNT file
        FileWriter fw2 = new FileWriter(f2);
        BufferedWriter bw2 = new BufferedWriter(fw2);

        String f3 = "F:\\T9\\SSC\\Assi 3\\src\\ALA.txt";               // ALA file
        FileWriter fw3 = new FileWriter(f3);
        BufferedWriter bw3 = new BufferedWriter(fw3);

        String f4 = "F:\\T9\\SSC\\Assi 3\\src\\Output.txt";            // OUTPUT file without macro expansion
        FileWriter fw4 = new FileWriter(f4);
        BufferedWriter bw4 = new BufferedWriter(fw4);

        try {


            String sCurrentLine, s0, s1, s2;
            while ((sCurrentLine = br.readLine()) != null) {
                s0 = sCurrentLine.split(" |\\,")[0];

                if (s0.equals("MACRO")) {               // check for Macro definition
                    macrodef = true;
                    alaParameter = true;
                    endMacro = true;
                }
                else if (macrodef == true || alaParameter == true || endMacro == true) {

                    if (macrodef == true) {             //  writing in MNT
                        bw2.write(mntptr + " " + s0 + " " + mdtptr + "\n");
                        macrodef = false;
                        macroName = true;
                        mntptr++;
                    }
                    if (alaParameter == true) {         //  writing in ALA
                        for (int i = 1; i < (sCurrentLine.split(" |\\,").length); i++) {
                            s1 = sCurrentLine.split(" |\\,")[i];
                            String temp;
                            bw3.write("#" + alaptr + " " + s1 + "\n");
                            temp = "#" + alaptr;
                            ala.put(s1, temp);
                            alaptr++;
                        }
                        alaParameter = false;
                    }
                    if (endMacro == true){              //  writing in MDT
                        bw1.write(mdtptr+" ");
                        for (int i = 0; i < (sCurrentLine.split(" |\\,").length); i++){

                            s2 = sCurrentLine.split(" |\\,")[i];

                            if (ala.containsKey(s2) && macroName == false){     // replacing Parameters with # number
                                bw1.write(ala.get(s2)+" ");
                            }
                            else {
                                bw1.write(s2+" ");
                            }
                        }
                        bw1.write("\n");
                        mdtptr++;
                        macroName = false;
                    }
                }

                else {
                    bw4.write(sCurrentLine+"\n");
                }

                if (s0.equals("MEND")){
                    endMacro = false;
                }
            }

        } catch (FileNotFoundException fileNotFoundException) {
            fileNotFoundException.printStackTrace();
        } catch (IOException ioException) {
            ioException.printStackTrace();
        }

        bw1.close();
        bw2.close();
        bw3.close();
        bw4.close();

    }
}
