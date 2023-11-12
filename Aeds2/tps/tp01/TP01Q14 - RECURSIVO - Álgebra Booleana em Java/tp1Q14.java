public class tp1Q14 {
    public static boolean mudarBoolean(String string, boolean[] val) {
        boolean resultado = true;
        char[] mudar = string.toCharArray();
        char tipo = ' ';
        for (int i = string.length()-1, j = 0; i > 0; i--) {
            if (mudar[i] == '(') {
                j = i;
                tipo = mudar[j-1];
                switch(tipo) {
                    case 'd':
                        resultado = true;
                    case 't':
                        j-=3;
                        break;
                    case 'r':
                        j-=2;
                        resultado = false;
                        break;
                }

                while (mudar[j] != ')') {

                    if (mudar[j] >= 'A' && mudar[j] <= 'Z') {
                        switch(tipo) {
                            case 'd':
                                resultado &= val[mudar[j] - 'A'];
                                break;
                            case 'r':
                                resultado |= val[mudar[j] - 'A'];
                                break;
                            case 't':
                                resultado = !val[mudar[j] - 'A'];
                                break;
                        }
                    } else if (mudar[j] == '1' || mudar[j] == '0') {
                        switch(tipo) {
                            case 'd':
                                resultado &= (mudar[j] == '1');
                                break;
                            case 'r':
                                resultado |= (mudar[j] == '1');
                                break;
                            case 't':
                                resultado = (mudar[j] != '1');
                                break;
                        }
                    }
                    mudar[j] = ' ';
                    j++;
                }


                mudar[j] = (char)((resultado? 1:0) + '0');



            }
        }
        return resultado;
    }

    public static void main(String[] args) {
        boolean[] val = new boolean[MyIO.readInt()];

        for (int i = 0; i < val.length; i ++) {
            if ( (MyIO.readInt() == 1)) {
                val[i] = true;
            } else { 
                val[i] = false;
            }
        }

        String S1 = MyIO.readLine();

        while (val.length != 0) {


                if ((mudarBoolean(S1, val))) {
                    MyIO.println(1);
                }
               else{
                MyIO.println(0);
               }
            
            val = new boolean[MyIO.readInt()];
            
            for (int i = 0; i < val.length; i ++) {
                if (MyIO.readInt() == 1) {
                    val[i] =  true ;
                }
                else{
                    val[i] =   false;
                }
            }

            if (val.length > 0)
                S1 = MyIO.readLine();
        }
    }   
}