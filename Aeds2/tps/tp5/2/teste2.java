import java.io.*;

class Lista {
    public String[] arr;
    public int n;

    public Lista(){
        this(10000);
    }
    public Lista(int tam){
        arr = new String[tam];
        n = 0;
    }

    public void insert(String x){
        arr[n] = x;
        n++;
        
        for (int i = 0; i < n-1; i++){
            if (x.compareTo(arr[i]) == 0){
                remove();
            }
        }
    }

    public String remove(){
        return arr[--n];
    }

    public void sort(){
        for (int i = 0; i < (n-1); i++){
            int menor = i;
            for (int j = (i+1); j < n; j++){
                if (arr[menor].compareTo(arr[j]) > 0) menor = j;
            }
            swap(menor, i);
        }
    }

    public void swap(int menor, int i){
        String temp = arr[menor];
        arr[menor] = arr[i];
        arr[i] = temp;
    }

    public void show(){
        for (int i = 0; i < n; i++){
            System.out.println(arr[i]);
        }
    }
}

public class teste2 {
    public static void ler(String linha, Lista lista){
        String[] aux = new String[10000];

        linha = linha.replace("(", " ");
        linha = linha.replace(".", " ");
        linha = linha.replace("*", " ");
        linha = linha.replace("$", " ");
        linha = linha.replace("#", " ");
        linha = linha.replace("@", " ");
        linha = linha.replace("%", " ");
        linha = linha.replace("&", " ");
        linha = linha.replace(")", " ");
        linha = linha.replace(":", " ");
        linha = linha.replace("\"", " ");

        aux = linha.split("\\s+");

        for (int i = 0; i < aux.length; i++){
            if (!aux[i].isEmpty()){
                lista.insert(aux[i].toLowerCase());
            }
        }
    }

    public static void main(String[] args) throws Exception{

        FileReader r = new FileReader("pub.in");
        BufferedReader br = new BufferedReader(r);

        Lista lista = new Lista();
        
        String linha = br.readLine();
        while (linha != null){
            if (!linha.isEmpty()){
                ler(linha, lista);
            }

            linha = br.readLine();
        }

        lista.sort();
        lista.show();

        br.close();
    }
}
