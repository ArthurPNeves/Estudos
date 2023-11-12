import java.io.*;
import java.net.*;

public class TP01Q08LeituradePaginaHTMLemJava {

    // funcao que le um html e poe numa string

    public static String getHtml(String endereco) {
        URL url;
        InputStream is = null;
        BufferedReader br;
        String resp = "", line;

        try {
            url = new URL(endereco);
            is = url.openStream(); // throws an IOException
            br = new BufferedReader(new InputStreamReader(is));

            while ((line = br.readLine()) != null) {
                resp += line + "\n";
            }
        } catch (MalformedURLException mue) {
            mue.printStackTrace();
        } catch (IOException ioe) {
            ioe.printStackTrace();
        }

        try {
            is.close();
        } catch (IOException ioe) {
            // nothing to see here

        }

        return resp;
    }

    // Le cada letra do site armazena em uma variavel, cada vareavel apos receber o valor ira para uma posicao do array que sera retornado na funcao 
    static int[] readhtml(String palavra1, String palavra2) {
        String palavra3;
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

        palavra3 = getHtml(palavra2);
        for (int L = 0; L < palavra3.length(); L++) {
            switch (palavra3.charAt(L)) {
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
                case 225:
                    aa++;
                    break;
                case 233:
                    ee++;
                    break;
                case 237:
                    ii++;
                    break;
                case 243:
                    oo++;
                    break;
                case 250:
                    uu++;
                    break;
                case 224:
                    aaa++;
                    break;
                case 232:
                    eee++;
                    break;
                case 236:
                    iii++;
                    break;
                case 242:
                    ooo++;
                    break;
                case 249:
                    uuu++;
                    break;
                case 227:
                    ab++;
                    break;

                case 245:
                    ob++;
                    break;
                case 226:
                    aaaa++;
                    break;
                case 234:
                    eeee++;
                    break;
                case 238:
                    iiii++;
                    break;
                case 244:
                    oooo++;
                    break;
                case 251:
                    uuuu++;
                    break;

                default:

                    break;

            }
            // verfica se a letra é consoante
            if (palavra3.charAt(L) == 'a' || palavra3.charAt(L) == 'e' || palavra3.charAt(L) == 'i'
                    || palavra3.charAt(L) == 'o' || palavra3.charAt(L) == 'u') {

            } else if (palavra3.charAt(L) <= 'z'
                    && palavra3.charAt(L) >= 'a') {
                consoante++;
            }
        }
        
        int array[] = { a, e, i, o, u, aa, ee, ii, oo, uu, aaa, eee, iii, ooo, uuu, ab, ob, aaaa, eeee, iiii, oooo,
                uuuu, consoante, br, table };
        return array;
    }
    
    // Funcao quer verifica se entrada é igual a FIM, ultiziando charAt nas posicoes0,1,2 , (Sera ultilizada na Main)
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
        // Imprindo cada frase como a quantidade e o caractere corespondente procurando novos sites ate chegar o fim

        palavra = MyIO.readLine();
        palavra2 = MyIO.readLine();

        while (isFim(palavra) == false) {
            array = readhtml(palavra, palavra2);

            x = 0;
            while (x < array.length) {
                switch (x) {
                    case 0:
                        MyIO.print("a(" + (array[x]) + ") ");
                        break;
                    case 1:
                        MyIO.print("e(" + (array[x]) + ") ");
                        break;
                    case 2:
                        MyIO.print("i(" + (array[x]) + ") ");
                        break;
                    case 3:
                        MyIO.print("o(" + (array[x]) + ") ");
                        break;
                    case 4:
                        MyIO.print("u(" + (array[x]) + ") ");
                        break;
                    case 5:
                        MyIO.print("á(" + (array[x]) + ") ");
                        break;
                    case 6:
                        MyIO.print(("é(" + (array[x]) + ") "));
                        break;
                    case 7:
                        MyIO.print("í(" + (array[x]) + ") ");
                        break;
                    case 8:
                        MyIO.print("ó(" + (array[x]) + ") ");
                        break;
                    case 9:
                        MyIO.print("ú(" + (array[x]) + ") ");
                        break;
                    case 10:
                        MyIO.print(("à(" + (array[x]) + ") "));
                        break;
                    case 11:
                        MyIO.print("è(" + (array[x]) + ") ");
                        break;

                    case 12:
                        MyIO.print("ì(" + (array[x]) + ") ");
                        break;
                    case 13:
                        MyIO.print(("ò(" + (array[x]) + ") "));
                        break;
                    case 14:
                        MyIO.print("ù(" + (array[x]) + ") ");
                        break;
                    case 15:
                        MyIO.print("ã(" + (array[x]) + ") ");
                        break;
                    case 16:
                        MyIO.print("õ(" + (array[x]) + ") ");
                        break;
                    case 17:
                        MyIO.print("â(" + (array[x]) + ") ");
                        break;
                    case 18:
                        MyIO.print("ê(" + (array[x]) + ") ");
                        break;
                    case 19:
                        MyIO.print("î(" + (array[x]) + ") ");
                        break;
                    case 20:
                        MyIO.print("ô(" + (array[x]) + ") ");
                        break;
                    case 21:
                        MyIO.print("û(" + (array[x]) + ") ");
                        break;
                    case 22:
                        MyIO.print("consoante(" + (array[x]) + ") ");
                        break;
                    case 23:
                        MyIO.print("<br>(" + (array[x]) + ") ");
                        break;
                    case 24:
                        MyIO.print("<table>(" + (array[x]) + ") ");
                        break;
                    default:
                        
                        break;
                }
                x++;
            }
            MyIO.print(palavra + "\n");
            palavra = MyIO.readLine();
            if(isFim(palavra) == false)
            {
                palavra2 = MyIO.readLine();
            }
            
        }
    }
}