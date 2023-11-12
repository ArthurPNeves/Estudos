#include "io.hpp"
/*
 Exemplo1101 - v0.0. - __ / __ / _____
 Author: ________________________
*/
// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres
// ----------------------------------------------- definicoes globais
void pause ( std::string text )
{
 std::string dummy;
 std::cin.clear ( );
 std::cout << std::endl << text;
 std::cin.ignore( );
 std::getline(std::cin, dummy);
 std::cout << std::endl << std::endl;
} // end pause ( )
// ----------------------------------------------- classes / pacotes
#include "myarray.hpp"
using namespace std;
// ----------------------------------------------- metodos
/**
 Method00 - nao faz nada.
*/
void method00 ( )
{
// nao faz nada
} // fim method00 ( )

void method01 ( )
{

 Array <int> int_array ( 5, 0 );

  int superior = 0;
  int inferior = 0;
  cout << "insira valor inferior:\n";
  cin >> inferior;
  cout << endl;
  cout << "insira valor superior:\n";
  cin >> superior;
  cout << endl;
  int_array.gerarint(inferior, superior);

 int_array.fprint ( "DADOS.TXT" );

 int_array.free ( );

 pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )
/**
 Method02.
*/
void method02 ( )
{
// funciona mas com bug
 Array <int> int_array ( 5, 0 );

 int_array.fread ( "DADOS.TXT" );
 int maior = int_array.acharMaior ( ) ;
 cout << endl << maior << endl;

 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method02 ( 

/**
 Method03.
*/
void method03 ( )
{

 Array <int> int_array ( 5, 0 );

 int_array.fread ( "DADOS.TXT" );
 int menor = int_array.acharMenor ( ) ;
 cout << endl << menor << endl;

 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
 Method04.
*/
void method04 ( )
{
 Array <int> int_array ( 5, 0 );

 int_array.fread ( "DADOS.TXT" );
 int soma = int_array.soma ( ) ;
 cout << endl << soma << endl;

 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
 Method05.
*/
void method05 ( )
{
Array <int> int_array ( 5, 0 );

 int_array.fread ( "DADOS.TXT" );
 double media = int_array.media ( ) ;
 cout << endl << media << endl;

 int_array.free ( ); 
// encerrar
 pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )
/**
 Method06.
*/
void method06 ( )
{
 Array <int> int_array ( 5, 0 );

 int_array.fread ( "DADOS.TXT" );


bool resultado = int_array.testeSeIgual0 ();
if ( resultado == true)
{
  cout << endl << "Todos Iguais a 0" << endl;
}
else
{
  cout << endl << "Nem Todos Iguais a 0" << endl;
}

 int_array.free ( );
 pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )
/**
 Method07.
*/
void method07 ( )
{
 Array <int> int_array ( 5, 0 );

 int_array.fread ( "DADOS.TXT" );

bool resultado = int_array.decrecente ();
if ( resultado == true)
{
  cout << endl << "Decrecente" << endl;
}
else
{
  cout << endl << "Nao esta Decrecente" << endl;
}

 int_array.free ( );
 pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )
/**
 Method08.
*/
void method08 ( )
{
 Array <int> int_array ( 5, 0 );

 int_array.fread ( "DADOS.TXT" );
  int superior = 0;
  int inferior = 0;
  int procurado = 0;
  cout << "insira valor inferior:\n";
  cin >> inferior;
  cout << endl;
  cout << "insira valor superior:\n";
  cin >> superior;
  cout << endl;
  cout << "insira procurado:\n";
  cin >> procurado;
  cout << endl;


bool resultado = int_array.acharvalor (procurado, inferior, superior);
if ( resultado == true)
{
  cout << endl << "Existe no arranjo" << endl;
}
else
{
  cout << endl << "Nao Existe no arranjo" << endl;
}


 pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )
/**
 Method09.
*/
void method09 ( )
{

 Array <int> int_array ( 5, 0 );

 int_array.fread ( "DADOS.TXT" );
  int constante = 0;
  cout << endl;
  cout << "insira constante:\n";
  cin >> constante;
  cout << endl;
  int_array.constanteMult(constante);
  int_array.print();

 pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )
/**
 Method10.
*/
void method10 ( )
{
  // nao consegui faazer
Array <int> int_array ( 5, 0 );

 int_array.fread ( "DADOS.TXT" );

int_array.colocardecrecente ();
int_array.print();

 int_array.free ( );
 pause ( "Apertar ENTER para continuar" );
} 
int main ( int argc, char** argv )
{


 int x = 0; 
 do
 {

 cout << "ED11\n " << endl;
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
 cout << endl << "Entrar com uma opcao: ";
 cin >> x;
 // escolher acao
 switch ( x )
 {
 case 0:
 method00 ( );
 break;
 case 1:
 method01 ( );
 break;
 case 2:
 method02 ( );
 break;
 case 3:
 method03 ( );
 break;
 case 4:
 method04 ( );
 break;
 case 5:
 method05 ( );
 break;
 case 6:
 method06 ( );
 break;
 case 7:
 method07 ( );
 break;
 case 8:
 method08 ( );
 break;
 case 9:
 method09 ( );
 break;
 case 10:
 method10 ( );
 break;
 default:
 cout << endl << "ERRO: Valor invalido." << endl;
 } // fim escolher
 }
 while ( x != 0 );
// encerrar
 pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( 