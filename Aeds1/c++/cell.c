// 999999_AED1
#include <stdio.h>
#include <stdlib.h>

/*
  Roteiro:
  0. definir testes
  1. definir erros
  2. definir dados
     2.1. constantes    (simples, elaboradas)
     2.2. tipos         (simples, elaborados)
     2.3. armazenadores (simples, elaborados)
     2.4. apontadores   (simples, estruturais, de servico)
  3. definir acoes
     3.1. construtores  (alocadores  , inicializadores)
     3.2. destrutores   (recicladores, desvinculadores)
     3.3. acessos
          3.3.1. individuais
                 setters
                 gettters
          3.3.2. grupo
                 print/to_String
     3.4. operacoes
*/

// ---

/*
           intCell
         ___________   
        |       |   |  
        | value |   |  
        |-----------|  
        | link  |  --->
        |_______|___|  
*/
typedef
   struct s_intCell
   {
     int               value;
     struct s_intCell *link ;
   }
intCell;

/*
ref_intCell            
   __    ___________   
  |  |  |       |   |  
  | --->| value | ? |  
  |__|  |-----------|  
        | link  |  ---> ?
        |_______|___|  
*/
typedef
 intCell *
ref_intCell;

/*
  self            
   __    ___________   
  |  |  |       |   |  
  | --->| value | x |  
  |__|  |-----------|  
        | link  |  ---> ?
        |_______|___|  
*/
void intCell_setValue ( ref_intCell self, int value )
{
     if ( self )
     {
        self->value = value;
     } // end if
} // end intCell_setValue ( ) 

/*
  self            
   __    ___________     ___________ 
  |  |  |       |   |   |       |   |
  | --->| value | ? |   | value | ? |
  |__|  |-----------|   |-----------|
        | link  |  ---> | link  |  ---> ?
        |_______|___|   |_______|___|
*/
void intCell_setLink ( ref_intCell self, ref_intCell link )
{
     if ( self )
     {
        self->link = link;
     } // end if
} // end intCell_setLink ( ) 

/*
  self                   
   __    ___________     
  |  |  |       |   |    
  | --->| value | x |     ===> x  
  |__|  |-----------|    
        | link  |  ---+  
        |_______|___| |  
                    __v__
                     ___ 
                         
*/
int  intCell_getValue ( ref_intCell self )
{
     int value = 0;
     if ( self )
     {
        value = self->value;
     } // end if
     return ( value );
} // end intCell_getValue ( ) 

/*
  self                   
   __    ___________     
  |  |  |       |   |    
  | --->| value | x |    
  |__|  |-----------|    
        | link  |  ---+   ===> link
        |_______|___| |  
                    __v__
                     ___ 
*/                         
ref_intCell intCell_getLink ( ref_intCell self )
{
     ref_intCell link = NULL;
     if ( self )
     {
        link = self->link;
     } // end if
     return ( link );
} // end intCell_getLink ( ) 

/*
  self                   
   __    ___________     
  |  |  |       |   |    
  | --->| value | x |    
  |__|  |-----------|    
        | link  |  ---+  
        |_______|___| |  
                    __v__
                     ___ 
                         
*/
void intCell_init ( ref_intCell self, int value )
{
    if ( self )
    {
       intCell_setValue ( self, value ); // self->value = value;
       intCell_setLink  ( self, NULL  ); // self->link  = NULL ;
     } // end if
} // end intCell_init ( ) 

/*
         malloc  OK         NULL
   __    ___________         __
  |  |  |       |   |       |  | 
  | --->| value | ? |       | ---+
  |__|  |-----------|       |__| | 
        | link  |  ---> ?      __v__   
        |_______|___|           ___
*/
ref_intCell intCell_alloc ( )
{
    return ( malloc ( sizeof(intCell) ) );
} // end intCell_alloc ( )

/*
  self                  
   __    ___________     
  |  |  |       |   |    
  | --->| value | x |    
  |__|  |-----------|    
        | link  |  ---+  
        |_______|___| |  
                    __v__
                     ___ 
                       
*/
ref_intCell intCell_newCell ( int value )
{
    ref_intCell self = intCell_alloc ( );
    intCell_init ( self, value );
    return ( self );
} // end intCell_newCell ( )

