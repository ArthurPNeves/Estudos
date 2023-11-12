
public class TP01Q09ArquivoemJava {

    public static void EscreverFile(String array[]) {
        // metodo q escreve no arquivo
        Arq.openWrite("exemplo.txt");
        
        for (int i = 0; i < array.length; i++) {
            Arq.println(array[array.length - i -1]);
        }
        Arq.close();
        
    }
    
    public static String[] fazerArray(int x)
    {
        // array q sera escrito no arquivo
        String array[] = new String[x];

        for (int i = 0; i < x; i++) {
            array[i] = MyIO.readLine();
            if (array[i].charAt(0) == '.') {
                String Temp;
                Temp = '0' + array[i];
                array[i] = Temp;
            }
        }
        
        return array;
    }

    public static void main(String[] args) {
        // incializando variaveis
        int x = MyIO.readInt();
       String string[] = fazerArray(x);
       String palavra;
       // executando methodos
        EscreverFile(string);
        Arq.openRead("exemplo.txt");
        while (Arq.hasNext() == true) {
            palavra = Arq.readString();
            MyIO.println(palavra);
            
        }
        Arq.close();
        
    }


}