
public class TP01Q15RECURSIVOIsemJava {

    // verifica se todas as letras da palavra sao vogal
    static boolean isVogal(String palavra, int i) {
        boolean result = true;
        if (i < palavra.length()) {
            if (palavra.charAt(i) == 'a' || palavra.charAt(i) == 'e' || palavra.charAt(i) == 'i'
                    || palavra.charAt(i) == 'o' || palavra.charAt(i) == 'u') {
                result = isVogal(palavra, i + 1);

            } else {
                return false;
            }
        }
        return result;
    }

    // verifica se todas as letras da palavra sao consoante
    static boolean isConsoante(String palavra, int i) {
        boolean result = true;
        if (i < palavra.length()) {

            if (palavra.charAt(i) == 'a' || palavra.charAt(i) == 'e' || palavra.charAt(i) == 'i'
                    || palavra.charAt(i) == 'o' || palavra.charAt(i) == 'u' || palavra.charAt(i) > 'z'
                    || palavra.charAt(i) < 'a') {
                result = isConsoante(palavra, i + 1);
            } else {
                result = false;
            }

        }
        return result;
    }

    // verifica se é um nomero a String
    static boolean isInt(String palavra, int i) {
        boolean result = true;
        if (i < palavra.length()) {
            if (palavra.charAt(i) >= '0' && '9' >= palavra.charAt(i)) {
                result = isInt(palavra, i + 1);
            } else {
                return false;
            }
        }
        return result;
    }

    // verifica se é um numero real a string
    static boolean isReal(String palavra, int i, int contador) {
        boolean result = true;

        if (i < palavra.length()) {

            if ((palavra.charAt(i) >= '0' && '9' >= palavra.charAt(i)) || palavra.charAt(i) == '.'
                    || palavra.charAt(i) == ',') {

                if (palavra.charAt(i) == '.' || palavra.charAt(i) == ',') {
                    result = isReal(palavra, i + 1, contador + 1);
                } else {
                    result = isReal(palavra, i + 1, contador);
                }
                if(contador > 1)
                {
                    return false;
                }

            } else {
                return false;
            }

        }
        
        

        return result;

    }

    // Funcao quer verifica se entrada é igual a FIM, ultiziando charAt nas
    // posicoes0,1,2 , (Sera ultilizada na Main)

    static boolean isFim(String palavra) {
        boolean result = false;
        if (palavra.charAt(0) == 'F' && palavra.charAt(1) == 'I' && palavra.charAt(2) == 'M')
            result = true;
        return result;
    }

    public static void main(String[] args) {
        // inciando variaveis
        String palavra;

        // Lendo todas as saidas, imprindo Sim e Nao, caso seja verdadeira um dos
        // methodo e parando quando Fim for achado

        palavra = MyIO.readLine();
        while (isFim(palavra) == false) {
            if (isVogal(palavra, 0)) {
                MyIO.print("SIM ");
            } else {
                MyIO.print("NAO ");
            }

            if (isConsoante(palavra, 0)) {
                MyIO.print("SIM ");
            } else {
                MyIO.print("NAO ");
            }

            if (isInt(palavra, 0)) {
                MyIO.print("SIM ");
            } else {
                MyIO.print("NAO ");
            }

            if (isReal(palavra, 0, 0)) {
                MyIO.print("SIM\n");
            } else {
                MyIO.print("NAO\n");
            }
            palavra = MyIO.readLine();
        }
    }

}