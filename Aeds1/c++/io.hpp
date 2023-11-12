/**
   IO_lib - v0.3c - __ / __ / _____
   Author: ________________________

 */
// ---------------------- lista de dependencias

#include <iostream>    // para entradas e saidas
#include <iomanip>     // para formatacoes
#include <fstream>     // para arquivos
#include <sstream>     // para conversoes
#include <string>      // std::string         - para objetos com caracteres
#include <limits>      // std::numeric_limits - para intervalos de valores

#include <cstdio>      // para entradas e saida
#include <cstdlib>     // para a biblioteca padrao
#include <cstring>     // para cadeias de caracteres
#include <cmath>       // para definicoes matematicas

#include <stddef.h>    // para definicoes basicas
#include <stdarg.h>    // para tratar argumentos
#include <ctype.h>     // para tipos padroes
#include <time.h>      // para medir tempo

#ifndef __IO_HPP__
#define __IO_HPP__

// ---------------------- redefinicoes uteis

#define  null             nullptr

#define  IO_printf        printf
#define  IO_scanf         scanf
#define  IO_fprintf       fprintf
#define  IO_fscanf        fscanf

#define  AND              &&
#define  OR               ||
#define  NOT              ! 
#define  XOR              ^ 

// ---------------------- definicoes de constantes

const   bool FALSE        = false;  // definir constante
const   bool TRUE         = true ;  // definir constante

const   char EOS          = '\0';   // definir fim de cadeia de caracteres
const   char EOL          = '\n';   // definir mudanca de linha
const   char ENDL []      = "\n";   // definir mudanca de linha
const   char STR_EMPTY [] =  "" ;   // definir cadeia de caracteres vazia
const   int  STR_SIZE     =  80 ;   // definir tamanho padrao para caracteres

// ---------------------- definicoes de tipos

typedef char*   chars  ;            // definir cadeia  de caracteres
typedef int*    ints   ;            // definir arranjo de inteiros
typedef double* doubles;            // definir arranjo de reais
typedef bool*   bools  ;            // definir arranjo de logicos

// ---------------------- definicoes de variaveis globais

int  IO_error   = 0;                // inicialmente sem erros
bool IO_trace   = true;             // inicialmente habilitado

// ---------------------- definicoes de funcoes e procedimentos

// ---------------------- para tratamento de erros

void IO_debugOFF ( )
{
  IO_trace = false;
} // end IO_debug_OFF ( )

void IO_debugON  ( )
{
  IO_trace = true;
} // end IO_debug_ON  ( )

void IO_debug ( bool condition, char *text )
{
  if ( IO_trace && condition )
  {
     printf ( "\nDBG> %s\n", text );
     getchar( );
  } // end if
} // end IO_debug ( )

// ---------------------- para entradas e saidas

/**
    Metodo para limpar a saida de dados padrao.
 */
void IO_clrscr ( void )
{
 // system ( "clear" ); // para Linux   - OBS: NAO RECOMENDADO !
    system ( "cls"   ); // para Windows - OBS: NAO RECOMENDADO !
} // end IO_flush ( )

/**
    Metodo para limpar a entrada de dados padrao.
 */
void IO_flush ( void )
{
 // fflush ( stdin );   // OBS: NAO RECOMENDADO !
    std::cin.clear ( );
    std::cin.ignore(80, '\n');
} // end IO_flush ( )

/**
    Funcao para informar a versao dessa biblioteca.
    @return versao atual
 */
std::string IO_version ( void )
{
    std::string x = "v.03b";
    return ( x );
} // end IO_version ( )

/**
    Metodo para identificar o programa e a autoria.
    @param text - mensagem a ser exibida
 */
void IO_id ( std::string text )
{
    std::cout << text << std::endl;
    std::cout << "Autor: ________________________";
    std::cout << std::endl;          // mudar de linha
} // fim IO_id ( )

/**
    Funcao para ler valor logico do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
    OBS.:   Usar o valor zero para falso, e diferente de zero para verdadeiro
 */
