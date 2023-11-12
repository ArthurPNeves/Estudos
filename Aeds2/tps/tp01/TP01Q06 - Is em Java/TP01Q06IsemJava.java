
public class TP01Q06IsemJava {

    // verifica se todas as letras da palavra sao vogal
    static boolean isVogal(String palavra) {
        boolean result = false;
        for (int i = 0; i < palavra.length(); i++) {
            if (palavra.charAt(i) == 'a' || palavra.charAt(i) == 'e' || palavra.charAt(i) == 'i'
                    || palavra.charAt(i) == 'o' || palavra.charAt(i) == 'u') {
                result = true;
            } else {
                return false;
            }
        }
        return result;
    }

    // verifica se todas as letras da palavra sao consoante
    static boolean isConsoante(String palavra) {
        boolean result = false;
        for (int i = 0; i < palavra.length(); i++) {
            if (palavra.charAt(i) == 'a' || palavra.charAt(i) == 'e' || palavra.charAt(i) == 'i'
                    || palavra.charAt(i) == 'o' || palavra.charAt(i) == 'u' || palavra.charAt(i) > 'z'
                    || palavra.charAt(i) < 'a') {
                return false;
            } else {
                result = true;
            }
        }
        return result;
    }
    // verifica se é um nomero a String
    static boolean isInt(String palavra) {
        boolean result = false;
        for (int i = 0; i < palavra.length(); i++) {
            if (palavra.charAt(i) >= '0' && '9' >= palavra.charAt(i)) {
                result = true;
            } else {
                return false;
            }
        }
        return result;
    }
    // verifica se é um numero real a string
    static boolean isReal(String palavra) {
        boolean result = false;
        int contador = 0;
        for (int i = 0; i < palavra.length(); i++) {
            if ((palavra.charAt(i) >= '0' && '9' >= palavra.charAt(i)) || palavra.charAt(i) == '.'
                    || palavra.charAt(i) == ',') {
                if (palavra.charAt(i) == '.' || palavra.charAt(i) == ',') {
                    contador++;
                }
                result = true;
            } else {
                return false;
            }
        }
        if (contador > 1) {
            return false;
        } else {
            return result;
        }

    }

    // Funcao quer verifica se entrada é igual a FIM, ultiziando charAt nas  posicoes0,1,2 , (Sera ultilizada na Main)
    
    static boolean isFim(String palavra) {
        boolean result = false;
        if (palavra.charAt(0) == 'F' && palavra.charAt(1) == 'I' && palavra.charAt(2) == 'M')
            result = true;
        return result;
    }

    public static void main(String[] args) {
        // inciando variaveis
        String palavra;

        // Lendo todas as saidas, imprindo Sim e Nao, caso seja verdadeira um dos methodo e parando quando Fim for achado

        palavra = MyIO.readLine();
        while (isFim(palavra) == false) {
            if (isVogal(palavra)) {
                MyIO.print("SIM ");
            } else {
                MyIO.print("NAO ");
            }

            if (isConsoante(palavra)) {
                MyIO.print("SIM ");
            } else {
                MyIO.print("NAO ");
            }

            if (isInt(palavra)) {
                MyIO.print("SIM ");
            } else {
                MyIO.print("NAO ");
            }

            if (isReal(palavra)) {
                MyIO.print("SIM\n");
            } else {
                MyIO.print("NAO\n");
            }
            palavra = MyIO.readLine();
        }
    }

}