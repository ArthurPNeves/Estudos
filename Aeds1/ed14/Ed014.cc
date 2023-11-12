#include "Contato.hpp"
using namespace std;


void method00 ( )
{
}
void method01 ( )
{

ref_Contato pessoa1 = new Contato ( "", "2", "" );
pessoa1->readNome("\nInsira o nome:\n");
if ( pessoa1 )
 cout << "pessoa1 - " << pessoa1->toString( ) << endl;
 else
 cout << "pessoa1 tem erro (" << pessoa1->getErro( ) << ")" << endl;
 // fim se
 pause ( "Apertar ENTER para continuar" );
}
void method02 ( )
{
ref_Contato pessoa1 = new Contato ( "", "", "" );
pessoa1->readNome("\nInsira o nome:\n");
pessoa1->readfone1("\nInsira o fone1:\n");
if ( pessoa1 )
 cout << "pessoa1 - " << pessoa1->toString( ) << endl;
 else
 cout << "pessoa1 tem erro (" << pessoa1->getErro( ) << ")" << endl;
 // fim se
 pause ( "Apertar ENTER para continuar" );
}
/**
 Method03 - Testar recuperacao de dados.
*/
void method03 ( )
{
ref_Contato pessoa1 = new Contato ( "", "", "" );
pessoa1->readNome("\nInsira o nome:\n");
pessoa1->readfone1("\nInsira o fone1:\n"); // teste da funcao inserido dentro do readfone1

if ( pessoa1 )
 cout << "pessoa1 - " << pessoa1->toString( ) << endl;
 else
 cout << "pessoa1 tem erro (" << pessoa1->getErro( ) << ")" << endl;
 pause ( "Apertar ENTER para continuar" );
}

void method04 ( )
{
ref_Contato pessoa1 = new Contato ( "", "", "" );
pessoa1->fromFile("Pessoa1.txt");
if ( pessoa1 )
cout << "pessoa1 - " << pessoa1->toString( ) << endl;
else
cout << "pessoa1 tem erro (" << pessoa1->getErro( ) << ")" << endl;
pause ( "Apertar ENTER para continuar" );
}

void method05 ( )
{
  ref_Contato pessoa1 = new Contato ( "", "", "" );
pessoa1->readNome("\nInsira o nome:\n");
pessoa1->readfone1("\nInsira o fone1:\n");
pessoa1->toFile("Pessoa1.txt");
if ( pessoa1 )
 cout << "pessoa1 - " << pessoa1->toString( ) << endl;
 else
 cout << "pessoa1 tem erro (" << pessoa1->getErro( ) << ")" << endl;
 pause ( "Apertar ENTER para continuar" );
}

void method06 ( )
{
ref_Contato pessoa1 = new Contato ( "", "", "" );
pessoa1->readNome("\nInsira o nome:\n");
pessoa1->readfone1("\nInsira o fone1:\n");
pessoa1->readfone2("\nInsira o fone2:\n"); 
pessoa1->toFile("Pessoa1.txt");
if ( pessoa1 )
 cout << "pessoa1 - " << pessoa1->toString( ) << endl;
 else
 cout << "pessoa1 tem erro (" << pessoa1->getErro( ) << ")" << endl;
 pause ( "Apertar ENTER para continuar" );
}

void method07 ( )
{
ref_Contato pessoa1 = new Contato ( "", "", "" );
pessoa1->readNome("\nInsira o nome:\n");
pessoa1->readfone1("\nInsira o fone1:\n");
pessoa1->readfone2("\nInsira o fone2:\n");

int n = pessoa1->telefones();
if ( pessoa1 )
 cout << "pessoa1 - " << pessoa1->toString( ) << " tem "<< n << " telefones"<< endl;
 else
 cout << "pessoa1 tem erro (" << pessoa1->getErro( ) << ")" << endl;
 pause ( "Apertar ENTER para continuar" );

}


void method08 ( )
{
ref_Contato pessoa1 = new Contato ( "", "", "" );
pessoa1->readNome("\nInsira o nome:\n");
pessoa1->readfone1("\nInsira o fone1:\n");
int n = pessoa1->telefones();
int novotelefone = 0;
if (n < 2)
{
  cout << "\nDeseja adicionar mais 1 telefone? Digite 1 para Sim e 2 Para Nao\n";
  cin >> novotelefone;
}
if (novotelefone == 1)
{
  pessoa1->readfone2("\nInsira o fone2:\n");
}


if ( pessoa1 )
 cout << "pessoa1 - " << pessoa1->toString( ) << " tem "<< n << " telefones"<< endl;
 else
 cout << "pessoa1 tem erro (" << pessoa1->getErro( ) << ")" << endl;
 pause ( "Apertar ENTER para continuar" );

}

void method09 ( )
{
ref_Contato pessoa1 = new Contato ( "", "", "" );
pessoa1->readNome("\nInsira o nome:\n");
pessoa1->readfone1("\nInsira o fone1:\n");
int n = pessoa1->telefones();

if (n < 2)
{
  pessoa1->setfone2("333-333");
}
// nao comprendi o exercicio
if ( pessoa1 )
 cout << "pessoa1 - " << pessoa1->toString( ) << " tem "<< n << " telefones"<< endl;
 else
 cout << "pessoa1 tem erro (" << pessoa1->getErro( ) << ")" << endl;
 pause ( "Apertar ENTER para continuar" );
} 

void method10 ( )
{
ref_Contato pessoa1 = new Contato ( "", "", "" );
pessoa1->readNome("\nInsira o nome:\n");
pessoa1->readfone1("\nInsira o fone1:\n");
int n = pessoa1->telefones();

if (n == 2)
{
  pessoa1->setfone2("");
}
// nao comprendi o exercicio
if ( pessoa1 )
 cout << "pessoa1 - " << pessoa1->toString( ) << " tem "<< n << " telefones"<< endl;
 else
 cout << "pessoa1 tem erro (" << pessoa1->getErro( ) << ")" << endl;
 pause ( "Apertar ENTER para continuar" );

 pause ( "Apertar ENTER para continuar" );
} 


int main(int argc, char **argv)
{

  int x = 0;
  do
  {
    cout << "ED13\n " << endl;
    // mostrar opcoes
    cout << "Opcoes " << endl;
    cout << " 0 - parar " << endl;
    cout << " 1 - ex1" << endl;
    cout << " 2 - ex2" << endl;
    cout << " 3 - ex3" << endl;
    cout << " 4 - ex4" << endl;
    cout << " 5 - ex5" << endl;
    cout << " 6 - ex6" << endl;
    cout << " 7 - ex7" << endl;
    cout << " 8 - ex8" << endl;
    cout << " 9 - ex9" << endl;
    cout << "10 - ex10" << endl;

    // ler do teclado
    cout << endl<< "Entrar com uma opcao: "; cin >> x;
    // escolher acao
    switch (x)
    {
    case 0:
      method00();
      break;
    case 1:
      method01();
      break;
    case 2:
      method02();
      break;
    case 3:
      method03();
      break;
    case 4:
      method04();
      break;
    case 5:
      method05();
      break;
    case 6:
      method06();
      break;
    case 7:
      method07();
      break;
    case 8:
      method08();
      break;
    case 9:
      method09();
      break;
    case 10:
      method10();
      break;
    default:
      cout << endl
      << "ERRO: Valor invalido." << endl;
    } // fim escolher
  } while (x != 0);
  // encerrar
  pause("Apertar ENTER para terminar");
  return (0);
} 