/*
  front                     back
   __    ___________         __    ___________ 
  |  |  |       |   |       |  |  |       |   |
  | --->| value | x |       | --->| value | y |
  |__|  |-----------|       |__|  |-----------|
        | link  |  ---+           | link  |  ---+
        |_______|___| |           |_______|___| |
                    __v__                     __v__
                     ___                       ___
                      
  front                     back
   __    ___________         __    ___________ 
  |  |  |       |   |       |  |  |       |   |
  | --->| value | x |       | --->| value | y |
  |__|  |-----------|       |__|  |-----------|
        | link  |  -------------->| link  |  ---+
        |_______|___|             |_______|___| |
                                              __v__
                                               ___
*/
void intCell_connect ( ref_intCell front, ref_intCell back )
{
     if ( front )
     {
        intCell_setLink ( front, back ); // front->link = back;
     } // end if
} // end intCell_connect ( ) 

/*
  front                    back
   __    ___________        __    ___________ 
  |  |  |       |   |      |  |  |       |   |
  | --->| value | x |      | --->| value | y |
  |__|  |-----------|      |__|  |-----------|
        | link  |  ------------->| link  |  ---+
        |_______|___|            |_______|___| |
                                             __v__
                                              ___

  front                    back
   __    ___________        __    ___________ 
  |  |  |       |   |      |  |  |       |   |
  | --->| value | x |      | --->| value | y |
  |__|  |-----------|      |__|  |-----------|
        | link  |  ---+          | link  |  ---+
        |_______|___| |          |_______|___| |
                    __v__                    __v__
                     ___                      ___ 
*/
void intCell_disconnect ( ref_intCell front, ref_intCell back )
{
     if ( front && back && intCell_getLink ( front ) == back )
     {
        intCell_setLink ( front, NULL ); // front->link = NULL;
     } // end if
} // end intCell_disconnect ( ) 

/*
  Method for printing value of a pointed cell.
  @param self - pointer to a cell
*/
void intCell_printCell ( ref_intCell self )
{
    if ( self )
    {
       printf ( " %d ", self->value );
    }
    else
    {
       printf ( " _ " );
    } // end if
} // end intCell_printCell ( )

/*
  Method for printing all values linked to a pointed cell.
  @param self - pointer to a cell
*/
void intCell_print ( ref_intCell front )
{
    ref_intCell cursor = front;
    while ( cursor )
    {
        printf ( " %d ", intCell_getValue ( cursor ) );
        cursor = intCell_getLink ( cursor );
    } // end while 
} // end intCell_print ( )

/*
  Function for counting cells linked to a pointed cell.
  @return number of cells
  @param  self - pointer to a cell
*/
int intCell_length ( ref_intCell self )
{
    int         length = 0;
    ref_intCell cursor = self;
    while ( cursor )
    {
        length = length + 1;
        cursor = intCell_getLink ( cursor );
    } // end while
    return ( length );
} // end intCell_length ( )

/*
 cursor
   __
  |  |
  | ----+
  |__|  |
        |
  front |                  back
   __   v___________        __    ___________ 
  |  |  |       |   |      |  |  |       |   |
  | --->| value | x |      | --->| value | y |
  |__|  |-----------|      |__|  |-----------|
        | link  |  ------------->| link  |  ---+
        |_______|___|            |_______|___| |
                                             __v__
                                              ___

 cursor
     __
    |  |
    | -----------------------------+
    |__|                           |
                                   |
    front                    back  |
     __    ___________        __   v___________ 
    |  |  |       |   |      |  |  |       |   |
    | --->| value | x |      | --->| value | y |
    |__|  |-----------|      |__|  |-----------|
          | link  |  ------------->| link  |  ---+
          |_______|___|            |_______|___| |
                                               __v__
                                                ___
  
 cursor
     __
    |  |
    | -----------------------------+
    |__|                           |
                                   |
    front                    back  |                 newCell
     __    ___________        __   v___________        __    ___________   
    |  |  |       |   |      |  |  |       |   |      |  |  |       |   |  
    | --->| value | x |      | --->| value | y |      | --->| value | z |  
    |__|  |-----------|      |__|  |-----------|      |__|  |-----------|  
          | link  |  ------------->| link  |  ---+          | link  |  ---+
          |_______|___|            |_______|___| |          |_______|___| |
                                               __v__                    __v__
                                                ___                      ___
    
 cursor
     __
    |  |
    | -----------------------------+
    |__|                           |
                                   |
    front                    back  |                 newCell
     __    ___________        __   v___________        __    ___________   
    |  |  |       |   |      |  |  |       |   |      |  |  |       |   |  
    | --->| value | x |      | --->| value | y |      | --->| value | z |  
    |__|  |-----------|      |__|  |-----------|      |__|  |-----------|  
          | link  |  ------------->| link  |  ------------->| link  |  ---+
          |_______|___|            |_______|___|            |_______|___| |
                                                                        __v__
                                                                         ___
  
*/
void intCell_push_back ( ref_intCell front, int value )
{
     ref_intCell cursor = front;
     if ( cursor )
     {
        while ( intCell_getLink ( cursor ) )        // ( cursor->link )
        {
              cursor = intCell_getLink ( cursor ) ; //   cursor->link;
        } // end while
        intCell_connect ( cursor, intCell_newCell ( value ) );
     } // end if
} // end intCell_push_back ( ) 

