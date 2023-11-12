import java.io.BufferedReader;

import java.io.FileReader;
import java.security.Principal;

class Data {

    private int dia;
    private String mes;
    private int ano;

    public int getDia() {
        return dia;
    }

    public void setDia(int dia) {
        this.dia = dia;
    }

    public String getMes() {
        return mes;
    }

    public void setMes(String mes) {
        this.mes = mes;
    }

    public int getAno() {

        return ano;
    }

    public void setAno(int ano) {

        this.ano = ano;
    }

    public Data() {
    }

    public Data(int dia, String mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

}

class Celula {
    private gameQ5 obj;
    private Celula prox, ant;
  
    public gameQ5 getObj() {
        return obj;
    }
    

    public Celula() {
    }


    public void setObj(gameQ5 obj) {
        this.obj = obj;
    }

    public Celula(gameQ5 obj, Celula prox, Celula ant) {
        this.obj = obj;
        this.prox = prox;
        this.ant = ant;
    }


    public Celula getProx() {
        return prox;
    }

    public void setProx(Celula prox) {
        this.prox = prox;
    }


    public Celula getAnt() {
        return ant;
    }


    public void setAnt(Celula ant) {
        this.ant = ant;
    }

}

class lista {

    private Celula primeiro, ultimo;
    int tamanho;
    int comparacoes, movimentacoes;

    /* 
    void inserirInicio(gameQ5 GAME) throws Exception {
        if (primeiro == null) {
            this.primeiro.setObj(GAME);
            this.ultimo.setObj(GAME);
        } else {
            Celula tmp = new Celula(GAME, null);
            tmp.setProx(primeiro);
            primeiro = tmp;
            tmp = null;
        }
        tamanho++;
    }

    void inserir(gameQ5 GAME, int posicao) throws Exception {
        if (posicao == 0) {
            inserirInicio(GAME);
        } else if (posicao < 0 || posicao > tamanho) {
            throw new Exception("erro posicao");
        } else if (posicao == tamanho) {
            inserirFim(GAME);
        } else {
            Celula i = primeiro;
            for (int j = 0; j < posicao - 1; j++, i = i.getProx())
                ;
            Celula tmp = new Celula(GAME, null);
            tmp.setProx(i.getProx());
            i.setProx(tmp);
            tmp = i = null;

        }
        tamanho++;
    }



    gameQ5 removerInicio() throws Exception {
        if (primeiro == null) {
            throw new Exception("fila vazia");
        }
        Celula tmp = primeiro;
        primeiro = primeiro.getProx();
        tamanho--;
        return tmp.getObj();
    }

    gameQ5 remover(int posicao) throws Exception {

        gameQ5 elemento;
        if (primeiro == ultimo || posicao < 0 || posicao >= tamanho) {
            throw new Exception("Erro!");
        } else if (posicao == 0) {
            elemento = removerInicio();
        } else if (posicao == tamanho - 1) {
            elemento = removerFinal();
        } else {
            Celula i = primeiro;
            for (int j = 0; j < posicao - 1; j++, i = i.getProx())
                ;
            Celula tmp = i.getProx();
            elemento = tmp.getObj();
            i.setProx(tmp.getProx());
            tmp.setProx(null);
            i = tmp = null;
        }
        tamanho--;
        return elemento;

    }

    gameQ5 removerFinal() throws Exception {
        Celula tmp = primeiro;
        for (; tmp.getProx() != ultimo; tmp = (tmp.getProx()))
            ;
        Celula tmp2 = ultimo;
        ultimo = tmp;
        ultimo.setProx(null);
        tamanho--;
        return tmp2.getObj();
    }

    void fazerAcoes() throws Exception {
        String x = MyIO.readLine();
        String aux = "";
        String aux2 = "";
        String id = "";
        String posicao = "";
        int j = 0;

        for (int i = 0; i < Integer.parseInt(x); i++) {
            aux2 = "";
            id = "";
            posicao = "";
            j = 0;
            aux = "";
            aux = MyIO.readLine();
            for (; aux.charAt(j) != ' ' && j < aux.length() - 1; j++) {
                aux2 = aux2 + aux.charAt(j);
            }
            j++;

            if (aux2.equals("II")) {
                for (; j < aux.length(); j++) {
                    id = id + aux.charAt(j);
                }

                inserirInicio(lerId(Integer.parseInt(id)));

            } else if (aux2.equals("IF")) {

                for (; j < aux.length(); j++) {
                    id = id + aux.charAt(j);
                }
                inserirFim(lerId(Integer.parseInt(id)));

            } else if (aux2.equals("I*")) {
                for (; aux.charAt(j) != ' '; j++) {
                    posicao = posicao + aux.charAt(j);
                }
                j++;
                for (; j < aux.length(); j++) {
                    id = id + aux.charAt(j);
                }

                inserir(lerId(Integer.parseInt(id)), Integer.parseInt(posicao));

            } else if (aux.equals("RF")) {

                System.out.println("(R) " + removerFinal().getName());

            } else if (aux.equals("RI")) {
                System.out.println("(R) " + removerInicio().getName());
            } else if (aux2.equals("R*")) {
                for (; j < aux.length(); j++) {
                    posicao = posicao + aux.charAt(j);
                }

                System.out.println("(R) " + remover(Integer.parseInt(posicao)).getName());

            }

        }

    }
    */

