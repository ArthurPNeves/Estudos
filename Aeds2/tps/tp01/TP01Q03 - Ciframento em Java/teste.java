
class teste {

    public static void main(String[] args) {
         String palavra = "Abacate";
         String palavra2;
         char c= 'c';
         for (int i = 0; i < palavra.length() -3; i++) {
            palavra = palavra.substring(i, i) + c
         }
        
        System.out.println(palavra);
    }

}