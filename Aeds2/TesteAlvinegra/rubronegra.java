public class rubronegra {
    no raiz;

    void inserir()
    {

    }

    void remover()
    {

    }

    void pesquisar()
    {

    }

    void balancear ()
    {
        
    }

    no rotEsq(no no)
    {
        no NoDir = no.dir;
        no esqNodir = NoDir.esq;
        NoDir.esq = no;
        no.dir = esqNodir;
        return NoDir;
    }

    no rotDir(no no)
    {
        no NoEsq = no.esq;
        no dirNoEsq = NoEsq.dir;

        return NoEsq;
    }


    void rotEsqDir()
    {
        
    }


    void rotDirEsq()
    {
        
    }


}