    void inserirFim(gameQ5 GAME) throws Exception {
        if (ultimo == null) {
            Celula tmp = new Celula(GAME, null, null);
            ultimo = tmp;
            primeiro = ultimo;
            tmp = null;
        } else {
            ultimo.setProx(new Celula(GAME, null, ultimo));
            ultimo = ultimo.getProx();
        }
        tamanho++;
    }
    
   /*  void ordernarLista(int esq, int dir)
    {
        int i = esq, j = dir;
        Celula pivo = encontrarCelula( (esq + dir)/2 );
        
        while (i <= j) {
            while(compararDate(pivo.getObj(), encontrarCelula(i).getObj()))
            {
                i++; comparacoes++;}
            
            while (compararDate( encontrarCelula(j).getObj(), pivo.getObj())) 
            {j--; comparacoes++;}
            if (i <= j) {
                System.out.println("\n\nSwap:" + encontrarCelula(i).getObj().getName() + "\n");
                swap(i, j);
                movimentacoes++;
                i++;
                j--;
            }
        }
        if (esq < j)  ordernarLista(esq, j);
        if (i < dir)  ordernarLista(i, dir);
    } 
    */

    int particao(int esq, int dir)
    {
        Celula pivo = encontrarCelula( dir );
        int i = (esq - 1);

        for (int j = esq; j < dir; j++) {
            if (compararDate(pivo.getObj(), encontrarCelula(j).getObj() ) ) {
      
              i++;
                swap(i, j);
            }
      
          }

          swap(dir, i + 1);

          return(i + 1);
    }

    void ordernarLista(int esq, int dir)
    {
        if (esq < dir) {
            int pi = particao(esq, dir);
            
            ordernarLista(esq, pi -1 );
            ordernarLista( pi + 1, dir );
        }
    }

    Celula encontrarCelula(int posicao){
        Celula tmp = primeiro;
        for(int k = 0;  k < posicao; k++)
        {
            tmp = tmp.getProx();
        }
        return tmp;
    }

     public void swap(int x, int y)
     {
        gameQ5 temp = encontrarCelula(x).getObj();
        encontrarCelula(x).setObj(encontrarCelula(y).getObj()) ;
        encontrarCelula(y).setObj(temp);
      }
     