bool IO_readbool ( std::string text )
{
    int x = 0;
    std::cout << text;
    std::cin  >> std::skipws >> x;
    std::cin.clear ( );
    return    ( x!=0 );
} // end IO_readbool ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
char IO_readchar ( std::string text )
{
    char x = '0';
    std::cout << text;
    do
    {
      IO_flush    ( );
      std::cin.get ( x );
      std::cin.clear ( );
    }
    while ( x == '\n' );
    return ( x );
} // end IO_readchar ( )

/**
    Funcao para ler valor real de precisao dupla do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
double IO_readdouble ( std::string text )
{
    double x = 0.0;
    std::cout << text;
    std::cin  >> std::skipws >> x;
    std::cin.clear ( );
    return    ( x );
} // end IO_readdouble ( )

/**
    Funcao para ler valor real de precisao simples do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
float IO_readfloat ( std::string text )
{
    float x = 0.0;
    std::cout << text;
    std::cin  >> std::skipws >> x;
    std::cin.clear ( );
    return    ( x );
} // end IO_readfloat ( )

/**
    Funcao para ler valor inteiro do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
int IO_readint ( std::string text )
{
    int x = 0;
    std::cout << text;
    std::cin  >> std::skipws >> x;
    std::cin.clear ( );
    return    ( x );
} // end IO_readint ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
 */
void IO_pause ( void )
{
    char x = '0';
    do
    {
//    IO_flush    ( );
      x = std::cin.get( );
      std::cin.clear( );
    }
    while ( x != '\n' );
} // end IO_pause ( )

/**
    Funcao para ler caractere do teclado.
    @return valor lido
    @param  text - mensagem a ser exibida antes da leitura
 */
void IO_pause ( std::string text )
{
    std::cout << std::endl << text << std::endl;
    IO_pause ( );
} // end IO_pause ( )

/**
    Funcao para reservar espaco para guardar cadeia de caracteres.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
chars IO_new_chars ( int size )
{
    return ( (chars) malloc ( (size+1)*sizeof(char) ) );
} // fim IO_new_chars ( )

/**
    Funcao para reservar espaco para guardar inteiros.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
ints IO_new_ints ( int size )
{
    return ( (ints) malloc ( (size)*sizeof(int) ) );
} // fim IO_new_ints ( )

/**
    Funcao para reservar espaco para guardar reais.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
doubles IO_new_doubles ( int size )
{
    return ( (doubles) malloc ( (size)*sizeof(double) ) );
} // fim IO_new_doubles ( )

/**
    Funcao para reservar espaco para guardar logicos.
    @return area reservada, se houver; NULL, caso contrario
    @param size - quantidade de dados
 */
bools IO_new_bools ( int size )
{
    return ( (bools) malloc ( (size)*sizeof(bool) ) );
} // fim IO_new_bools ( )

/**
    Funcao para concatenar cadeias de caracteres.
    @return cadeia com o resultado
    @param text1 - primeira cadeia
    @param text2 - segunda  cadeia
 */
std::string IO_concat ( std::string text1, std::string text2 )
{                               
  std::string buffer = text1+text2;
  return ( buffer );
} // fim IO_concat ( )

/**
    Funcao para converter valor logico para caracteres.
    @return cadeia com o resultado
    @param x     - valor logico
 */
std::string IO_toString ( bool x )
{
  std::ostringstream buffer;
  buffer << std::boolalpha << x;
  return  ( buffer.str ( ) );
} // fim IO_toString ( )

/**
    Funcao para converter caractere para caracteres.
    @return cadeia com o resultado
    @param x     - caractere
 */
std::string IO_toString ( char x )
{                             
  std::ostringstream buffer;
  buffer << x;
  return  ( buffer.str ( ) );
} // fim IO_toString ( )

/**
    Funcao para converter inteiro para caracteres.
    @return cadeia com o resultado
    @param x     - valor inteiro
 */
