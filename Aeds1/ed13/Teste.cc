#include "Contato.hpp"
using namespace std;


void method00 ( )
{
}
void method01 ( )
{
 // definir dados
 Contato pessoa1;
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( );
// identificar
 cout << "\nEXEMPLO1301 - Method01 - v0.0\n" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
 
 // fim method01 ( 
}
void method02 ( )
{
 // definir dados
 Contato pessoa1;
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( );
// identificar
 cout << "\nEXEMPLO1302 - Method02 - v0.0\n" << endl;
// testar atribuicoes
 pessoa1.setNome ( "Pessoa_01" );
 pessoa1.setfone1 ( "111" );
 pessoa3->setNome ( "Pessoa_03" );
 pessoa3->setfone1 ( "333" );
 cout << "pessoa1 - { " << pessoa1.getNome ( ) << ", " << pessoa1.getfone1 ( ) << " }" << endl;
 cout << "pessoa3 - { " << pessoa3->getNome ( ) << ", " << pessoa3->getfone1 ( ) << " }" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
 // fim method02 ( 
}
/**
 Method03 - Testar recuperacao de dados.
*/
void method03 ( )
{
 // definir dados
 Contato pessoa1;
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( );
// identificar
 cout << "\nEXEMPLO1303 - Method03 - v0.0\n" << endl;
// testar atribuicoes
 pessoa1.setNome ( "Pessoa_01" );
 pessoa1.setfone1 ( "111" );
 pessoa3->setNome ( "Pessoa_03" );
 pessoa3->setfone1 ( "333" );
 cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
 cout << "pessoa3 - " << pessoa3->toString ( ) << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
 // fim method03 ( )
}
    /**
 Method04 - Testar construtor alternativo.
*/
void method04 ( )
{
  
 // definir dados
 Contato pessoa1 ( "Pessoa_01", "111", "" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "Pessoa_03", "333", "" );
// identificar
 cout << "\nEXEMPLO1304 - Method04 - v0.0\n" << endl;
// testar atribuicoes
 cout << "pessoa1 - " << pessoa1.toString ( ) << endl;
 cout << "pessoa3 - " << pessoa3->toString ( ) << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
 // fim method04 ( )
}
/**
 Method05 - Testar construtor alternativo.
*/
void method05 ( )
{
 // definir dados
 Contato pessoa1 ( "Pessoa_01", "111" , "" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "", "333", "" );
// identificar
 cout << "\nEXEMPLO1305 - Method05 - v0.0\n" << endl;
// testar atribuicoes
 cout << "pessoa1 - " << pessoa1.toString ( ) << " (" << pessoa1.getErro( ) << ")" << endl;
 cout << "pessoa3 - " << pessoa3->toString ( ) << " (" << pessoa3->getErro( ) << ")" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
 // fim method05 ( )
 
 }
/**
 Method06 - Testar construtor alternativo.
*/
void method06 ( )
{
 // definir dados
 Contato pessoa1 ( "Pessoa_01", "111", "" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "", "333", "" );
// identificar
 cout << "\nEXEMPLO1306 - Method06 - v0.0\n" << endl;
// testar atribuicoes
 if ( ! pessoa1.hasErro( ) )
 cout << "pessoa1 - " << pessoa1.toString( ) << endl;

 else
 cout << "pessoa1 tem erro (" << pessoa1.getErro( ) << ")" << endl;

 if ( ! pessoa3->hasErro( ) )
 cout << "pessoa3 - " << pessoa3->toString( ) << endl;

 else
 cout << "pessoa3 tem erro (" << pessoa3->getErro( ) << ")" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
 // fim method06 ( 
}
void method07 ( )
{
 // definir dados
 Contato pessoa1 ( "Pessoa_01", "111", "" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "", "333", "" );
// identificar
 cout << "\nEXEMPLO1307 - Method07 - v0.0\n" << endl;
// testar atribuicoes
 pessoa2 = &pessoa1; // copiar endereco de objeto
 if ( ! pessoa2->hasErro( ) )
 cout << "pessoa1 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa1 tem erro (" << pessoa2->getErro( ) << ")" << endl;
 pessoa2 = pessoa3; // vincular-se a outro objeto
 if ( ! pessoa2->hasErro( ) )
 cout << "pessoa3 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa3 tem erro (" << pessoa2->getErro( ) << ")" << endl;
// encerrar
 pause ( "Apertar ENTER para continuar" );
 // fim method07 ( )

}
/**
 Method08 - Testar atribuicoes e tratamento de erro.
*/

void method08 ( )
{
 // definir dados
 Contato pessoa1 ( "Pessoa_01", "111", "" );
 ref_Contato pessoa2 = nullptr;
 ref_Contato pessoa3 = new Contato ( "", "333", "" );
 ref_Contato pessoa4 = nullptr;
// identificar
 cout << "\nEXEMPLO1308 - Method08 - v0.0\n" << endl;
// testar atribuicoes
 pessoa2 = new Contato ( pessoa1 );
 if ( pessoa2 )
 cout << "pessoa2 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa2 tem erro (" << pessoa1.getErro( ) << ")" << endl;
 if ( pessoa3 ) // o teste de existencia deve ser feito previamente
 {
 pessoa2 = new Contato ( *pessoa3 );
 if ( pessoa2 )
 cout << "pessoa2 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa2 tem erro (" << pessoa3->getErro( ) << ")" << endl;
 // fim se
 if ( pessoa4 ) // o teste de existencia deve ser feito previamente
 {
 pessoa2 = new Contato ( *pessoa4 );
 if ( pessoa2 )
 cout << "pessoa2 - " << pessoa2->toString( ) << endl;
 else
 cout << "pessoa2 tem erro (" << pessoa4->getErro( ) << ")" << endl;
 // fim se
// encerrar
 pause ( "Apertar ENTER para continuar" );
 // fim method08 ( )
}
}
}
/**
 Method09 - Testar arranjo de objetos (1).
*/

void method09 ( )
{
// definir dados
 Contato pessoa [ 3 ];
 int x = 0;
// identificar
 cout << "\nEXEMPLO1309 - Method09 - v0.0\n" << endl;
// testar atribuicoes
 pessoa [ 0 ].setNome ( "Pessoa_1" );
 pessoa [ 0 ].setfone1 ( "111" );
 pessoa [ 1 ].setNome ( "Pessoa_2" );
 pessoa [ 1 ].setfone1 ( "222" );
 pessoa [ 2 ].setNome ( "Pessoa_3" );
 pessoa [ 2 ].setfone1 ( "333" );
 for ( x=0; x < 3; x=x+1 )
 {
 cout << x << " : " << pessoa[ x ].toString( ) << endl;
 } // fim repetir
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
 Method10 - Testar arranjo de referencias para objetos (2).
*/
void method10 ( )
{
// definir dados
 Contato *pessoa [ 3 ];
 int x = 0;
// identificar
 cout << "\nEXEMPLO1310 - Method10 - v0.0\n" << endl;
// testar atribuicoes
 pessoa [ 0 ] = new Contato ( "Pessoa_1", "111", "" );
 pessoa [ 1 ] = new Contato ( "Pessoa_2", "222", "" );
 pessoa [ 2 ] = new Contato ( "Pessoa_3", "334", "" );
 for ( x=0; x < 3; x=x+1 )
 {
 cout << x << " : " << pessoa[ x ]->toString( ) << endl;
 } // fim repetir
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

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
} // fim main(