/*
 cursor
     __
    |  |
    | ----+
    |__|  |
          |
    front |                                       
     __   v___________              ___________              ___________   
    |  |  |       |   |            |       |   |            |       |   |  
    | --->| value | x |            | value | y |            | value | z |  
    |__|  |-----------|            |-----------|            |-----------|  
          | link  |  ------------->| link  |  ------------->| link  |  ---+
          |_______|___|            |_______|___|            |_______|___| |
                                                                        __v__
                                                                         ___
  
 cursor
     __
    |  |
    | -----------------------------+
    |__|                           |
                                   |
    front                          |                                       
     __    ___________             v___________              ___________   
    |  |  |       |   |            |       |   |            |       |   |  
    | --->| value | x |            | value | y |            | value | z |  
    |__|  |-----------|            |-----------|            |-----------|  
          | link  |  ------------->| link  |  ------------->| link  |  ---+
          |_______|___|            |_______|___|            |_______|___| |
                                                                        __v__
                                                                         ___
  
 cursor
     __
    |  |
    | ------------------------------------------------------+
    |__|                                                    |
                                                            |
    front                                                   |              
     __    ___________              ___________             v___________   
    |  |  |       |   |            |       |   |            |       |   |  
    | --->| value | x |            | value | y |            | value | z |  
    |__|  |-----------|            |-----------|            |-----------|  
          | link  |  ------------->| link  |  ------------->| link  |  ---+
          |_______|___|            |_______|___|            |_______|___| |
                                                                        __v__
                                                                         ___

 cursor
     __
    |  |
    | ------------------------------------------------------+
    |__|                                                    |
                                                            |
    front                                              back |              
     __    ___________              ___________         __  v___________   
    |  |  |       |   |            |       |   |       |  | |       |   |  
    | --->| value | x |            | value | y |       | -->| value | z |  
    |__|  |-----------|            |-----------|       |__| |-----------|  
          | link  |  ------------->| link  |  ------------->| link  |  ---+
          |_______|___|            |_______|___|            |_______|___| |
                                                                        __v__
                                                                         ___

 cursor
     __
    |  |
    | ----+
    |__|  |
          |
    front |                                            back               
     __   v___________              ___________         __   ___________   
    |  |  |       |   |            |       |   |       |  | |       |   |  
    | --->| value | x |            | value | y |       | -->| value | z |  
    |__|  |-----------|            |-----------|       |__| |-----------|  
          | link  |  ------------->| link  |  ------------->| link  |  ---+
          |_______|___|            |_______|___|            |_______|___| |
                                                                        __v__
                                                                         ___

 cursor
     __
    |  |
    | -----------------------------+
    |__|                           |
                                   |
    front                          |                   back               
     __    ___________             v___________         __   ___________   
    |  |  |       |   |            |       |   |       |  | |       |   |  
    | --->| value | x |            | value | y |       | -->| value | z |  
    |__|  |-----------|            |-----------|       |__| |-----------|  
          | link  |  ------------->| link  |  ------------->| link  |  ---+
          |_______|___|            |_______|___|            |_______|___| |
                                                                        __v__
                                                                         ___

 cursor
     __
    |  |
    | -----------------------------+
    |__|                           |
                                   |
    front                          |                   back               
     __    ___________             v___________         __   ___________   
    |  |  |       |   |            |       |   |       |  | |       |   |  
    | --->| value | x |            | value | y |       | -->| value | z |  
    |__|  |-----------|            |-----------|       |__| |-----------|  
          | link  |  ------------->| link  |  ---+          | link  |  ---+
          |_______|___|            |_______|___| |          |_______|___| |
                                               __v__                    __v__
                                                ___                      ___

*/
ref_intCell intCell_pop_back ( ref_intCell front )
{
    ref_intCell cursor = front;
    ref_intCell back   = NULL ;
    if ( cursor )
    {
//       while ( intCell_getLink ( intCell_getLink ( cursor ) ) )
       while ( intCell_getLink ( cursor ) )
       {
             cursor = intCell_getLink ( cursor ) ; 
       } // end while
       back = cursor;
//       back = intCell_getLink ( cursor );
       cursor = front;
       while ( intCell_getLink ( cursor ) != NULL &&
               intCell_getLink ( cursor ) != back )
       {
             cursor = intCell_getLink ( cursor ) ; 
       } // end while
       if ( cursor != back )
       {
             intCell_disconnect ( cursor, back );
       } // end if
    } // end if
    return ( back );
} // end intCell_pop_back ( )
 