std::string IO_toString ( int x )
{         
  std::ostringstream buffer;
  buffer << x;
  return  ( buffer.str ( ) );
} // fim IO_toString ( )

/**
    Funcao para converter real para caracteres.
    @return cadeia com o resultado
    @param x     - valor real
 */
std::string IO_toString ( double x )
{
  std::ostringstream buffer;
  buffer << x;
  return  ( buffer.str ( ) );
} // fim IO_toString ( )

/**
    Funcao para converter cadeia de caracteres.
    @return cadeia com o resultado
    @param x     - valor real
 */
std::string IO_toString ( chars x )
{
  std::ostringstream buffer;
  buffer << x;
  return  ( buffer.str ( ) );
} // fim IO_toString ( )

/**
    Funcao para converter cadeia de caracteres.
    @return cadeia com o resultado
    @param x     - valor real
 */
const char* IO_toString ( std::string x )
{
  return  ( x.c_str ( ) );
} // fim IO_toString ( )

/**
    Metodo para mostrar uma linha com certo texto.
    @param text1 - primeira cadeia
 */
void IO_print ( std::string text1 )
{
  std::cout << text1;
} // fim IO_print ( )

/**
    Metodo para mostrar uma linha com certo texto
    e mudar de linha.
    @param text1 - primeira cadeia
 */
void IO_println ( std::string text1="" )
{
  std::cout << text1 << std::endl;
} // fim IO_println ( )

/**
    Metodo para gravar uma linha em arquivo texto.
    @param filePtr - referencia para arquivo aberto
    @param text1 - cadeia de caracteres a ser gravada
 */
void IO_fprint ( FILE* filePtr, std::string text1 )
{
  fprintf ( filePtr, "%s", text1.c_str( ) );
} // fim IO_fprint ( )

/**
    Metodo para gravar uma linha em arquivo texto
    e mudar de linha.
    @param filePtr - referencia para arquivo aberto
    @param text1 - cadeia de caracteres a ser gravada
 */
void IO_fprintln ( FILE* filePtr, std::string text1 )
{
  fprintf ( filePtr, "%s\n", text1.c_str( ) );
} // fim IO_fprintln ( )

/**
    Funcao para ler uma palavra de arquivo.
    @return palavra lida
    @param arquivo - referencia para arquivo aberto
 */
chars IO_fread ( FILE* filePtr )
{
  chars buffer = IO_new_chars ( STR_SIZE+1 );

  fscanf ( filePtr, "%s", buffer ); // ler uma linha
  return ( buffer );
} // fim IO_fread ( )

/**
    Funcao para ler uma linha inteira.
    @return linha lida
    @param filePtr - referencia para arquivo aberto
 */
std::string IO_freadln ( std::ifstream& filePtr )
{
  std::string buffer;

  std::getline ( filePtr, buffer );   // ler uma linha
  return ( buffer );
} // fim IO_freadln ( )
/**/

/**
    Funcao para ler cadeia de caracteres.
    @return cadeia de caracteres
    @param text - mensagem a ser exibida antes da leitura
 */
std::string IO_readstring ( std::string text )
{
  std::string buffer;

  std::cout << text ;
  IO_flush  ( )      ;                // limpar a entrada de dados
  std::cin  >> buffer;                // ler cadeia de caracteres

  return ( buffer );
} // fim IO_readString ( )

/**
    Funcao para ler uma linha inteira.
    @return linha lida
    @param text - mensagem a ser exibida antes da leitura
 */
std::string IO_readln ( std::string text )
{
  std::string buffer;

  std::cout << text ;
  IO_flush  ( );                           // limpar a entrada de dados
//std::getline ( std::cin, buffer, std::cin.widen('\n') );   // ler cadeia de caracteres
//std::getline ( std::cin, buffer);        // ler uma linha
  std::getline ( std::cin, buffer, '\n' ); // ler cadeia de caracteres

  return ( buffer );
} // fim IO_readln ( )

#endif
