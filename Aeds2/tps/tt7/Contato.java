
class No {
    private char letra;
    private No esq;
    private No dir;
    private celula primeiro;
    private celula ultimo;

    public char getLetra() {
        return letra;
    }

    public void setLetra(char letra) {
        this.letra = letra;
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

    public celula getPrimeiro() {
        return primeiro;
    }

    public void setPrimeiro(celula primeiro) {
        this.primeiro = primeiro;
    }

    public celula getUltimo() {
        return ultimo;
    }

    public void setUltimo(celula ultimo) {
        this.ultimo = ultimo;
    }

    public No clone()
    {
        No i = new No(this.letra, this.esq, this.dir, this.primeiro, this.ultimo);
        return i;
    }

    public No(char letra, No esq, No dir, celula primeiro, celula ultimo) {
        this.letra = letra;
        this.esq = esq;
        this.dir = dir;
        this.primeiro = primeiro;
        this.ultimo = ultimo;
    }

    public No() {
    }

    No(char letra) {
        this(letra, null, null, null, null);
    }

}

class celula {
    private Contato contato;
    private celula prox;

    public Contato getContato() {
        return contato;
    }

    public void setContato(Contato contato) {
        this.contato = contato;
    }

    public celula getProx() {
        return prox;
    }

    public void setProx(celula prox) {
        this.prox = prox;
    }

    public celula() {
    }

    public celula(Contato contato, celula prox) {
        this.contato = contato;
        this.prox = prox;
    }

}

public class Contato {
    private String nome;
    private String telefone;
    private String email;
    private int cpf;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public int getCpf() {
        return cpf;
    }

    public void setCpf(int cpf) {
        this.cpf = cpf;
    }

    public Contato(String nome, String telefone, String email, int cpf) {
        this.nome = nome;
        this.telefone = telefone;
        this.email = email;
        this.cpf = cpf;
    }

    public Contato() {
    }

}

class Agenda {
    private No raiz;

    public Agenda(No raiz) {
        this.raiz = raiz;
    }

    public Agenda() throws Exception {
        raiz = new No('M');
        inserir('F', raiz);
        inserir('T', raiz);
        inserir('C', raiz);
        inserir('I', raiz);
        inserir('P', raiz);
        inserir('W', raiz);
        inserir('A', raiz);
        inserir('B', raiz);
        inserir('D', raiz);
        inserir('E', raiz);
        inserir('G', raiz);
        inserir('H', raiz);
        inserir('J', raiz);
        inserir('K', raiz);
        inserir('L', raiz);
        inserir('N', raiz);
        inserir('O', raiz);
        inserir('Q', raiz);
        inserir('R', raiz);
        inserir('S', raiz);
        inserir('U', raiz);
        inserir('V', raiz);
        inserir('X', raiz);
        inserir('Y', raiz);
        inserir('Z', raiz);

    }

    Boolean pesquisarCpf(int cpf) {
        return pesquisarCpf(cpf, raiz);
    }

    boolean pesquisarCpf(int cpf, No i) {
        boolean result = false;
            if (i != null) {
                No tmp = new No();
                tmp = i.clone();
                while (tmp.getPrimeiro() != null) {
                    
                    if (tmp.getPrimeiro().getContato().getCpf() == cpf) {
                        result = true;
                        tmp.setPrimeiro(tmp.getPrimeiro().getProx());
                    } else {
                        tmp.setPrimeiro(tmp.getPrimeiro().getProx());
                    }
                }
                if (result == false) {  
                    result = pesquisarCpf(cpf, i.getEsq());
                }
                if (result == false) {                  
                    result = pesquisarCpf(cpf, i.getDir());
                }
            }
            
        return result;
    }

    Boolean pesquisarNome(String nome) {
        return pesquisarNome(nome, raiz);
    }

