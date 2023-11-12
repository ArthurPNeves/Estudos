
class arv {
    teste raiz;

    void inserir(String elemento) {
        inserir(elemento, raiz, 0);
    }

    void inserir(String elemento, teste i, int x) {

        if (i.prox[elemento.charAt(x)] == null) {
            if (x < elemento.length() - 1) {
                i.prox[elemento.charAt(x)] = new teste(null, elemento.charAt(x), false);
            }
            else if(x == elemento.length() - 1)
            {
                i.prox[elemento.charAt(x)].folha = true;
            }
            else{
                inserir(elemento, i.prox[elemento.charAt(x)], (x + 1));
            }

        } else {
            if (x < elemento.length() - 1) {
                inserir(elemento, i.prox[elemento.charAt(x)], (x + 1));
            }
            else if(x == elemento.length() - 1)
            {
                i.prox[elemento.charAt(x)].folha = true;
            }


        }

    }

    private void inserir(String s, No no, int i) throws Exception {
        System.out.print("\nEM NO(" + no.elemento + ") (" + i + ")");
        if(no.prox[s.charAt(i)] == null){
            System.out.print("--> criando filho(" + s.charAt(i) + ")");
            no.prox[s.charAt(i)] = new No(s.charAt(i));

            if(i == s.length() - 1){
                System.out.print("(folha)");
                no.prox[s.charAt(i)].folha = true;
            }else{
                inserir(s, no.prox[s.charAt(i)], i + 1);
            }

        } else if (i < s.length() - 1){
            inserir(s, no.prox[s.charAt(i)], i + 1);

        } else if(i == s.length() - 1){
            System.out.print("(folha)");
            no.prox[s.charAt(i)].folha = true;
        } 
    }


}

public class teste {
    public teste[] prox;
    public char elemento;
    public boolean folha;
    final public int tamanho = 250;

    public teste[] getProx() {
        return prox;
    }

    public void setProx(teste[] prox) {
        this.prox = prox;
    }

    public char getElemento() {
        return elemento;
    }

    public void setElemento(char elemento) {
        this.elemento = elemento;
    }

    public boolean isFolha() {
        return folha;
    }

    public void setFolha(boolean folha) {
        this.folha = folha;
    }

    public int getTamanho() {
        return tamanho;
    }

    public teste(teste[] prox, char elemento, boolean folha) {
        this.prox = prox;
        this.elemento = elemento;
        this.folha = folha;
    }

    public teste() {
    }

}
