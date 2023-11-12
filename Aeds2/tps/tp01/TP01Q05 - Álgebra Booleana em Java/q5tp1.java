import java.io.*;
import java.nio.charset.*;
public class q5tp1 {
    public static boolean mudarBooleano(char[] mudar, int iniciar, boolean[] valores) {
        porta porta;
        int num = iniciar;
        int fim = mudar.length;
        if (mudar[num] == 'a') porta = new AND();
        else if (mudar[num] == 'o') porta = new OR();
        else porta = new NOT();
        for(;mudar[num] != '('; num++) mudar[num] = ' ';
        for (; num < fim; num++) {
            switch(mudar[num]) {
                case 'n':
                case 'a':
                case 'o':
                    porta.conta(mudarBooleano(mudar, num, valores));
                    break;
                case ')':
                    fim = num;
                    break;        
                default:
                    if (mudar[num] >= 'A' && mudar[num] <= 'Z')
                        porta.conta(valores[mudar[num] - 'A']);
                    break;
            }
            mudar[num] = ' ';
        }
        return porta.result;
    }

        public static boolean mudarBooleano(String string, boolean[] val) {
        return mudarBooleano(string.toCharArray(), 0, val);
    }
    
    public static void main(String[] args) {
        boolean[] array = new boolean[MyIO.readInt()];

        for (int i = 0; i < array.length; i ++) {

            if (MyIO.readInt() == 1) {
                array[i] =  true ;
            }
            else{
                array[i] =   false;
            }

        }

        String S1 = MyIO.readLine();

        while (array.length != 0) {
            if ((mudarBooleano(S1, array))) {
                MyIO.println(1);
            }
           else{
            MyIO.println(0);
           }

            
            array = new boolean[MyIO.readInt()];
            
            for (int i = 0; i < array.length; i ++) {
                if (MyIO.readInt() == 1) {
                    array[i] =  true ;
                }
                else{
                    array[i] =   false;
                }
            }

            if (array.length > 0)
                S1 = MyIO.readLine();
        }
    }   
}

abstract class porta {
    public boolean result = true;    public static String name;   abstract void conta(boolean input);
}

class AND extends porta {
    @Override void conta(boolean input) {this.result &= input;}; 
}

class OR extends porta {
OR() {this.result = false;}; @Override void conta(boolean input) {this.result |= input;}; 
}

class NOT extends porta {
    @Override void conta(boolean input) {this.result = !input;}; 
}