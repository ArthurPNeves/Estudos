 class TP01Q01RecursivoPalindromoemJava{

    static boolean palindromo(String palavra, int esq, int dir)
    {
        // Verificar se é ou não palindramo, verficando da esquerda para a direita se os caracteres sao iguais

        if ( palavra.charAt(esq) != palavra.charAt(dir) )
        {
            return false;
        }
        else
        {
            if (palavra.length()/2 == esq ) {
                return true;
            }
            return palindromo(palavra, esq + 1, dir -1);

        }
        

         
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
        
        if (palindromo(palavra, 0,palavra.length() -1 ))
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