import java.util.Random;

public class TP01Q04AlteracaoAleatoriaemJava {
    // methodo que altera aleatoriamente as letras escolhidas de acordo com a seed 4
    // ulizlizando a funcao gerador da classse random
    static String AltAleatoria(String palavra, Random gerador) {
        // iniciando variaveis locais

        int x = 0;
        x = ('a' + (Math.abs(gerador.nextInt()) % 26));
        int y = 0;
        y = ('a' + (Math.abs(gerador.nextInt()) % 26));

        String palavra2 = "";

        // subistiruir letras
        for (int i = 0; i < palavra.length(); i++) {

            if (palavra.charAt(i) == (char) x)
                palavra2 = palavra2 + (char) y;
            else
                palavra2 = palavra2 + palavra.charAt(i);
        }

        return palavra2;
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
        Random gerador = new Random();
        gerador.setSeed(4);
        // Lendo todas as saidas, as palavras com as mudancas de letras

        palavra = MyIO.readLine();
        while (isFim(palavra) == false) {
            palavra = AltAleatoria(palavra, gerador);
            MyIO.print(palavra + "\n");
            palavra = MyIO.readLine();
        }
    }

}