// ---

/*
  Example with C statements.
*/
void method_01 ( void )
{
 // definir dados
    ref_intCell a = NULL;
    
    printf ( "\nMethod_01\n" );
    a = malloc ( sizeof(intCell) );
    if ( a )
    {
        a->value = 1;
        a->link  = NULL;
        printf ( "\na = %d", a->value );
    } // end if
    printf ( "\n" );
} // end method_01 ( )

/*
  Example with intCell primitives.
*/
void method_02 ( void )
{
 // definir dados
    ref_intCell a = NULL;
    
    printf ( "\nMethod_02\n" );
    a = intCell_alloc ( );
    if ( a )
    {
       intCell_setValue ( a,   1  );
       intCell_setLink  ( a, NULL );
       printf ( "\na = %d", intCell_getValue ( a ) );
    } // end if
    printf ( "\n" );
} // end method_02 ( )

/*
  Example with intCell primitives and init method.
*/
void method_03 ( void )
{
 // definir dados
    ref_intCell a = NULL;
    
    printf ( "\nMethod_03\n" );
    a = intCell_alloc ( );
    if ( a )
    {
       intCell_init ( a, 1 );
       printf ( "\na = %d", intCell_getValue ( a ) );
    } // end if
    printf ( "\n" );
} // end method_03 ( )

/*
  Example with intCell primitives: newCell and printCell.
*/
void method_04 ( void )
{
 // definir dados
    ref_intCell a = NULL;

    a = intCell_newCell ( 1 ); // a = new intCell ( 1 );
    printf ( "\nMethod_04\n" );
    printf ( "\na = " );
    intCell_printCell ( a );
    printf ( "\n" );
} // end method_04 ( )

/*
    a                                a
   __    ___________                __    ___________
  |  |  |       |   |              |  |  |       |   |
  | --->| value | 1 |              | --->| value | 1 |
  |__|  |-----------|              |__|  |-----------|
        | link  |  ---+                  | link  |  ---+
        |_______|___| |                  |_______|___| |
                    __v__                              |
                     ___                 +-------------+
    b                                b   |           
   __    ___________                __   v___________
  |  |  |       |   |              |  |  |       |   |
  | --->| value | 2 |              | --->| value | 2 |
  |__|  |-----------|              |__|  |-----------|
        | link  |  ---+                  | link  |  ---+
        |_______|___| |                  |_______|___| |
                    __v__                            __v__
                     ___                              ___
                       
*/
void method_05 ( void )
{
     ref_intCell a = intCell_newCell ( 1 );
     ref_intCell b = intCell_newCell ( 2 );
    
     printf ( "\nMethod_05\n" );

     intCell_printCell ( a );
     intCell_printCell ( b );
     printf ( "\n" );

     if ( a )
     {
        a->link = b;
        printf ( "\na->link->value = " );
        intCell_printCell ( a->link );
     } // end if
     printf ( "\n" );
} // end method_05 ( )

/*
  Example with intCell primitive: connect.
*/
void method_06 ( void )
{
     ref_intCell a = intCell_newCell ( 1 );
     ref_intCell b = intCell_newCell ( 2 );
    
     printf ( "\nMethod_06\n" );

     intCell_printCell ( a );
     intCell_connect   ( a, b );
     intCell_printCell ( intCell_getLink ( a ) );
     printf ( "\n" );
} // end method_06 ( )

