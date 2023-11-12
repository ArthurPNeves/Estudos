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
    
    public void inserir(char letra)
    {
        raiz = inserir(raiz, letra);
    }
    public NO inserir(NO i, char letra)
    {
        if (i == null) {
            i = new NO(letra, null, null);
        }
        else if(letra > i.letra)
        {
            i.dir = inserir(i.dir, letra);
        }
        else if(letra < i.letra)
        {
            i.esq=  inserir(i.esq, letra);
        }
        else
        {
            System.out.println("erro");
        }
        return i;
    }

    public boolean pesquisar(char letra){
        NO tmp = raiz;
        while (tmp != null && tmp.letra != letra) {
            if (tmp.letra > letra) {
                tmp = tmp.esq;
            }
            else if(tmp.letra < letra)
            {
                tmp = tmp.dir;
            }
        }
        if (tmp == null) {
            return false;
        } else {
            return true;
        }
    }
    

    public void in()
    {
         in(raiz);
    }

    public void in(NO i)
    {
        if (i != null) {
           in(i.esq);
            System.out.print(i.letra + " ");
            in(i.dir);
        }
    }

    public void pre()
    {
        
        pre(raiz);
    }

    public void pre(NO i)
    {
        if (i != null) {
            System.out.print((i.letra + " "));
            pre(i.esq);
            pre(i.dir);
            
            
        }
    }
    
    public void pos()
    {
       
        pos(raiz);
    }

    public void pos(NO i)
    {
        if (i != null) {
            
            pos(i.esq);
            pos(i.dir);
            System.out.print((i.letra + " "));
            
        }
    }
}

class NO {
char letra;
NO dir;
NO esq;
public int getletra() {
    return letra;
}
public void setletra(char letra) {
    this.letra = letra;
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
public NO(char letra, NO dir, NO esq) {
    this.letra = letra;
    this.dir = dir;
    this.esq = esq;
}
public NO() {
}
    
}

public class tpQ9 {
    static public void fazerAcoes(String s1, ARV arv)
    {
        if(s1.compareTo("INFIXA") == 0)
        {
            
            arv.in();
            System.out.println();
        }
        else if(s1.compareTo("PREFIXA") == 0)
        {
           
            arv.pre();  
            System.out.println();
        }
        else if(s1.compareTo("POSFIXA") == 0)
        {
            
            arv.pos();
            System.out.println();
        }
        else if(s1.charAt(0) == 'I')
        {
            
            arv.inserir(s1.charAt(2));
        }
        else if(s1.charAt(0) == 'P')
        {
            
           Boolean result =  arv.pesquisar(s1.charAt(2));
           if (result) {
            System.out.print(s1.charAt(2) + " existe");
            System.out.println();
           }
           else
           {
            System.out.print("nao existe");
            System.out.println();
           }
        }
        else{
            
        }
        

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
       String s1;
        
       ARV arv = new ARV();
       while (sc.hasNext()) {
        
        s1 = sc.nextLine();

        fazerAcoes(s1, arv);
 

       }

        
        sc.close();
    } 
}

//