import java.io.BufferedReader;

import java.io.FileReader;
import java.util.Scanner;

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

class No {
    public gameQ5 obj;
    public No esq, dir;
    boolean cor;


    public gameQ5 getObj() {
        return obj;
    }

    public void setObj(gameQ5 obj) {
        this.obj = obj;
    }

    public No getEsq() {
        return esq;
    }

    public void setEsq(No esq) {
        this.esq = esq;
    }

    public No getDir() {
        return dir;
    }

    public void setDir(No dir) {
        this.dir = dir;
    }



  public No(gameQ5 elemento) {
    this(elemento, false, null, null);
  }

  public No(gameQ5 elemento, boolean cor) {
    this(elemento, cor, null, null);
  }

  public No(gameQ5 elemento, boolean cor, No esq, No dir) {
    this.cor = cor;
    this.obj = elemento;
    this.esq = esq;
    this.dir = dir;
  }
}

class Arvore {
    No raiz;

    public Arvore() {
    }

    public Arvore(No raiz) {
        this.raiz = raiz;
    }

    static boolean isFim(String palavra) {
        boolean result = false;
        if (palavra.charAt(0) == 'F' && palavra.charAt(1) == 'I' && palavra.charAt(2) == 'M')
            result = true;
        return result;
    }

    void fazerAcoes() throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = MyIO.readInt();
        String s1 = "";
        for (int i = 0; i < n; i++) {
            s1 = MyIO.readLine();
            
            if (s1.charAt(0) == 'I') {
                String s2 = "";
                for (int j = 2; j < s1.length(); j++) {
                    s2 = s2 + s1.charAt(j);
                }
                inserir(lerId(Integer.parseInt(s2)));
                /* 
            } else if (s1.charAt(0) == 'R') {
                
                String s2 = "";
                for (int j = 2; j < s1.length(); j++) {
                    s2 = s2 + s1.charAt(j);
                }
                remover(lerNome(s2));
            
            */
        }
        }

        s1 = MyIO.readLine();
        while (isFim(s1) == false) {
            pesquisar(s1);
            s1 = MyIO.readLine();
        }
       sc.close();
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

    public void inserir(gameQ5 elemento) throws Exception {
        // Se a arvore estiver vazia
        if (raiz == null) {
           raiz = new No(elemento);
           
  
        // Senao, se a arvore tiver um elemento
        } else if (raiz.esq == null && raiz.dir == null) {
           if (  raiz.obj.getName().compareTo(elemento.getName()) > 0) {
              raiz.esq = new No(elemento);
             
           } else {
              raiz.dir = new No(elemento);
             
           }
  
        // Senao, se a arvore tiver dois elementos (raiz e dir)
        } else if (raiz.esq == null) {
           if ( raiz.obj.getName().compareTo(elemento.getName()) > 0) {
              raiz.esq = new No(elemento);
              
  
           } else if ( raiz.dir.obj.getName().compareTo(elemento.getName()) > 0) {
              raiz.esq = new No(raiz.obj);
              raiz.obj = elemento;
             
  
           } else {
              raiz.esq = new No(raiz.obj);
              raiz.obj = raiz.dir.obj;
              raiz.dir.obj = elemento;
             
           }
           raiz.esq.cor = raiz.dir.cor = false;
  
        // Senao, se a arvore tiver dois elementos (raiz e esq)
        } else if (raiz.dir == null) {
           if (raiz.obj.getName().compareTo(elemento.getName()) < 0) {
              raiz.dir = new No(elemento);
              
  
           } else if (raiz.esq.obj.getName().compareTo(elemento.getName()) < 0) {
              raiz.dir = new No(raiz.obj);
              raiz.obj = elemento;
  
           } else {
              raiz.dir = new No(raiz.obj);
              raiz.obj = raiz.esq.obj;
              raiz.esq.obj = elemento;
           }
           raiz.esq.cor = raiz.dir.cor = false;
  
        // Senao, a arvore tem tres ou mais elementos
        } else {
           inserir(elemento, null, null, null, raiz);
        }
        raiz.cor = false;
     }
  
     private void balancear(No bisavo, No avo, No pai, No i) {
        // Se o pai tambem e preto, reequilibrar a arvore, rotacionando o avo
        if (pai.cor == true) {
           // 4 tipos de reequilibrios e acoplamento
           if (pai.obj.getName().compareTo(avo.obj.getName()) > 0) { // rotacao a esquerda ou direita-esquerda
              if (i.obj.getName().compareTo(pai.obj.getName()) > 0) {
                 avo = rotacaoEsq(avo);
              } else {
                 avo = rotacaoDirEsq(avo);
              }
           } else { // rotacao a direita ou esquerda-direita
              if (i.obj.getName().compareTo(pai.obj.getName()) < 0) {
                 avo = rotacaoDir(avo);
              } else {
                 avo = rotacaoEsqDir(avo);
              }
           }
           if (bisavo == null) {
              raiz = avo;
           } else if (bisavo.obj.getName().compareTo(avo.obj.getName()) > 0) {
              bisavo.esq = avo;
           } else {
              bisavo.dir = avo;
           }
           // reestabelecer as cores apos a rotacao
           avo.cor = false;
           avo.esq.cor = avo.dir.cor = true;

        } // if(pai.cor == true)
     }
  