/*
  Example of intCell primitive: connect.
*/
void method_07 ( void )
{
     ref_intCell a = intCell_newCell ( 1 );
     ref_intCell b = intCell_newCell ( 2 );
    
     printf ( "\nMethod_06\n" );

     intCell_connect   ( a, b );
     intCell_print     ( a );
     printf ( "\n" );
} // end method_07 ( )

/*
  Example with intCell primitive: connect.
*/
void method_08 ( void )
{
     ref_intCell a = intCell_newCell ( 1 );
     ref_intCell b = intCell_newCell ( 2 );
    
     printf ( "\nMethod_08\n" );

     intCell_connect ( a, b );
     intCell_connect ( b, intCell_newCell ( 3 ) );
     intCell_connect ( b->link, intCell_newCell ( 4 ) );
     intCell_connect ( b->link->link, intCell_newCell ( 5 ) );
     intCell_print   ( a );
     printf ( "\n" );
} // end method_08 ( )

/*
  Example with intCell primitive: connect.
*/
void method_09 ( void )
{
     ref_intCell a = intCell_newCell ( 1 );
     ref_intCell b = intCell_newCell ( 2 );
    
     printf ( "\nMethod_08\n" );

     intCell_connect ( a, b );
     intCell_connect ( b, 
                       intCell_newCell ( 3 ) );
     intCell_connect ( intCell_getLink ( b ), 
                       intCell_newCell ( 4 ) );
     intCell_connect ( intCell_getLink ( intCell_getLink (b)), 
                       intCell_newCell ( 5 ) );
     intCell_print   ( a );
     printf ( "\n" );
} // end method_09 ( )

/*
  Example with intCell primitive: push_back.
*/
void method_10 ( void )
{
     ref_intCell a = intCell_newCell ( 1 ); 
       
     printf ( "\nMethod_10\n" );

     intCell_push_back ( a, 2 );
     intCell_push_back ( a, 3 );
     intCell_push_back ( a, 4 );
     intCell_push_back ( a, 5 );
     intCell_print     ( a );
     printf ( "\n" );
} // end method_10 ( )

/*
  Example with intCell primitive: push_back and pop_back.
*/
void method_11 ( void )
{
     ref_intCell a = intCell_newCell ( 1 ); 
     ref_intCell b = NULL; 
       
     printf ( "\nMethod_10\n" );

     intCell_push_back ( a, 2 );
     intCell_push_back ( a, 3 );
     intCell_push_back ( a, 4 );
     intCell_push_back ( a, 5 );
     intCell_print     ( a );
     printf ( "\n" );

     while ( intCell_getLink ( a ) )
     { 
          b = intCell_pop_back ( a );
          intCell_printCell ( b );
          getchar ( );
     } // end while
        printf ( "\n" );
} // end method_11 ( )

/*
  Example with intCell primitive: length.
*/
void method_12 ( void )
{
     int x = 0;
     ref_intCell a = intCell_newCell ( 1 ); 
     ref_intCell b = NULL; 
       
     printf ( "\nMethod_12\n" );

     for ( x=2; x<=5; x=x+1 )
     { 
         intCell_push_back ( a, x );
         intCell_print     ( a );
         printf ( "\n" );
     } // end for
     printf ( "\n" );

     x = intCell_length ( a ); 
         printf ( "\nlength(a) = %d\n", x );

     while ( x > 0 )
     { 
         b = intCell_pop_back ( a );
         intCell_printCell ( b );
         getchar ( );
         x = x - 1;
     } // end while
     printf ( "\n" );
     intCell_print     ( a );
} // end method_12 ( )

// ---

int main ( void )
{
 // dados/resultados
    int option = 0;
     
 // identificar
    printf ( "999999_AED1\n");

 // acoes
    do
    {
        printf ( "\nOpcao? " );
        scanf  ( "%d", &option );
        getchar( );
        switch ( option )
        {
               case  0:               break;
               case  1: method_01( ); break;
               case  2: method_02( ); break;
               case  3: method_03( ); break;
               case  4: method_04( ); break;
               case  5: method_05( ); break;
               case  6: method_06( ); break;
               case  7: method_07( ); break;
               case  8: method_08( ); break;
               case  9: method_09( ); break;
               case 10: method_10( ); break;
               case 11: method_11( ); break;
               case 12: method_12( ); break;
               default:               break;
        } // end switch
    }
    while ( option != 0 );
    
 // encerrar
    printf ( "\nApertar ENTER para terminar.\n" );
    getchar( );   
    return (0);
} // end main ( )
