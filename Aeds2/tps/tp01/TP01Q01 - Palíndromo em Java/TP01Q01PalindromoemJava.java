 class TP01Q01PalindromoemJava{

    static boolean palindromo(String palavra)
    {
        // iniciando variaveis locais
        boolean result = true;
        int esq;
        int x = 0;
        x = palavra.length();
        int dir = x;
        // Verificar se é ou não palindramo, verficando da esquerda para a direita se os caracteres sao iguais
        for (esq = 0; esq < x/2; esq++)
        {
            if ( palavra.charAt(esq) != palavra.charAt(dir-1) )
            {
                result = false;
            }
            dir--;
        }
        return result;
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
    palavra = MyIO.readLine();
    //Lendo todas as saidas, imprindo Sim e Nao e parando quando Fim for achado (Ultilizando Funcao isFim)

    
    while (isFim(palavra) == false) {
        
        if (palindromo(palavra))
    {
        System.out.println("SIM");
    }
    else{
        System.out.println("NAO");
        
    }
    palavra = MyIO.readLine();
    }

    }
    
}