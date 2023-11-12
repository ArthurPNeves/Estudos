class TP01Q03CiframentoemJava{
    // Funcao que faz ciframento colocando 3 caracteres a frente
    static String Ciframento(String palavra)
    {
        // iniciando variaveis locais
        int x = 0;
        x = palavra.length();
        int y = 0;
        char c;
        String palavra2 = "";
        // movendo para 3 caracteres a frente
        for (int i = 0; i < x; i++) {
            y = (int)palavra.charAt(i) ;
            
                y = y + 3;
                c = (char)(y);
                palavra2 = palavra2 + c;
                
        }
        
        return palavra2;
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
        palavra = Ciframento(palavra);
        MyIO.print(palavra + "\n");
        palavra = MyIO.readLine();
    }
}
}