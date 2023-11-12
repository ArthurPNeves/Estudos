/*
   myerror.hpp  - v0.0. - __ / __ / _____
   Author: ______________________________

*/

// ----------------------------------------------- definicoes globais

#include <iostream>
using std::cin ;	      // para entrada
using std::cout; 	      // para saida
using std::cerr; 	      // para saida de erros
using std::endl;	      // para mudar de linha

#include <sstream>
using std::ostringstream;     // para entrada

#include <string>
using std::string;	      // para cadeia de caracteres

#ifndef _MYERROR_H_
#define _MYERROR_H_

class MyError
{
  protected: 		       // area reservada
    int         error;         // para o codigo de erro
    std::string error_id;      // para identificar a responsabilidade
    std::string error_msg;     // para a mensagem de erro

  public:

	bool has_Error ( void )
	{
	   return ( error != 0 );
	} // end has_Error ( )

	int  get_Error ( void )
	{
	   return ( error );
	} // end get_Error ( )

	virtual
	void set_Error ( int code )
	{
	   error = code;
	} // end set_Error ( )

	virtual
	std::string to_String ( )
	{
	   std::ostringstream buffer;
       buffer << "\nError code = (" << error << ")";
	   error_msg = buffer.str( );
	   return ( buffer.str( ) );
	} // end to_String_Error ( )

	virtual
	void print ( void )
	{
	   std::ostringstream buffer;
	   if ( error_msg.length( ) == 0 )
	   {
	      error_msg = to_String( );
	   } // end if
	   buffer << error_msg;
       std::cerr << buffer.str( ) << std::endl;
	} // end print_Error ( )

}; // end class

#endif
