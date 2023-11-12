
// ----------------------------------------------- preparacao
// dependencias
#include <iostream>
#include <math.h>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo
// outras dependencias
void pause ( std::string text )
{
 std::string dummy;
 std::cin.clear ( );
 std::cout << std::endl << text;
 std::cin.ignore( );
 std::getline(std::cin, dummy);
 std::cout << std::endl << std::endl;
} // end pause ( )
// ----------------------------------------------- classes
#include "Erro.hpp" // classe para tratar erros
class MyString : public Erro
{
  private:
  string s = "";
  int length = 0;
  int chave = 2;
 public:


bool isnum(char c){
        int result = false;
        try {
            if ('0'<= c && c<= '9'){
                result = true;
                throw (0);
            }else {
                throw (-1);
            }
        }catch (int error) {
            setErro(error);
        }

        return (result);
    }

void setString(string temp)
    {
        s = temp;
        length = temp.length();
    }

std::string getString()
    {
        return (s);
    }

int TransformaInt()
{
  int resultado = 0;
  for ( int i = 0; i < s.length(); i++)
  {
    if (isnum(s[i]))
    {
      resultado = s[i] -48;
    }
    
  }
  return (resultado); 
}

};
using namespace std;


void method00 ( )
{
// nao faz nada
} // fim method00 ( )
/**
 Method01 - Testar definicoes da classe.
*/
void method01 ( )
{
  MyString *s = new MyString();
  
  s->setString("76");
  cout<< s->TransformaInt();
cout << endl<<s->getErroMsg();
 pause ( "Apertar ENTER para continuar" );
} 

int main ( int argc, char** argv )
{
// definir dado
 int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
 do
 {
 // identificar
 cout << "EXEMPLO1401 - Programa - v0.0\n " << endl;
 // mostrar opcoes
 cout << "Opcoes " << endl;
 cout << " 0 - parar " << endl;
 cout << " 1 - testar definicoes " << endl;
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
 default:
 cout << endl << "ERRO: Valor invalido." << endl;
 } // fim escolher
 }
 while ( x != 0 );
// encerrar
 pause ( "Apertar ENTER para terminar" );
 return ( 0 );
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa
*/