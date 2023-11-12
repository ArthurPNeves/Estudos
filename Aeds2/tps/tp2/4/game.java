import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.Buffer;
import java.security.Principal;
import java.sql.Date;
import java.util.jar.Attributes.Name;

public class game {

    private String Name;
    private String[] arraydenomes = new String[3];
    private int comparacoes;

    public int getComparacoes() {
        return comparacoes;
    }

    public void setComparacoes(int comparacoes) {
        this.comparacoes = comparacoes;
    }

    public String[] getArraydenomes() {
        return arraydenomes;
    }

    public void setArraydenomes(String[] arraydenomes) {
        this.arraydenomes = arraydenomes;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    game() {

    }

 
    public game(String name, String[] arraydenomes, int comparacoes) {
        Name = name;
        this.arraydenomes = arraydenomes;
        this.comparacoes = comparacoes;
    }

    void ler(String Frase) {
        int i = 0;
        String Nome = "";
        while (Frase.charAt(i) != ',') {
            i++;
        }
        i++;
        while (Frase.charAt(i) != ',') {
            Nome = Nome + Frase.charAt(i);
            i++;
        }
        this.Name = Nome;

    }

    /*
     * while (i <= j) {
     * while (arraydenomes[i].charAt(n) != pivo.charAt(n)) {
     * n++;
     * }
     * while (arraydenomes[j].charAt(m) != pivo.charAt(m)) {
     * m++;
     * }
     * 
     * while (arraydenomes[i].charAt(n) < pivo.charAt(n))
     * {
     * i++;
     * }
     * while (arraydenomes[j].charAt(0) > pivo.charAt(0))
     * {
     * j--;
     * }
     * if (i <= j) {
     * 
     * String aux = arraydenomes[j];
     * arraydenomes[j] = arraydenomes[i];
     * arraydenomes[i] = aux;
     * 
     * i++;
     * j--;
     * }
     * }
     * 
     * .
     * 
     * 
     * while (i <= j) {
     * while (arraydenomes[i].charAt(0) < pivo.charAt(0))
     * {
     * i++;
     * }
     * while (arraydenomes[j].charAt(0) > pivo.charAt(0))
     * {
     * j--;
     * }
     * if (i <= j) {
     * 
     * String aux = arraydenomes[j];
     * arraydenomes[j] = arraydenomes[i];
     * arraydenomes[i] = aux;
     * i++;
     * j--;
     * }
     * }
     */

    void quicksort(int esq, int dir) {
        int i = esq, j = dir;
        int n = 0, m = 0;

        String pivo = arraydenomes[(esq + dir) / 2];

        while (i <= j) {
            n = 0;
            m = 0;
            if (arraydenomes[i].equals(pivo)) {
                while (arraydenomes[i].charAt(0) < pivo.charAt(0)) {
                    i++;
                }
            } else {

                while (arraydenomes[i].charAt(n) == pivo.charAt(n)) {
                    n++;
                }
                while (arraydenomes[i].charAt(n) < pivo.charAt(n)) {
                    i++;
                }
            }

            if (arraydenomes[j].equals(pivo)) {
                while (arraydenomes[j].charAt(0) < pivo.charAt(0)) {
                    j--;
                }
            } else {
                while (arraydenomes[j].charAt(m) == pivo.charAt(m)) {
                    m++;
                }
                while (arraydenomes[j].charAt(m) > pivo.charAt(m)) {
                    j--;
                }
            }

            if (i <= j) {

                String aux = arraydenomes[j];
                arraydenomes[j] = arraydenomes[i];
                arraydenomes[i] = aux;

                i++;
                j--;
            }
        }

        if (esq < j)
            quicksort(esq, j);
        if (i < dir)
            quicksort(i, dir);
    }

    boolean pesquisaBinare(String nome) {
        boolean resp = false;
        int dir = arraydenomes.length - 1, esq = 0, meio;
        while (esq <= dir) {
            meio = (esq + dir) / 2;
            if (nome.equals(arraydenomes[meio]) ) {
                resp = true;
                esq = arraydenomes.length;
                this.comparacoes = this.comparacoes + 1;
            } else if (nome.charAt(0) > arraydenomes[meio].charAt(0)) {
                esq = meio + 1;
                this.comparacoes = this.comparacoes + 2;
            } else {
                dir = meio - 1;
                this.comparacoes = this.comparacoes + 2;
            }
            this.comparacoes = this.comparacoes + 1;
        }

        return resp;
    }

    void procurarNome() {
        String nome = "";
        
        quicksort(0, this.arraydenomes.length - 1);
        nome = MyIO.readLine();

        while (isFim(nome) == false) {

            if (pesquisaBinare(nome)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }

            
            nome = MyIO.readLine();
        }
        
    }

    static void escreverLog(long Inicio, long Final, int comparacoes) throws IOException {
        long tempoCodigo = Final - Inicio;
        comparacoes = comparacoes + 1;
        BufferedWriter arquivo = new BufferedWriter(new FileWriter("matrícula_sequencial.txt"));
        arquivo.write("763994\t" + tempoCodigo + "\t" + comparacoes);
        arquivo.close();
    }

    static boolean isFim(String palavra) {
        boolean result = false;
        if (palavra.charAt(0) == 'F' && palavra.charAt(1) == 'I' && palavra.charAt(2) == 'M')
            result = true;
        return result;
    }

    public static void main(String[] args) throws IOException {

        String id;
        String[] arraydenomes = new String[3];
        String aux = "";
        int k = 0;
        game GAME = new game();
        int j = 0;
        String aux2 = "1";

        id = MyIO.readString();
        BufferedReader arq = new BufferedReader(new FileReader("games.csv"));

        long Inicio = System.currentTimeMillis();

        while (isFim(id) == false) {
            arq = new BufferedReader(new FileReader("games.csv"));

            while (Integer.parseInt(aux2) != Integer.parseInt(id)) {
                aux2 = "";
                j = 0;
                aux = arq.readLine();
                while (aux.charAt(j) != ',') {
                    aux2 = aux2 + aux.charAt(j);
                    j++;
                }
            }

            GAME.ler(aux);
            arraydenomes[k] = GAME.getName();
            k++;
            aux2 = "1";
            arq.close();
            id = MyIO.readString();
        }

        GAME.setArraydenomes(arraydenomes);
        int comparacoes = 0;
        GAME.procurarNome();
        comparacoes = GAME.getComparacoes();

        long Final = System.currentTimeMillis();
        escreverLog(Inicio, Final, comparacoes);
    }
}