      public boolean compararDate(gameQ5 primeiro, gameQ5 segundo)
     {
        int mesEmNum1 = 0;
        int mesEmNum2 = 0;
        boolean result = false;
        if (primeiro.getRelease_date().getAno() == segundo.getRelease_date().getAno()) {
            if (primeiro.getRelease_date().getMes().equals(segundo.getRelease_date().getMes()) == true) {
                if (primeiro.getRelease_date().getDia() >= segundo.getRelease_date().getDia()  ) {
                    result = true;
                }
                else
                {
                    result = false;
                }
            } else {
                if (primeiro.getRelease_date().getMes().equals("Jan")) {
                    mesEmNum1 = 1;
                } 
                else if (primeiro.getRelease_date().getMes().equals("Feb")) {
                    mesEmNum1 = 2;
                }
                else if (primeiro.getRelease_date().getMes().equals("Mar")) {
                    mesEmNum1 = 3;
                } 
                else if (primeiro.getRelease_date().getMes().equals("Apr")) {
                    mesEmNum1 = 4;
                } 
                else if (primeiro.getRelease_date().getMes().equals("May")) {
                    mesEmNum1 = 5;
                } 
                else if (primeiro.getRelease_date().getMes().equals("Jun")) {
                    mesEmNum1 = 6;
                } 
                else if (primeiro.getRelease_date().getMes().equals("Jul")) {
                    mesEmNum1 = 7;
                } 
                else if (primeiro.getRelease_date().getMes().equals("Aug")) {
                    mesEmNum1 = 8;
                } 
                else if (primeiro.getRelease_date().getMes().equals("Sep")) {
                    mesEmNum1 = 9;
                } 
                else if (primeiro.getRelease_date().getMes().equals("Oct")) {
                    mesEmNum1 = 10;
                } 
                else if (primeiro.getRelease_date().getMes().equals("Nov")) {
                    mesEmNum1 = 11;
                } 
                else if (primeiro.getRelease_date().getMes().equals("Dec")) {
                    mesEmNum1 = 12;
                } 

                if (segundo.getRelease_date().getMes().equals("Jan")) {
                    mesEmNum2 = 1;
                } 
                else if (segundo.getRelease_date().getMes().equals("Feb")) {
                    mesEmNum2 = 2;
                }
                else if (segundo.getRelease_date().getMes().equals("Mar")) {
                    mesEmNum2 = 3;
                } 
                else if (segundo.getRelease_date().getMes().equals("Apr")) {
                    mesEmNum2 = 4;
                } 
                else if (segundo.getRelease_date().getMes().equals("May")) {
                    mesEmNum2 = 5;
                } 
                else if (segundo.getRelease_date().getMes().equals("Jun")) {
                    mesEmNum2 = 6;
                } 
                else if (segundo.getRelease_date().getMes().equals("Jul")) {
                    mesEmNum2 = 7;
                } 
                else if (segundo.getRelease_date().getMes().equals("Aug")) {
                    mesEmNum2 = 8;
                } 
                else if (segundo.getRelease_date().getMes().equals("Sep")) {
                    mesEmNum2 = 9;
                } 
                else if (segundo.getRelease_date().getMes().equals("Oct")) {
                    mesEmNum2 = 10;
                } 
                else if (segundo.getRelease_date().getMes().equals("Nov")) {
                    mesEmNum2 = 11;
                } 
                else if (segundo.getRelease_date().getMes().equals("Dec")) {
                    mesEmNum2 = 12;
                }

                if (mesEmNum1 > mesEmNum2) {
                    result = true;
                } else {
                    result = false;
                }

            }

        }
        else
        {
            if (primeiro.getRelease_date().getAno() > segundo.getRelease_date().getAno() ) {
                result = true;
            }
            else
            {
                result = false;
            }
        }

        return result;
     }


    void imprimirLista() {
        Celula tmp = primeiro;
       
        for (; tmp != null; tmp = tmp.getProx()) {
            System.out.println(tmp.getObj().getJogo() );
        }
    }

    gameQ5 lerId(int id) throws Exception {
        gameQ5 GAME = new gameQ5();
        String aux = "";
        int j = 0;
        String aux2 = "1";
        BufferedReader arq = new BufferedReader(new FileReader("/tmp/games.csv"));

        while (Integer.parseInt(aux2) != id) {
            aux2 = "";
            j = 0;
            aux = arq.readLine();
            while (aux.charAt(j) != ',') {
                aux2 = aux2 + aux.charAt(j);
                j++;
            }
        }

        arq.close();
        GAME.ler(aux);
        GAME.fixStringsParse();
        GAME.imprimir();
        return GAME;
    }

    public Celula getPrimeiro() {
        return primeiro;
    }

    public void setPrimeiro(Celula primeiro) {
        this.primeiro = primeiro;
    }

    public Celula getUltimo() {
        return ultimo;
    }

    public void setUltimo(Celula ultimo) {
        this.ultimo = ultimo;
    }

