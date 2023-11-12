public class no {
    boolean cor;
    no dir , esq;
    int elemento;
    
    public no(boolean cor, no dir, no esq, int elemento) {
        this.cor = cor;
        this.dir = dir;
        this.esq = esq;
        this.elemento = elemento;
    }

    
    public no() {
    }


    public boolean isCor() {
        return cor;
    }
    public void setCor(boolean cor) {
        this.cor = cor;
    }
    public no getDir() {
        return dir;
    }
    public void setDir(no dir) {
        this.dir = dir;
    }
    public no getEsq() {
        return esq;
    }
    public void setEsq(no esq) {
        this.esq = esq;
    }
    public int getElemento() {
        return elemento;
    }
    public void setElemento(int elemento) {
        this.elemento = elemento;
    }
    
}
