class TP01Q13RECURSIVOCiframentoemJava{
    // Funcao que faz ciframento colocando 3 caracteres a frente
    static String Ciframento(String palavra, int i)
    {
        // iniciando variaveis locais
        int y = 0;
        char c;
        String palavra2 = "";

        if (i <palavra.length()) {
            
            y = (int)palavra.charAt(i) ;
            y = y + 3;
            c = (char)(y);
            palavra2 = c + Ciframento(palavra, i+1);
            
        } 
        return palavra2 ;
    }
    

        // Funcao quer verifica se entrada é igual a FIM, ultiziando charAt nas posicoes0,1,2 , (Sera ultilizada na Main)

    static boolean isFim(String palavra)
    {
        boolean result = false;
        if(palavra.charAt(0) == 'F' && palavra.charAt(1) == 'I' && palavra.charAt(2) == 'M')
        result = true;
        return result;
    }
    

public static void main(String[] args) {
    // inciando variaveis
    String palavra;

    // Executando funcoes usando as devidas funcoes

    palavra = MyIO.readLine();
    while(isFim(palavra) == false)
    {
        palavra = Ciframento(palavra, 0);
        MyIO.print(palavra + "\n");
        palavra = MyIO.readLine();
    }
}
}