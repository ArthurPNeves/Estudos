
public class teste {

    static int[] readhtml(String palavra, String palavra2) {
        int a = 0;
        int e = 0;
        int i = 0;
        int o = 0;
        int u = 0;
        int aa = 0;
        int ee = 0;
        int ii = 0;
        int oo = 0;
        int uu = 0;
        int aaa = 0;
        int eee = 0;
        int iii = 0;
        int ooo = 0;
        int uuu = 0;
        int ab = 0;
        int ob = 0;
        int aaaa = 0;
        int eeee = 0;
        int iiii = 0;
        int oooo = 0;
        int uuuu = 0;
        int consoante = 0;
        int br = 0;
        int table = 0;

        palavra = ExemploURL.getHtml(palavra2);
        for (int L = 0; L < palavra.length(); L++) {
            switch (palavra.charAt(L)) {
                case 'a':
                    a++;
                    break;
                case 'e':
                    e++;
                    break;
                case 'i':
                    i++;
                    break;
                case 'o':
                    o++;
                    break;
                case 'u':
                    u++;
                    break;
                case 'á':
                    aa++;
                    break;
                case 'é':
                    ee++;
                    break;
                case 'í':
                    ii++;
                    break;
                case 'ó':
                    oo++;
                    break;
                case 'ú':
                    uu++;
                    break;
                case 'à':
                    aaa++;
                    break;
                case 'è':
                    eee++;
                    break;
                case 'ì':
                    iii++;
                    break;
                case 'ò':
                    ooo++;
                    break;
                case 'ù':
                    uuu++;
                    break;
                case 'ã':
                    ab++;
                    break;

                case 'õ':
                    ob++;
                    break;
                case 'â':
                    aaaa++;
                    break;
                case 'ê':
                    eeee++;
                    break;
                case 'î':
                    iiii++;
                    break;
                case 'ô':
                    oooo++;
                    break;
                case 'û':
                    uuuu++;
                    break;

                default:
                    break;
            }

            for (int j = 0; j < palavra.length(); j++) {
                if (palavra.charAt(j) == 'a' || palavra.charAt(j) == 'e' || palavra.charAt(j) == 'i'
                        || palavra.charAt(j) == 'o' || palavra.charAt(j) == 'u' || palavra.charAt(j) > 'z'
                        || palavra.charAt(j) < 'a') {

                } else {
                    consoante++;
                }
            }
            
        }
        MyIO.print("Teste2");
        int array[] = { a, e, i, o, u, aa, ee, ii, oo, uu, aaa, eee, iii, ooo, uuu, ab, ob, aaaa, eeee, iiii, oooo, uuuu, consoante, br, table };
        return array;
    }

    static boolean isFim(String palavra) {
        boolean result = false;
        if (palavra.charAt(0) == 'F' && palavra.charAt(1) == 'I' && palavra.charAt(2) == 'M')
            result = true;
        return result;
    }

    public static void main(String[] args) {
        // inciando variaveis
        String palavra;
        String palavra2;
        int array[];
        int x = 0;
        // Lendo todas as saidas, imprindo Sim e Nao e parando quando Fim for achado
        
        palavra = MyIO.readLine();
        palavra2 = MyIO.readLine();
        MyIO.print("Teste3");
        while (isFim(palavra) == false) {
            array = readhtml(palavra, palavra2);
            MyIO.print("Teste4");
            while (x < array.length) {
                switch (x) {
                    case 0:
                    MyIO.print("a("+(array[x])+") ");
                        break;
                    case 1:
                    MyIO.print("e("+(array[x])+") ");
                        break;
                    case 2:
                    MyIO.print("i("+(array[x])+") ");
                        break;
                    case 3:
                    MyIO.print("o("+(array[x])+") ");
                        break;
                    case 4:
                    MyIO.print("u("+(array[x])+") ");
                        break;
                    case 5:
                    MyIO.print("á("+(array[x])+") ");
                        break;
                    case 6:
                    MyIO.print("é("+(array[x])+") ");
                        break;
                    case 7:
                    MyIO.print("í("+(array[x])+") ");
                        break;
                    case 8:
                    MyIO.print("ó("+(array[x])+") ");
                        break;
                    case 9:
                    MyIO.print("ú("+(array[x])+") ");
                        break;
                    case 10:
                    MyIO.print("à("+(array[x])+") ");
                        break;
                    case 11:
                    MyIO.print("è("+(array[x])+") ");
                        break;

                    case 12:
                    MyIO.print("ì("+(array[x])+") ");
                        break;
                    case 13:
                    MyIO.print("ò("+(array[x])+") ");
                        break;
                    case 14:
                    MyIO.print("ù("+(array[x])+") ");
                        break;
                    case 15:
                    MyIO.print("ã("+(array[x])+") ");
                        break;
                    case 16:
                    MyIO.print("õ("+(array[x])+") ");
                        break;
                    case 17:
                    MyIO.print("â("+(array[x])+") ");
                        break;
                    case 18:
                    MyIO.print("ê("+(array[x])+") ");
                        break;
                    case 19:
                    MyIO.print("î("+(array[x])+") ");
                        break;
                    case 20:
                    MyIO.print("ô("+(array[x])+") ");
                        break;
                    case 21:
                    MyIO.print("û("+(array[x])+") ");
                        break;
                    case 22:
                    MyIO.print("consoante("+(array[x])+") ");
                        break;
                    case 23:
                    MyIO.print("<br>("+(array[x])+") ");
                        break;
                    case 24:
                    MyIO.print("<table>("+(array[x])+") ");
                        break;
                    default:
                    MyIO.print(palavra);
                        break;
                }
                x++;
            }
            MyIO.print("Teste5");
            palavra = MyIO.readLine();
            palavra2 = MyIO.readLine();
        }
    }
}