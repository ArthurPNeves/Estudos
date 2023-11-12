#include "io.hpp"
using namespace std;

#include <iostream>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream ; // para ler arquivo
template < typename T >
class Array
{
 private: // area reservada
 T optional;
 int length;
 T *data;
 public: // area aberta
 Array ( int n, T initial )
 {
 // definir valores iniciais
 optional = initial;
 length = 0;
 data = nullptr;
 // reservar area
 if ( n > 0 )
 {
 length = n;
 data = new T [ length ];
 }
 } // end constructor
 void free ( )
 {
 if ( data != nullptr )
 {
 delete ( data );
 data = nullptr;
 } // end if
 } // end free ( )
 void set ( int position, T value )
 {
 if ( 0 <= position && position < length )
 {
 data [ position ] = value;
 } // end if
 } // end set ( )
 T get ( int position )
 {
 T value = optional;
 if ( 0 <= position && position < length )
 {
 value = data [ position ];
 } // end if
 return ( value );
 } // end get ( )
 void print ( )
 {
 cout << endl;
 for ( int x = 0; x < length; x=x+1 )
 {
 cout << setw( 3 ) << x << " : "
 << setw( 9 ) << data[ x ]
 << endl;
 } // end for
 cout << endl;
 } // end print ( )

 void read ( )
 {
 cout << endl;
 for ( int x = 0; x < length; x=x+1 )
 {
 cout << setw( 3 ) << x << " : ";
 cin >> data[ x ];
 } // end for
 cout << endl;
 } // end read ( )


void fprint ( string fileName )
 {
 ofstream afile; // output file
 afile.open ( fileName );
 afile << length << endl;
 for ( int x = 0; x < length; x=x+1 )
 {
 afile << data[ x ] << endl;
 } // end for
 afile.close ( );
 } // end fprint ( )


void fread ( string fileName )
 {
 ifstream afile; // input file
 int n = 0;
 afile.open ( fileName );
 afile >> n;
 if ( n <= 0 )
 {
 cout << "\nERROR: Invalid length.\n" << endl;
 }
 else
 {
 // guardar a quantidade de dados
 length = n;
 // reservar area
 data = new T [ n ];
 // ler dados
 for ( int x = 0; x < length; x=x+1 )
 {
 afile >> data[ x ];
 } // end for
 } // end if
 afile.close ( );
 } // end fread ()

 void gerarint(int inferior, int superior)
 {

  int posicao = 0;
  int x = 0;
  while (length > posicao)
  {
    x = rand();
    if (x > inferior && x < superior)
    {
      data[posicao] = x;
      posicao++;
    }
  }
 }

 int acharMaior(){
    int posicao = 0;
    int maior = data[posicao];
    while (length > posicao)
    {
        posicao++;
        if (maior < data[posicao] )
        {
            maior = data[posicao];

        }
        
    }
    return(maior);
 }

 int acharMenor(){
    int posicao = 0;
    int menor = data[posicao];
    while (length > posicao)
    {
        posicao++;
        if (menor > data[posicao] )
        {
            menor = data[posicao];

        }
        
    }
    return(menor);
 }


int soma(){
    int posicao = 0;
    int soma = 0;
    while (length > posicao)
    {
        
        soma = soma + data[posicao];
        posicao++;
    }
    return(soma);
 }

 double media(){
    int posicao = 0;
    double soma = 0;
    double media = 0;
    while (length > posicao)
    {
        
        soma = soma + data[posicao];
        posicao++;
    }
    media = soma/posicao;
    return(media);
 }

bool testeSeIgual0(){
    bool resultado = false;
    int posicao = 0;
    int contador = 0;
    while (length > posicao)
    {
        if (data[posicao] == 0)
        {
            contador++;
        }
        posicao++;
    }

    if (contador == posicao)
    {
        resultado = true;
    }
    
    return(resultado);
 }

 bool decrecente(){
    bool resultado = false;
    int posicao = 0;
    int contador = 0;
    while (length > posicao)
    {
        if (data[posicao] > data[posicao + 1])
        {
            contador++;
        }
        if(posicao == length -1){
            contador++;
        }
        posicao++;
    }

    if (contador == posicao)
    {
        resultado = true;
    }
    
    return(resultado);
 }

 bool acharvalor(int procurado, int inferior, int superior){
    int posicao = inferior;
    int contador = 0;
    bool resultado = false;
    while (length > posicao && superior > posicao )
    {
        if (data[posicao] == procurado)
        {
            contador++;
        }
        
        posicao++;
    }
    if (contador > 0)
    {
        resultado = true;
    }
    return(resultado);
 }
 void constanteMult(int constante){
    int posicao = 0;
    while ( length > posicao)
    {
        data[posicao] = data[posicao] * constante;
        posicao++;
    }
    
 }

    void colocardecrecente(){
        int posicao = 0;
        int trocador = 0;
        while (decrecente() == false)
        {
            while (length > posicao)
            {
                if (data[posicao] < data[posicao + 1])
                {
                    trocador = data[posicao];
                    data[posicao] = data[posicao + 1];
                    data[posicao + 1] = trocador;
                }
            
            }
            posicao++;
            }
        }
    
    
};