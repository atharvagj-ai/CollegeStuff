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

        boolean macrodef = false, flag1 = false, flag2 = false,macroName = false;
        int mdtptr = 1, mntptr = 1, alaptr = 1;
        String inputfilename = "F:\\T9\\SSC\\Assi 3\\src\\Input.txt"; //Input File

        fr = new FileReader(inputfilename);
        br = new BufferedReader(fr);

        String f1 = "F:\\T9\\SSC\\Assi 3\\src\\MDT.txt";
        FileWriter fw1 = new FileWriter(f1);
        BufferedWriter bw1 = new BufferedWriter(fw1);

        String f2 = "F:\\T9\\SSC\\Assi 3\\src\\MNT.txt";
        FileWriter fw2 = new FileWriter(f2);
        BufferedWriter bw2 = new BufferedWriter(fw2);

        String f3 = "F:\\T9\\SSC\\Assi 3\\src\\ALA.txt";
        FileWriter fw3 = new FileWriter(f3);
        BufferedWriter bw3 = new BufferedWriter(fw3);

        String f4 = "F:\\T9\\SSC\\Assi 3\\src\\Output.txt";
        FileWriter fw4 = new FileWriter(f4);
        BufferedWriter bw4 = new BufferedWriter(fw4);

        try {


            String sCurrentLine, s0, s1, s2;
            while ((sCurrentLine = br.readLine()) != null) {
                s0 = sCurrentLine.split(" |\\,")[0];

                if (s0.equals("MACRO")) {
                    macrodef = true;
                    flag1 = true;
                    flag2 = true;
                }
                else if (macrodef == true || flag1 == true || flag2 == true) {
                    if (macrodef == true) {
                        bw2.write(mntptr + "\t" + s0 + "\t" + mdtptr + "\n");
                        macrodef = false;
                        macroName = true;
                        mntptr++;
                    }
                    if (flag1 == true) {
                        for (int i = 1; i < (sCurrentLine.split(" |\\,").length); i++) {
                            s1 = sCurrentLine.split(" |\\,")[i];
                            String temp;
                            bw3.write("#" + alaptr + "\t" + s1 + "\n");
                            temp = "#" + alaptr;
                            ala.put(s1, temp);
                            alaptr++;
                        }
                        flag1 = false;
                    }
                    if (flag2 == true){
                        bw1.write(mdtptr+" ");
                        for (int i = 0; i < (sCurrentLine.split(" |\\,").length); i++){
                            s2 = sCurrentLine.split(" |\\,")[i];
                            if (ala.containsKey(s2) && macroName == false){
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
                    flag2 = false;
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