    Boolean pesquisarNome(String nome, No i) {
        boolean result = false;
        if (i == null) {
            result = false;
        } else if (i.getLetra() == nome.charAt(0)) {
            No noTmp = new No();
            noTmp = i;
            celula celTmp = new celula();

            for (celTmp = noTmp.getPrimeiro(); celTmp.getProx() != null; celTmp = celTmp.getProx()) {
                if (celTmp.getContato().getNome().equals(nome)) {
                    result = true;
                }

            }

        } else if (i.getLetra() > nome.charAt(0)) {
            result = pesquisarNome(nome, i.getEsq());
        } else {
            result = pesquisarNome(nome, i.getDir());
        }

        return result;
    }

    
      Boolean removerNome(String Nome) {
      return removerNome(Nome, raiz);
      }
      
      Boolean removerNome(String nome, No i) {
      boolean result = false;
      if (i == null) {
      result = false;
      } else if (i.getLetra() == nome.charAt(0)) {
      No noTmp = new No();
      noTmp = i;
      celula tmpPrimeiro = noTmp.getPrimeiro();
      for (; noTmp.getPrimeiro() != null;
      noTmp.setPrimeiro(noTmp.getPrimeiro().getProx())) {
        if (noTmp.getPrimeiro().getContato().getNome().equals(nome)) {
            noTmp.getPrimeiro().getContato().setNome("");
        }
      }
      i.setPrimeiro(tmpPrimeiro);

      } else if (i.getLetra() > nome.charAt(0)) {
      result = removerNome(nome, i.getEsq());
      } else {
      result = removerNome(nome, i.getDir());
      }
      return result;
      }
     

    void mostra(No i) {
        if (i != null) {
            mostra(i.getEsq());
            System.out.print(i.getLetra() + " ");
            System.out.print("[ ");

            for (celula k = i.getPrimeiro(); k != null; k = k.getProx()) {
                System.out.print(k.getContato().getNome() + " ");
            }

            System.out.println("] ");
            mostra(i.getDir());
        }
    }

    Boolean inserirContato(Contato contato) {
        return inserirContato(contato, raiz);
    }

    boolean inserirContato(Contato contato, No i) {
        boolean result;
        if (i == null) {
            result = false;
        } else if (i.getLetra() == contato.getNome().charAt(0)) {

            if (i.getPrimeiro() == null) {
                celula newcel = new celula(contato, null);
                i.setPrimeiro(newcel);
                i.setUltimo(newcel);
            } else {
                i.getUltimo().setProx(new celula(contato, null));
                i.setUltimo(i.getUltimo().getProx());
            }
            result = true;

        } else if (i.getLetra() > contato.getNome().charAt(0)) {

            result = inserirContato(contato, i.getEsq());
        } else {

            result = inserirContato(contato, i.getDir());
        }

        return result;
    }

    void inserir(char letra) throws Exception {
        raiz = inserir(letra, raiz);
    }

    No inserir(char letra, No i) throws Exception {
        if (i == null) {
            i = new No(letra);
        } else {
            if (letra > i.getLetra()) {
                i.setDir(inserir(letra, i.getDir()));
            } else if (letra < i.getLetra()) {
                i.setEsq(inserir(letra, i.getEsq()));
            } else {
                throw new Exception("Erro! Letra igual");
            }
        }
        return i;
    }

    public static void main(String[] args) throws Exception {
        Agenda AGD = new Agenda();
        Contato CNT1 = new Contato("Arthur", "984393006", "arthur.p.neves@", 021);
        Contato CNT2 = new Contato("Gabriel", "12", "gab", 012);
        Contato CNT3 = new Contato("ANACA", "984393006", "arthur.p.neves@", 022);
        Contato CNT4 = new Contato("ZNACA", "984393006", "arthur.p.neves@", 13);
        AGD.inserirContato(CNT1);
        AGD.inserirContato(CNT2);
        AGD.inserirContato(CNT3);
        AGD.inserirContato(CNT4);
        System.out.println(AGD.pesquisarNome("Arthur"));
        System.out.println(AGD.pesquisarCpf(13));
        AGD.mostra(AGD.raiz);
        System.out.println("\n\n");
        AGD.removerNome("ANACA");
        AGD.mostra(AGD.raiz);
    }

}
