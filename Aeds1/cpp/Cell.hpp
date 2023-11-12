#include <iostream>
#include <string>

#include "myerror.hpp"

using namespace std;

// _______________________________________________ Cell.hpp

template <typename T>
class Cell : public MyError
{
    protected:
 // data
    T     optional;
    bool  empty;
    T     value;
    Cell *link ;


    public:
 // constructors and destructors
 // destructor
  ~ Cell ( )
    { }

 // constructor
    Cell ( )
    {
        empty = true;
        this->set_Value ( 0 );
        this->set_Link  ( nullptr );
    } // end Cell ( )

 // constructor (alternative)
    Cell ( T initial_value, Cell *initial_link=nullptr )
    {
        empty     = false;
        optional  = initial_value;
        set_Value ( optional );
        set_Link  ( initial_link  );
    } // end Cell ( )

 // accessors - setters and getters
    T  get_Value ( )
    {
         if ( empty )
            return ( this->optional );
         else
            return ( this->value );
    } // end get_Value ( )

    void set_Value ( T new_Value )
    {
         empty = false;
         this->value = new_Value;
    } // end set_Value ( )

    Cell* get_Link ( )
    {
         return ( this->link );
    } // end get_Link ( )

    void  set_Link ( Cell* new_Link )
    {
         this->link = new_Link;
    } // end set_Link ( )

 // convert data to string
    std::string toString ( )
    {
         std::string txt = "";
         Cell *tmp = nullptr;

         if ( isEmpty( ) )
         {
            txt = "[]"; // vazio
         }
         else
         {
            // base
            txt = txt + std::to_string ( this->get_Value( ) );
            // proximo 'a base
            tmp = this->get_Link( );
            while ( tmp )
            {
               txt = txt + "->" + std::to_string ( tmp->get_Value( ) );
               tmp = tmp->get_Link( ); // proximo ao atual
            } // end while
         } // end if
         
         return ( txt );
    } // end toString ( )

 // service
    Cell* get_Back ( )
    {
         Cell <T> *tmp = this;
         while ( tmp && tmp->get_Link( ) )
         {
            tmp = tmp->get_Link( );
         } // end while

         return ( tmp );
    } // end get_Back ( )

 // service
    int  get_Length ( )
    {
         int length    = 0;
         Cell <T> *tmp = this;

         while ( tmp )
         {
            if ( ! tmp->empty )
               length = length + 1;
            tmp = tmp->get_Link( );
         } // end while
         return ( length );
    } // end get_Length ( )

 // append
    void push_back ( T new_Value )
    {
         this->get_Back( )
             ->set_Link( new Cell <T> ( new_Value, nullptr ) );
    } // end push_back ( )

 // prepend
    void push_front ( T new_Value )
    {
      // definir dado local
         Cell *tmp = new Cell <T>( this->get_Value( ), this->get_Link( ) );
         if ( tmp )
         {
            this->set_Value ( new_Value );
            this->set_Link  ( tmp );
         } // end if
    } // end push_front ( )

 // remove first, but the last one
    Cell* pop_front ( )
    {
      // OBS.: NAO se podera' remover a referencia unitaria,
      //       mas podera' marca'-la como vazia.
      // definir dado local
         Cell *tmp     = new Cell <T> 
                       ( this->get_Value( ), nullptr );
         Cell *garbage = this->link;

         if ( garbage )
         {
            this->set_Value ( garbage->get_Value( ) );
            this->set_Link  ( garbage->get_Link ( ) );
            garbage->set_Link ( nullptr );
            delete ( garbage );
         }
         else
         if ( ! empty )
         {
            this->empty = true; this->value = optional;
         }
         else
         {
            tmp ->empty = true; tmp ->value = optional;
         } // end if
         return ( tmp );
    } // end pop_front ( )

 // remove last
    Cell* pop_back ( )
    {
      // definir dado local
         Cell *tmp     = nullptr;
         Cell *garbage = this->get_Back( );
         Cell *aux     = this;

         if ( ! empty && garbage )
         {
            tmp = new Cell <T> ( garbage->get_Value( ), nullptr );
         
            std::cout << "\nSearching pointer to the last one\n";
            while ( aux && aux->get_Link( ) != garbage )
            {
                  aux = aux->get_Link( );
            } // end while
            if ( aux )
            {
               aux->set_Link ( nullptr );
               delete ( garbage );
            }
            else
            {
               if ( ! empty )
               {
                  this->empty = true; this->value = optional;
               }
               else 
               {               
                  tmp ->empty = true; tmp ->value = optional;
               } // end if
            } // end if
         }
         return ( tmp );
    } // end pop_back ( )

    bool  isEmpty ( void )
    {
        return ( empty );
    } // end isEmpty ( )
    
