import java.util.*;

class ARV {
NO raiz;

public NO getRaiz() {
    return raiz;
}

public void setRaiz(NO raiz) {
    this.raiz = raiz;
}

public ARV(NO raiz) {
    this.raiz = raiz;
}

public ARV() {
}
    
    public void inserir(int elemento)
    {
        raiz = inserir(raiz, elemento);
    }
    public NO inserir(NO i, int elemento)
    {
        if (i == null) {
            i = new NO(elemento, null, null);
        }
        else if(elemento > i.elemento)
        {
            i.dir = inserir(i.dir, elemento);
        }
        else if(elemento < i.elemento)
        {
            i.esq=  inserir(i.esq, elemento);
        }
        else
        {
            System.out.println("erro");
        }
        return i;
    }


    public void in()
    {
        System.out.print("In..:");
        in(raiz);
    }

    public void in(NO i)
    {
        if (i != null) {
           in(i.esq);
            System.out.print(" " + i.elemento);
            in(i.dir);
        }


    }

    public void pre()
    {
        System.out.print("Pre.:");
        pre(raiz);
    }

    public void pre(NO i)
    {
        if (i != null) {
            System.out.print(" " + i.elemento);
            pre(i.esq);
            pre(i.dir);
            
            
        }
    }
    
    public void pos()
    {
        System.out.print("Post:");
        pos(raiz);
    }

    public void pos(NO i)
    {
        if (i != null) {
            
            pos(i.esq);
            pos(i.dir);
            System.out.print(" " + i.elemento);
            
        }
    }
}

class NO {
int elemento;
NO dir;
NO esq;
public int getElemento() {
    return elemento;
}
public void setElemento(int elemento) {
    this.elemento = elemento;
}
public NO getDir() {
    return dir;
}
public void setDir(NO dir) {
    this.dir = dir;
}
public NO getEsq() {
    return esq;
}
public void setEsq(NO esq) {
    this.esq = esq;
}
public NO(int elemento, NO dir, NO esq) {
    this.elemento = elemento;
    this.dir = dir;
    this.esq = esq;
}
public NO() {
}
    
}

public class tp8 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c  = sc.nextInt();
        int n = 0;
        
        for (int i = 0; i < c; i++) {
            ARV arv = new ARV();
            n = sc.nextInt();
            System.out.println("Case " + (i+1) + ":");
            for (int j = 0; j < n; j++) {
                arv.inserir(sc.nextInt());
            }
            arv.pre();
            System.out.println();
            arv.in();
            System.out.println();
            arv.pos();
            System.out.println("\n");
        }
        sc.close();
    } 
}

//