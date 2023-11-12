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



    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }


    game() {

    }

    game( String Name) {
        this.Name = Name;
    
    }

    void ler(String Frase) {
        int i = 0;
        String Nome = "";
        while(Frase.charAt(i) != ',')
        {
                i++;
        }
        i++;
        while(Frase.charAt(i) != ',')
        {
            Nome = Nome + Frase.charAt(i);
                i++;
        }
        this.Name = Nome;
        
        
    }

    static boolean isFim(String palavra) {
        boolean result = false;
        if (palavra.charAt(0) == 'F' && palavra.charAt(1) == 'I' && palavra.charAt(2) == 'M')
            result = true;
        return result;
    }

    public static void main(String[] args) throws IOException {
        
        String id;
        String[] arraydenomes = new String[50];
        String aux = "";
        int k = 0;
        game GAME = new game();
        int j = 0;
        String aux2 = "1";
        String nome = "";
        id = MyIO.readString();
        BufferedReader arq = new BufferedReader(new FileReader("/tmp/games.csv"));

        long Inicio = System.currentTimeMillis();

        while (isFim(id) == false) {
            arq = new BufferedReader(new FileReader("/tmp/games.csv"));

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

        nome =  MyIO.readLine();
        int contador = 0;
        int comparacoes = 0;
        while (isFim(nome) == false) {

            for (int i = 0; i < arraydenomes.length; i++) {
                if (arraydenomes[i].equals(nome) ) {
                    i = arraydenomes.length;
                }
                else
                {
                    contador ++;
                }
                comparacoes++;
            }

            if(contador == arraydenomes.length )
            {
                System.out.println("NAO");
            }
            else{
                System.out.println("SIM");
            }

            contador = 0;
            nome =  MyIO.readLine();
        }
        
        long Final = System.currentTimeMillis();
        long tempoCodigo = Final - Inicio;
        comparacoes = comparacoes + 1;
        BufferedWriter arquivo = new BufferedWriter (new FileWriter("matrícula_sequencial.txt"));
        arquivo.write("763994\t" + tempoCodigo + "\t" + comparacoes );
        arquivo.close();
    }
}


