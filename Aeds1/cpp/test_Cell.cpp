#include <iostream>

using namespace std;

#include "Cell.hpp"

int main ( void )
{
 // definir dados locais 
    Cell <int>   *a = new Cell <int> ( );
    Cell <double> b;

    std::string s;

 // testes
 //   (*a).test ( );
    a->test ( );
 //   b.test  ( );

    std::cout << "\nEND\n";
    getline ( cin, s );
    return ( 0 );
} // end main ( )
