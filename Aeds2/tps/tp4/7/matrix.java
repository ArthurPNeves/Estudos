class Celula {
    Celula sup;
    Celula direita;
    Celula inf;
    Celula esquerda;
    int elemento;

    public Celula(int x) {
        sup = direita = inf = esquerda = null;
        elemento = x;
    }

    public Celula () {
        this(0);
    }
}

class Matrix {
    Celula inicio;

    public Matrix() {
        inicio = null;
    }

    public Matrix(int linhas, int colunas) {
        inicio = novaLinha(colunas);
        for (int i = 1; i < linhas; i++) {
            conectarLinha(novaLinha(colunas));
        }
    }

    private Celula novaLinha(int coluna) {
        Celula comeco = new Celula();
        Celula i = comeco;

        for(int j = 1; j < coluna; j++) {
            i.direita = new Celula();
            i.direita.esquerda = i;
            i = i.direita;
        }
        i = null;

        return comeco;
    }

    private void conectarLinha (Celula comeco) {
        Celula i;
        for (i = inicio; i.inf != null; i = i.inf);

        while (i != null && comeco != null) {
            i.inf = comeco;
            comeco.sup = i;

            i = i.direita;
            comeco = comeco.direita;
        }
        i = null;
    }

    public void mostrar() {
        Celula i = inicio;

        while(i != null) {
            for (Celula j = i; j != null; j = j.direita) {
                MyIO.print(j.elemento + " ");
            }
            MyIO.println("");
            i = i.inf;
        }
        i = null;
    }

    public void mostrarPrincipal () throws Exception {
        Celula i = inicio;

        if(nLinhas() != nColunas()) {
            throw new Exception("Matriz nao quadrada");
        }

        while (i != null) {
            MyIO.print(i.elemento + " ");
            i = i.direita;
            if (i != null) {
                i = i.inf;
            }
        }
        MyIO.println("");
        i = null;
    }

    public void mostrarSecundaria () throws Exception {
        Celula i = inicio;

        if (nLinhas() != nColunas()) {
            throw new Exception("Matriz nao quadrada");
        }
        for (; i.direita != null; i = i.direita);

        while (i != null) {
            MyIO.print(i.elemento + " ");
            i = i.esquerda;
            if (i != null) {
                i = i.inf;
            }
        }
        MyIO.println("");
        i = null;
    }

    private int nLinhas () {
        int n = 0;
        for (Celula i = inicio; i != null; i = i.direita, n++);

        return n;
    }

    private int nColunas() {
        int n = 0;
        for (Celula i = inicio; i != null; i = i.inf, n++);

        return n;
    }

    public void inserir (int x, int l, int c) throws Exception {
        if (l > nLinhas() || c > nColunas()) {
            throw new Exception("Posicao inexistente");
        }
        Celula tmp = inicio;
        for (int i = 0; i < l; i++, tmp = tmp.inf);
        for (int i = 0; i < c; i++, tmp = tmp.direita);

        tmp.elemento = x;
        tmp = null;
    }

    public Matrix somar (Matrix b) throws Exception {
        if (this.nLinhas() != b.nLinhas() || this.nColunas() != this.nColunas()) {
            throw new Exception("Matrizes de tamanhos diferentes");
        }

        Matrix resp = new Matrix(this.nLinhas(), this.nColunas());

        Celula a_linha, a_cel, b_linha, b_cel, resp_linha, resp_cel;

        a_linha = a_cel = this.inicio;
        b_linha = b_cel = b.inicio;
        resp_linha = resp_cel = resp.inicio;

        while (a_linha != null || b_linha != null || resp_linha != null) {
            while (a_cel != null || b_cel != null || resp_cel != null) {
                resp_cel.elemento = a_cel.elemento + b_cel.elemento;

                a_cel = a_cel.direita;
                b_cel = b_cel.direita;
                resp_cel = resp_cel.direita;
            }
            a_linha = a_cel = a_linha.inf;
            b_linha = b_cel = b_linha.inf;
            resp_linha = resp_cel = resp_linha.inf;
        }

        return resp;
    }

    private static int mult(Celula a, Celula b) {
        int resp = 0;

        while(a != null && b != null) {
            resp = resp + a.elemento * b.elemento;
            a = a.direita;
            b = b.inf;
        }

        return resp;
    }

    public Matrix multiplicar(Matrix b) throws Exception {
        if (this.nLinhas()!=b.nColunas()||this.nColunas()==0||b.nLinhas()==0||b.nColunas()==0) {
            throw new Exception("Matriz vazia");
        }
        Matrix resp = new Matrix (this.nLinhas(), b.nColunas());

        Celula a_linha, b_coluna, resp_linha, resp_cel;

        a_linha  = this.inicio;
        b_coluna = b.inicio;
        resp_linha = resp_cel = resp.inicio;

        while(resp_linha!=null) {
            while(resp_cel!=null) {
                resp_cel.elemento = mult(a_linha, b_coluna);
                resp_cel=resp_cel.direita;
                b_coluna=b_coluna.direita;
            }

            resp_linha=resp_cel=resp_linha.inf;
            b_coluna=b.inicio;
            a_linha=a_linha.inf;
        }

        return resp;
    }
}

public class matrix {
    public static void main (String[] args) throws Exception {
        int testes = MyIO.readInt();

        for (int i=0; i<testes; i++) {
            int linhas = MyIO.readInt();
            int colunas = MyIO.readInt();

            Matrix matriz1 = new Matrix(linhas, colunas);

            for (int l=0; l<linhas; l++) {
                for(int c=0; c<colunas; c++) {
                    matriz1.inserir(MyIO.readInt(), l, c);
                }
            }
            linhas = MyIO.readInt();
            colunas = MyIO.readInt();

            Matrix matriz2 = new Matrix(linhas, colunas);

            for (int l=0; l<linhas; l++) {
                for(int c=0; c<colunas; c++) {
                    matriz2.inserir(MyIO.readInt(), l, c);
                }
            }

            matriz1.mostrarPrincipal();
            matriz1.mostrarSecundaria();
            Matrix matriz3 = matriz1.somar(matriz2);
            matriz3.mostrar();
            matriz3 = matriz1.multiplicar(matriz2);
            matriz3.mostrar();
        }
    }
}