 // tester
    void test ( )
    {
     // data definition
        Cell <int> *a1 = nullptr;
        Cell <int> *b1 = new Cell <int> ( );
        Cell <int> *c1 = new Cell <int> ( 5 );
        Cell <int> *d1 = new Cell <int> ( 10 );
        Cell <int> *e1 = new Cell <int> ( 15, nullptr );
        int         x  = 0;
        std::string s  = "";
        
     // tests
        std::cout << "\nTest - Cell\n" << std::endl;

     // 01. identity
        a1 = b1;  // identicos -> apontam a mesma coisa (nao e' copia!!!)

        std::cout << "01. a1=b1  a1 = " << a1->toString( ) << std::endl;
        std::cout << "01. a1=b1  b1 = " << b1->toString( ) << std::endl;

        a1->set_Value ( 1 );
        
        std::cout << "01. a1=b1  a1 = " << a1->toString( ) << std::endl;
        std::cout << "01. a1=b1  b1 = " << b1->toString( ) << std::endl;

        std::cout << std::endl;
        std::getline ( std::cin, s );
        
     // 02. appending
        c1->set_Link ( d1 );

        std::cout << "02. c1->d1   = " << c1->toString( ) << std::endl;

        d1->set_Link ( e1 );

        std::cout << "02. d1->e1   = " << d1->toString( ) << std::endl;
        std::cout << "02. c1->...  = " << c1->toString( ) << std::endl;

        std::getline ( std::cin, s );

     // 03. appending with a new cell as parameter
        e1->set_Link ( new Cell <int> ( 20, nullptr ) );

        std::cout << "03. c1->...  = " << c1->toString( ) << std::endl;
        std::cout << std::endl;

        std::getline ( std::cin, s );

     // 04. appending using reference to the last cell
        std::cout << "04. c1->back = "
                  << c1->get_Back( )->toString( ) 
                  << std::endl;

        std::getline ( std::cin, s );

     // 05. appending using reference to the last cell and new object
        for ( x=0; x<3; x=x+1 )
        {
            c1->get_Back( )
              ->set_Link
                ( new Cell <int> 
                ( c1->get_Back ( )->get_Value( )+5, nullptr ) );
            std::cout << "05. c1->...  = " 
                      << c1->toString( ) 
                      << std::endl;
        } // end for
        std::cout << std::endl;

        std::getline ( std::cin, s );

     // 06. appending and updating length
        std::cout << "06. a1->length = "
                  <<  a1->get_Length( ) 
                  << std::endl;
        std::cout << "06. c1->length = "
                  <<  c1->get_Length( ) 
                  << std::endl;
        std::cout << std::endl;

        for ( x=0; x<3; x=x+1 )
        {
            c1->push_back ( c1->get_Back( )->get_Value( )+5 );
            std::cout << "06. c1->...  = " 
                      << c1->toString( ) 
                      << std::endl;
        } // end for
        std::cout << std::endl;

        std::cout << "06. c1->length = "
                  <<  c1->get_Length( ) 
                  << std::endl;
                  
        std::cout << std::endl;
        std::getline ( std::cin, s );

     // 07. prepending and updating length
        for ( x=4; x>0; x=x-1 )
        {
            c1->push_front ( x );
            std::cout << "07. c1->...  = " 
                      << c1->toString( ) 
                      << std::endl;
        } // end for
        std::cout << std::endl;

        std::cout << "07. c1->length = "
                  <<  c1->get_Length( ) << std::endl;

        std::cout << std::endl;
        std::getline ( std::cin, s );

     // 08. removing first and updating length
        for ( x=4; x>0; x=x-1 )
        {
            a1 = c1->pop_front ( );
            std::cout << "08. a1       = " 
                      << a1->toString( ) 
                      << std::endl;
            std::cout << "08. c1->...  = " 
                      << c1->toString( ) 
                      << std::endl;
        } // end for
        std::cout << std::endl;

        std::cout << "08. c1->length = "
                  <<  c1->get_Length( ) 
                  << std::endl;
                  
        std::cout << std::endl;
        std::getline ( std::cin, s );

     // 09. removing last and updating length
        for ( x=4; x>=0; x=x-1 )
        {
            a1 = c1->pop_back ( );
            std::cout << "09. a1       = " 
                      << a1->toString( ) 
                      << std::endl;
            std::cout << "09. c1->...  = " 
                      << c1->toString( ) 
                      << std::endl;
        } // end for
        std::cout << std::endl;

        std::cout << "09. c1->length = "
                  <<  c1->get_Length( ) 
                  << std::endl;

        std::cout << std::endl;
        std::getline ( std::cin, s );

     // 10. trying to remove last single reference
        std::cout << "\nRemove last one\n" << std::endl;
        if ( a1 )
        {
           std::cout << "10. a1       = " 
                     << a1->toString( ) 
                     << std::endl;
           a1 = a1->pop_back ( );
           std::cout << "\nLast one removed\n" 
                     << std::endl;
           std::cout << "10. a1       = " 
                     << a1->toString( ) 
                     << std::endl;
        } // end if

        std::getline ( std::cin, s );

        std::cout << "\nRemoving cells\n" << std::endl;
        while ( ! c1->isEmpty( ) )
        {
           std::cout << "10. c1       = " 
                     << c1->toString( )   
                     << std::endl;
           std::cout << "10. c1.length= " 
                     << c1->get_Length( ) 
                     << std::endl;
           a1 = c1->pop_front( );
//           a1 = c1->pop_back ( );
           std::cout << "10. a1       = " 
                     << a1->toString( )   
                     << std::endl;
           std::cout << "10. a1.length= " 
                     << a1->get_Length( ) 
                     << std::endl;
           std::getline ( std::cin, s );
        }
        std::cout << "10. c1       = " 
                  << c1->toString( )   
                  << std::endl;
        std::cout << "10. c1.length= " 
                  << c1->get_Length( ) 
                  << std::endl;

        std::cout << "\nTry to remove from empty cell\n" 
                  << std::endl;
        if ( c1 )
        {
            std::cout << "10. c1       = " 
                      << c1->toString( )   
                      << std::endl;
            a1 = c1->pop_back ( );
            std::cout << std::endl;
            std::cout << "\nLast already removed\n";
            a1 = c1->pop_front( );
            std::cout << std::endl;
            std::cout << "\nLast already removed\n";
        } // end if

        std::cout << std::endl;
        std::getline ( std::cin, s );

     // dispensar area
        delete ( a1 );
        delete ( b1 );
        delete ( c1 );
        delete ( d1 );
        delete ( e1 );

        std::cout << "\nEND test\n";
        std::getline ( cin, s );
    } // end test ( )

}; // end class