    public int getTamanho() {
        return tamanho;
    }

    public void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    public int getComparacoes() {
        return comparacoes;
    }

    public void setComparacoes(int comparacoes) {
        this.comparacoes = comparacoes;
    }

    public int getMovimentacoes() {
        return movimentacoes;
    }

    public void setMovimentacoes(int movimentacoes) {
        this.movimentacoes = movimentacoes;
    }

}

public class gameQ5 {

    private int app_id;
    private String Name;
    private Data release_date;
    private String owners;
    private int age;
    private float price;
    private int dlcs;
    private String[] languages;
    private boolean windows;
    private String website;
    private boolean mac;
    private boolean linux;
    private float upvotes;
    private int avg_pt;
    private String developers;
    private String[] genres;
    private String[] ArrayDeStringAux = new String[17];
    private String Jogo;

    public int getApp_id() {
        return app_id;
    }

    public void setApp_id(int app_id) {
        this.app_id = app_id;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public Data getRelease_date() {
        return release_date;
    }

    public void setRelease_date(Data release_date) {
        this.release_date = release_date;
    }

    public String getOwners() {
        return owners;
    }

    public void setOwners(String owners) {
        this.owners = owners;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public float getPrice() {
        return price;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public int getDlcs() {
        return dlcs;
    }

    public void setDlcs(int dlcs) {
        this.dlcs = dlcs;
    }

    public String[] getLanguages() {
        return languages;
    }

    public void setLanguages(String[] languages) {
        this.languages = languages;
    }

    public String getWebsite() {
        return website;
    }

    public void setWebsite(String website) {
        this.website = website;
    }

    public boolean isWindows() {
        return windows;
    }

    public void setWindows(boolean windows) {
        this.windows = windows;
    }

    public boolean isMac() {
        return mac;
    }

    public void setMac(boolean mac) {
        this.mac = mac;
    }

    public boolean isLinux() {
        return linux;
    }

    public void setLinux(boolean linux) {
        this.linux = linux;
    }

    public float getUpvotes() {
        return upvotes;
    }

    public void setUpvotes(float upvotes) {
        this.upvotes = upvotes;
    }

    public int getAvg_pt() {
        return avg_pt;
    }

    public void setAvg_pt(int avg_pt) {
        this.avg_pt = avg_pt;
    }

    public String getDevelopers() {
        return developers;
    }

    public void setDevelopers(String developers) {
        this.developers = developers;
    }

    public String[] getGenres() {
        return genres;
    }

    public void setGenres(String[] genres) {
        this.genres = genres;
    }

    public String[] getArrayDeStringAux() {
        return ArrayDeStringAux;
    }

    public void setArrayDeStringAux(String[] arrayDeStringAux) {
        ArrayDeStringAux = arrayDeStringAux;
    }

    public String getJogo() {
        return Jogo;
    }

    public void setJogo(String jogo) {
        Jogo = jogo;
    }

    gameQ5() {

    }

    public gameQ5(int app_id, String name, Data release_date, String owners, int age, float price, int dlcs,
            String[] languages, boolean windows, String website, boolean mac, boolean linux, float upvotes, int avg_pt,
            String developers, String[] genres, String[] arrayDeStringAux, String jogo) {
        this.app_id = app_id;
        Name = name;
        this.release_date = release_date;
        this.owners = owners;
        this.age = age;
        this.price = price;
        this.dlcs = dlcs;
        this.languages = languages;
        this.windows = windows;
        this.website = website;
        this.mac = mac;
        this.linux = linux;
        this.upvotes = upvotes;
        this.avg_pt = avg_pt;
        this.developers = developers;
        this.genres = genres;
        ArrayDeStringAux = arrayDeStringAux;
        Jogo = jogo;

    }

    void fixStringsParse() {
        int i = 0;
        int j = 0;
        int aux = 0;
        String languages = "";
        String mes = "";
        String dia = "", ano = "";
        int countVirg = 0;
        String genres = "";

        for (int k = 0; k < ArrayDeStringAux.length; k++) {
            if (ArrayDeStringAux[k] == "") {
                ArrayDeStringAux[k] = null;
            }
        }

        if (ArrayDeStringAux[16] == null) {
            ArrayDeStringAux[16] = "";
        }

        this.app_id = Integer.parseInt(ArrayDeStringAux[0]);
        this.Name = ArrayDeStringAux[1];

        int k = 0;
        int contador = 0;
        for (int k2 = 0; k2 < ArrayDeStringAux[2].length(); k2++) {
            if (ArrayDeStringAux[2].charAt(k2) == ',') {
                contador++;
            }
        }

        if (contador == 1) {
            for (k = 0; k <= 2; k++) {
                mes = mes + ArrayDeStringAux[2].charAt(k);
            }
            k = 4;

            while (ArrayDeStringAux[2].charAt(k) != ',') {
                dia = dia + ArrayDeStringAux[2].charAt(k);
                k++;
            }

            for (k = k + 2; k < ArrayDeStringAux[2].length(); k++) {
                ano = ano + ArrayDeStringAux[2].charAt(k);

            }
        } else {
            for (k = 0; k <= 2; k++) {
                mes = mes + ArrayDeStringAux[2].charAt(k);
            }
            for (k = k + 2; k < ArrayDeStringAux[2].length(); k++) {
                ano = ano + ArrayDeStringAux[2].charAt(k);
            }
            dia = null;
        }

        if (dia != null) {
            this.release_date = new Data(Integer.parseInt(dia), mes, Integer.parseInt(ano));
        } else {
            this.release_date = new Data(0, mes, Integer.parseInt(ano));
        }

        this.owners = ArrayDeStringAux[3];
        this.age = Integer.parseInt(ArrayDeStringAux[4]);
        this.price = Float.parseFloat(ArrayDeStringAux[5]);
        this.dlcs = Integer.parseInt(ArrayDeStringAux[6]);

        while (ArrayDeStringAux[7].charAt(i) != ']') {
            if (ArrayDeStringAux[7].charAt(i) == ',') {
                countVirg++;
            }
            i++;
        }

        this.languages = new String[countVirg + 1];
        i = 1;

        while (ArrayDeStringAux[7].charAt(i) != ']') {

            if (ArrayDeStringAux[7].charAt(i) == '\'') {
                i++;
                aux++;
            } else if (ArrayDeStringAux[7].charAt(i) == ',' || ArrayDeStringAux[7].charAt(i) == ' ') {
                i++;
            } else if (ArrayDeStringAux[7].charAt(i) == '-') {
                languages = languages + " ";
                languages = languages + ArrayDeStringAux[7].charAt(i);
                languages = languages + " ";
                i++;
            } else {
                languages = languages + ArrayDeStringAux[7].charAt(i);
                i++;
            }

            if (aux % 2 == 0 && aux != 0 && ArrayDeStringAux[7].charAt(i) != ',' && ArrayDeStringAux[7].charAt(i) != ' '
                    && ArrayDeStringAux[7].charAt(i) == '\'' || ArrayDeStringAux[7].charAt(i) == ']') {

                this.languages[j] = languages;
                languages = "";
                j++;
            }

        }

        this.website = ArrayDeStringAux[8];
        this.windows = Boolean.parseBoolean(ArrayDeStringAux[9]);
        this.mac = Boolean.parseBoolean(ArrayDeStringAux[10]);
        this.linux = Boolean.parseBoolean(ArrayDeStringAux[11]);
        this.upvotes = Float.parseFloat(ArrayDeStringAux[12])
                / ((Float.parseFloat(ArrayDeStringAux[12]) + Float.parseFloat(ArrayDeStringAux[13]))) * 100;
        this.avg_pt = Integer.parseInt(ArrayDeStringAux[14]);
        this.developers = ArrayDeStringAux[15];

        countVirg = 0;
        i = 0;
        while (i < ArrayDeStringAux[16].length()) {

            if (ArrayDeStringAux[16].charAt(i) == ',') {
                countVirg++;
            }
            i++;
        }

        this.genres = new String[countVirg + 1];
        i = 0;
        j = 0;
        if (countVirg == 0) {
            this.genres[0] = ArrayDeStringAux[16];
        } else {
            while (i < ArrayDeStringAux[16].length()) {

                if (ArrayDeStringAux[16].charAt(i) == ',') {
                    this.genres[j] = genres;
                    genres = "";
                    j++;
                } else if (i == ArrayDeStringAux[16].length() - 1) {
                    genres = genres + ArrayDeStringAux[16].charAt(i);
                    this.genres[j] = genres;
                    genres = "";
                    j++;
                } else {
                    genres = genres + ArrayDeStringAux[16].charAt(i);
                }
                i++;
            }

        }

    }

    void imprimir() {
        float aux = 0;
        float aux2 = 0;
        int aux3 = 0;
        int aux4 = 0;
        this.Jogo = app_id + " " + Name + " " + release_date.getMes() + "/" + release_date.getAno() + " "
                + owners + " "
                + age + " " + price + " " + dlcs + " [";

        for (int i = 0; i < languages.length - 1; i++) {
            Jogo = Jogo + languages[i] + ", ";
        }
        Jogo = Jogo + languages[languages.length - 1] + "]" + " " + website + " " + windows + " " + mac + " " + linux;

        if (upvotes - (int) (upvotes) > 0.5) {
            Jogo = Jogo + " " + (int) (upvotes + 1) + "% ";
        } else {
            Jogo = Jogo + " " + (int) (upvotes) + "% ";
        }

        if (avg_pt == 0) {
            Jogo = Jogo + "null ";
        } else {
            aux2 = avg_pt;
            aux = aux2 / 60;
            aux3 = (int) aux;

            if (((aux - aux3) * 60) > 30) {
                aux4 = 1 + ((int) ((aux - aux3) * 60));
            } else {
                aux4 = (int) ((aux - aux3) * 60);
            }

            if (aux3 > 0 && aux4 > 0) {
                Jogo = Jogo + aux3 + "h " + aux4 + "m ";
            }

            if (aux3 <= 0 && aux4 > 0) {
                Jogo = Jogo + aux4 + "m ";

            }

            if (aux3 > 0 && aux4 <= 0) {
                Jogo = Jogo + aux3 + "h ";

            }
        }

        Jogo = Jogo + developers + " [";

        for (int i = 0; i < genres.length - 1; i++) {
            Jogo = Jogo + genres[i] + ", ";
        }
        Jogo = Jogo + genres[genres.length - 1] + "]";

    }

    void ler(String Frase) {
        int i = 0;
        int k = 0;
        this.ArrayDeStringAux[0] = "";
        while (i < Frase.length()) {

            if (Frase.charAt(i) == ',') {

                k++;
                this.ArrayDeStringAux[k] = "";
            } else {
                if (Frase.charAt(i) == '\"') {
                    i++;
                    while (Frase.charAt(i) != '\"') {
                        this.ArrayDeStringAux[k] = this.ArrayDeStringAux[k] + Frase.charAt(i);
                        i++;
                    }

                } else {
                    this.ArrayDeStringAux[k] = this.ArrayDeStringAux[k] + Frase.charAt(i);
                }

            }
            i++;
        }

    }

    static boolean isFim(String palavra) {
        boolean result = false;
        if (palavra.charAt(0) == 'F' && palavra.charAt(1) == 'I' && palavra.charAt(2) == 'M')
            result = true;
        return result;
    }

    public static void main(String[] args) throws Exception {

        String id;
        String aux = "";
        lista LISTA = new lista();

        int j = 0;
        String aux2 = "1";

        id = MyIO.readLine();
        BufferedReader arq = new BufferedReader(new FileReader("/tmp/games.csv"));

        while (isFim(id) == false) {
            gameQ5 GAME = new gameQ5();

            arq = new BufferedReader(new FileReader("/tmp/games.csv"));

            while (Integer.parseInt(aux2) != Integer.parseInt(id)) {
                aux2 = "";
                j = 0;
                aux = arq.readLine();
                while (aux.charAt(j) != ',') {
                    aux2 = aux2 + aux.charAt(j);
                    j++;
                }
            }

            GAME.ler(aux);
            GAME.fixStringsParse();
            GAME.imprimir();

            LISTA.inserirFim(GAME);

            aux2 = "1";
            arq.close();
            id = MyIO.readLine();
        }

        LISTA.ordernarLista(0, LISTA.getTamanho() -1);
        LISTA.imprimirLista();
    }

}
