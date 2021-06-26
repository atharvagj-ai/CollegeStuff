import java.util.*;
import java.io.*;
public class Pass1 {
    public static void main(String[] args) {

        BufferedReader br = null;
        FileReader fr = null;

        FileWriter fw = null;
        BufferedWriter bw = null;

        try {
            String inputfilename = "F:\\T9\\SSC\\Temp\\src\\input.txt";        //Input File
            fr = new FileReader(inputfilename);
            br = new BufferedReader(fr);

            String OUTPUTFILENAME = "F:\\T9\\SSC\\Temp\\src\\output.txt";      //Output File
            fw = new FileWriter(OUTPUTFILENAME);
            bw = new BufferedWriter(fw);

            Hashtable<String, String> is = new Hashtable<String, String>();     //For Imperative
            is.put("STOP", "00");
            is.put("ADD", "01");
            is.put("SUB", "02");
            is.put("MULT", "03");
            is.put("MOVER", "04");
            is.put("MOVEM", "05");
            is.put("COMP", "06");
            is.put("BC", "07");
            is.put("DIV", "08");
            is.put("READ", "09");
            is.put("PRINT", "10");

            Hashtable<String, String> dl = new Hashtable<String, String>();     //For Declarative
            dl.put("DC", "01");
            dl.put("DS", "02");

            Hashtable<String, String> ad = new Hashtable<String, String>();     // For Assembler Directive

            ad.put("START", "01");
            ad.put("END", "02");
            ad.put("ORIGIN", "03");
            ad.put("EQU", "04");
            ad.put("LTORG", "05");

            Hashtable<String,String> rt = new Hashtable<>();
            rt.put("AREG","1");
            rt.put("BREG","2");
            rt.put("CREG","3");
            rt.put("DREG","4");

            Hashtable<String, String> symtab = new Hashtable<String, String>();     // SYMTAB for Symbols
            Hashtable<String, Integer> symtab_ptr = new Hashtable<>();
            Hashtable<String, String> littab = new Hashtable<String, String>();     // LITTAB for Literals
            ArrayList<Integer> pooltab=new ArrayList<Integer>();                    // PoolTab

            String sCurrentLine;
            int locptr = 0;
            int litptr = 1;
            int symptr = 1;
            int pooltabptr = 1;

            sCurrentLine = br.readLine();

            String s1 = sCurrentLine.split(" ")[1];
            String s2 = sCurrentLine.split(" ")[2];
            if (s1.equals("START")) {                                     // Initial Start check
                bw.write("\t (AD,01)\t");
                s2 = sCurrentLine.split(" ")[2];
                bw.write("(C," + s2 + ")\n");
                locptr = Integer.parseInt(s2);                            // Storing the address in pointer
            }

            while ((sCurrentLine = br.readLine()) != null) {                // untill reach end of file
                int mind_the_LC = 0;
                String type = null;

                int flag2 = 0;		                        //checks whether addr is assigned to current symbol

                s1 = sCurrentLine.split(" |\\,")[0];	// reading first word from string

                for (Map.Entry m : symtab.entrySet()) {		    // allocating addr to symbols listed
                    if (s1.equals(m.getKey())) {
                        m.setValue(locptr);
                        flag2 = 1;
                    }
                }
                if (s1.length() != 0 && flag2 == 0) {		//if current string addr is not assigned,
                    symtab_ptr.put(s1, symptr);
                    symtab.put(s1, String.valueOf(locptr));
                    symptr++;
                }

                int isOpcode = 0;		                    //checks whether current word is an opcode or not

                s1 = sCurrentLine.split(" |\\,")[1];			//second word from string

                // Cheacking in different table and values

                for (Map.Entry m : is.entrySet()) {
                    if (s1.equals(m.getKey())) {
                        bw.write(locptr + "  (IS," + m.getValue() + ")\t");		//if match found in imperative stmt
                        type = "is";
                        isOpcode = 1;
                    }
                }

                for (Map.Entry m : ad.entrySet()) {
                    if (s1.equals(m.getKey())) {
                        if (s1.equals("ORIGIN")){
                            bw.write("\t (AD," + m.getValue() + ")\t");		// Origin condition check for reset address
                            type = "ad";
                            isOpcode = 1;
                        }
                        else{
                            bw.write(locptr + "   (AD," + m.getValue() + ")\t");        //if match found in Assembler Directive
                            type = "ad";
                            isOpcode = 1;
                        }
                    }
                }
                for (Map.Entry m : dl.entrySet()) {
                    if (s1.equals(m.getKey())) {
                        bw.write(locptr+ "   (DL," + m.getValue() + ")\t");		//if match found in declarative stmt
                        type = "dl";
                        isOpcode = 1;
                    }
                }


                if (s1.equals("LTORG")) {
                    pooltab.add(pooltabptr);
                    for (Map.Entry m : littab.entrySet()) {
                        if (m.getValue() == "") {				//if addr is not assigned to the literal
                            m.setValue(locptr);
                            locptr++;
                            mind_the_LC = 1;
                            isOpcode = 1;
                        }
                    }
                    pooltabptr++;
                }


                if (s1.equals("END")) {
                    pooltab.add(pooltabptr);
                    for (Map.Entry m : littab.entrySet()) {
                        if (m.getValue() == "") {
                            m.setValue(locptr);
                            locptr++;
                            mind_the_LC = 1;
                        }
                    }
                }


                if(s1.equals("EQU")){
                    symtab.put("equ", String.valueOf(locptr));
                }


                if (sCurrentLine.split(" |\\,").length > 2) {		//if there are 3 words handel index out of bound
                    s2 = sCurrentLine.split(" |\\,")[2];				//reading the 3rd word

                    if (rt.containsKey(s2)){
                        bw.write(rt.get(s2)+"\t");
                        isOpcode = 1;
                    }
                    else if (type == "dl") {
                        bw.write("(C," + s2 + ")\t");
                    }
                    else if (s1.equals("ORIGIN")){
                        bw.write("(C," + s2 + ")\t");
                        locptr = (Integer.parseInt(s2) - 1);
                    }

                    else if (s2.contains("=")) {                                 //it is either a literal, or a symbol
                        littab.put(s2, "");
                        bw.write("(L," + litptr + ")\t");
                        isOpcode = 1;
                        litptr++;
                    }
                    else{
                        if (symtab_ptr.containsKey(s2)){
                            bw.write("(S," + symtab_ptr.get(s2) + ")\t");
                            System.out.println("contains : ");
                        }
                        else {
                            symtab.put(s2, "");
                            symtab_ptr.put(s2,symptr);
                            bw.write("(S," + symptr + ")\t");
                            symptr++;
                        }
                    }
                    /*
                    else {
                        symtab.put(s2, "");
                    }*/
                }


                if (sCurrentLine.split(" |\\,").length > 3) {		//if there are 4 words

                    String s3 = sCurrentLine.split(" |\\,")[3];			//reading 4th word.

                    if (s3.contains("=")) {                                 //it is either a literal, or a symbol
                        littab.put(s3, "");
                        bw.write("(L," + litptr + ")\t");
                        isOpcode = 1;
                        litptr++;
                    }
                    else {
                        if (symtab_ptr.containsKey(s3)){
                            bw.write("(S," + symtab_ptr.get(s3) + ")\t");
                            System.out.println("contains : ");
                        }
                        else {
                            symtab.put(s3, "");
                            symtab_ptr.put(s3,symptr);
                            bw.write("(S," + symptr + ")\t");
                            symptr++;
                        }
                    }
                }

                bw.write("\n");		//done with a line.

                if (mind_the_LC == 0){
                    if (s1.equals("DS")) {
                        locptr += Integer.parseInt(s2);
                    }
                    else {
                        locptr++;
                    }
                }

            }

            String f1 = "F:\\T9\\SSC\\Temp\\src\\SYMTAB.txt";
            FileWriter fw1 = new FileWriter(f1);
            BufferedWriter bw1 = new BufferedWriter(fw1);
            for (Map.Entry m : symtab.entrySet()) {
                bw1.write(m.getKey() + "\t" + m.getValue()+"\n");
                //System.out.println(m.getKey() + "\t" + m.getValue()+"\n");
                //System.out.println(m.getKey() + " " + m.getValue());
            }

            String f2 = "F:\\T9\\SSC\\Temp\\src\\LITTAB.txt";
            FileWriter fw2 = new FileWriter(f2);
            BufferedWriter bw2 = new BufferedWriter(fw2);
            for (Map.Entry m : littab.entrySet()) {
                bw2.write(m.getKey() + "\t" + m.getValue()+"\n");
                //System.out.println(m.getKey() + " " + m.getValue());
            }

            String f3 = "F:\\T9\\SSC\\Temp\\src\\POOLTAB.txt";
            FileWriter fw3 = new FileWriter(f3);
            BufferedWriter bw3 = new BufferedWriter(fw3);
            for (Integer item : pooltab) {
                bw3.write(item+"\n");
                //System.out.println(item);
            }

            bw.close();
            bw1.close();
            bw2.close();
            bw3.close();

        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}