     /**
      * Metodo privado recursivo para inserir elemento.
      * 
      * @param elemento Elemento a ser inserido.
      * @param avo      No em analise.
      * @param pai      No em analise.
      * @param i        No em analise.
      * @throws Exception Se o elemento existir.
      */
     private void inserir(gameQ5 elemento, No bisavo, No avo, No pai, No i) throws Exception {
        if (i == null) {
           if (pai.obj.getName().compareTo(elemento.getName()) > 0) {
              i = pai.esq = new No(elemento, true);
           } else {
              i = pai.dir = new No(elemento, true);
           }
           if (pai.cor == true) {
              balancear(bisavo, avo, pai, i);
           }
        } else {
           // Achou um 4-no: eh preciso fragmeta-lo e reequilibrar a arvore
           if (i.esq != null && i.dir != null && i.esq.cor == true && i.dir.cor == true) {
              i.cor = true;
              i.esq.cor = i.dir.cor = false;
              if (i == raiz) {
                 i.cor = false;
              } else if (pai.cor == true) {
                 balancear(bisavo, avo, pai, i);
              }
           }
           if (i.obj.getName().compareTo(elemento.getName()) > 0) {
              inserir(elemento, avo, pai, i, i.esq);
           } else if (i.obj.getName().compareTo(elemento.getName()) < 0) {
              inserir(elemento, avo, pai, i, i.dir);
           } else {
              throw new Exception("Erro inserir (elemento repetido)!");
           }
        }
     }
  
     private No rotacaoDir(No no) {

        No noEsq = no.esq;
        No noEsqDir = noEsq.dir;
  
        noEsq.dir = no;
        no.esq = noEsqDir;
  
        return noEsq;
     }
  
     private No rotacaoEsq(No no) {
    
        No noDir = no.dir;
        No noDirEsq = noDir.esq;
  
        noDir.esq = no;
        no.dir = noDirEsq;
        return noDir;
     }
  
     private No rotacaoDirEsq(No no) {
        no.dir = rotacaoDir(no.dir);
        return rotacaoEsq(no);
     }
  
     private No rotacaoEsqDir(No no) {
        no.esq = rotacaoEsq(no.esq);
        return rotacaoDir(no);
     }

    public void in()
    {
        System.out.println();
         in(raiz);
         System.out.println();
    }

    public void in(No i)
    {
        if (i != null) {
           in(i.getEsq());
            System.out.print(i.getObj().getName() + " ");
            in(i.getDir());
        }


    }
    /* 
    void remover(gameQ5 game) throws Exception {
        raiz = remover(game, raiz);
    }

    No remover(gameQ5 game, No i) throws Exception {
        if (i == null) {
            throw new Exception("Erro!");
        } else if ( i.getObj().getName().compareTo(game.getName()) > 0) {
            i.setEsq(remover(game, i.getEsq()));
        } else if (i.getObj().getName().compareTo(game.getName()) < 0) {
            i.setDir(remover(game, i.getDir()));
        } else if (i.getDir() == null) {
            i = i.getEsq();
        } else if (i.getEsq() == null) {
            i = i.getDir();
        } else {
            i.setEsq(maiorEsq(i, i.getEsq()));
        }
        return i;
    }
    
    No maiorEsq(No i, No j) {
        if (j.getDir() == null) {
            i.setObj(j.getObj());
            j = j.getEsq();
        } else {
            j.setDir(maiorEsq(i, j.getDir()));
        }
        return j;
    }
*/
    public boolean pesquisar(String nome) {
        No tmp = raiz;
        System.out.print(nome + "\nraiz ");

        while (tmp != null && tmp.getObj().getName().compareTo(nome) != 0) {
            if (tmp.getObj().getName().compareTo(nome) < 0) {
                System.out.print("dir ");
                tmp = tmp.getDir();
            } else if (tmp.getObj().getName().compareTo(nome) > 0) {
                System.out.print("esq ");
                tmp = tmp.getEsq();
            }
        }
        if (tmp == null) {
            System.out.println("NAO");
            return false;
        } else {
            System.out.println("SIM");
            return true;
        }
    }

    public gameQ5 lerNome(String nome) {
        No tmp = raiz;
        

        while (tmp != null && tmp.getObj().getName().compareTo(nome) != 0) {
          
            if (tmp.getObj().getName().compareTo(nome) < 0) {
                tmp = tmp.getDir();
            } else if (tmp.getObj().getName().compareTo(nome) > 0) {
                tmp = tmp.getEsq();
            }
        }

   

        if (tmp == null) {
            return null;
        } else {
            return tmp.getObj();
        }
    }

    public No getRaiz() {
        return raiz;
    }

    public void setRaiz(No raiz) {
        this.raiz = raiz;
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
        Arvore ARV = new Arvore();
        int x = 0;
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

            ARV.inserir(GAME);

            aux2 = "1";
            arq.close();
            id = MyIO.readLine();
            x++;
        }
       
        ARV.fazerAcoes();

    }

}
