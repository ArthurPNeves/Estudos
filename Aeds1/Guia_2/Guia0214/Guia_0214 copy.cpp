
#include "karel.hpp"
#include "io.hpp" 
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
   // paredes verticais de fora
   for (int i = 3; i <= 8; i = i + 1)
   {
      world->set(2, i, VWALL);
   }

   int x = 3;
   while (x <= 8)
   {
      world->set(5, x, VWALL);
      x = x + 1;
   }

   // paredes verticais de dentro

   x = 3;
   while (x <= 7)
   {

      world->set(3, x, VWALL);
      world->set(4, x, VWALL);
      x = x + 1;
   }

   // paredes horizontais
   x = 3;
   while (x <= 5)
   {
      world->set(x, 2, HWALL);
      x = x + 1;
   }

   world->set(3, 8, HWALL);
   world->set(5, 8, HWALL);

   // put beepers
   world->set(5, 5, BEEPER);
   world->set(5, 4, BEEPER);
   world->set(5, 4, BEEPER);
   world->set(5, 3, BEEPER);
   world->set(5, 3, BEEPER);
   world->set(5, 3, BEEPER);
   world->set(4, 3, BEEPER);
   world->set(4, 3, BEEPER);
   world->set(4, 4, BEEPER);
   world->set(4, 4, BEEPER);
   world->set(4, 3, BEEPER);
   world->set(3, 3, BEEPER);
   world->set(3, 3, BEEPER);
   world->set(3, 3, BEEPER);

 world->save( fileName );

} // decorateWorld ( )
/**
 Classe para definir robo particular (MyRobot),
 a partir do modelo generico (Robot)
 Nota: Todas as definicoes irao valer para qualquer outro robo
 criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
{
 public:
 
/**
 * execute - Metodo para executar um comando.
 * @param action - comando a ser executado
 */
 void execute( int option )
 {
 // executar a opcao de comando
 switch ( option )
 {
 case 0: // terminar
 // nao fazer nada
 break;
 case 1: // virar para a esquerda
 if ( leftIsClear ( ) )
 {
 turnLeft( );
 } // end if
 break;
 case 2: // virar para o sul
 while ( ! facingSouth( ) )
 {
 turnLeft( );
 } // end while
 break;
 case 3: // virar para a direita
 if ( rightIsClear ( ) )
 {
 turnRight( );
 } // end if
 break;

 case 4: // virar para o oeste
 while ( ! facingWest( ) )
 {
 turnLeft( );
 } // end while
 break;
 case 5: // mover
 if ( frontIsClear ( ) )
 {
 move( );
 } // end if
 break;
 case 6: // virar para o leste
 while ( ! facingEast( ) )
 {
 turnLeft( );
 } // end while
 break;
 case 7: // pegar marcador
 if ( nextToABeeper( ) )
 {
 pickBeeper( );
 } // end if
 break;
 case 8: // virar para o norte
 while ( ! facingNorth( ) )
 {
 turnLeft( );
 } // end while
 break;
 case 9: // colocar marcador
 if ( beepersInBag( ) )
 {
 putBeeper( );
 } // end if
 break;
 default:// nenhuma das alternativas anteriores
 // comando invalido
 show_Error ( "ERROR: Invalid command." );
 } // end switch
 } // end execute( )

 /**
 * moveI - Metodo para mover o robot interativamente.
 * Lista de comandos disponiveis:
 * 0 - turnOff
 * 1 - turnLeft 2 - to South
 * 3 - turnRight 4 - to West
 * 5 - move 6 - to East
 * 7 - pickBeeper 8 - to North
 * 9 - putBeeper
 */
 void moveI( )
 {
 // definir dados
 int action;
 // repetir (com testes no fim)
 // enquanto opcao diferente de zero
 do
 {
 // ler opcao
 action = IO_readint ( "Command? " );
 // executar acao dependente da opcao
 execute ( action );
 }
 while ( action != 0 );
 } // end moveI( )

/**
 * 
 * recordActions - Metodo para mover o robot interativamente
 * e guardar a descricao da tarefa em arquivo.
 * @param fileName - nome do arquivo

 void recordActions ( const char * fileName )
 {
 // definir dados
 int action;
 // definir arquivo onde gravar comandos
 std::ofstream archive ( fileName );
 // ler acao
 action = IO_readint ( "Command? " );
 // repetir enquanto acao maior ou igual a zero
 while ( action >= 0 )
 {
 // testar se opcao valida
 if ( 0 <= action && action <= 9 )
 {
 // executar comando
 execute ( action );
 // guardar o comando em arquivo
 archive << action << "\n";
 } // end if
 // ler acao
 action = IO_readint ( "Command? " );
 } // end while
 // fechar o arquivo
 // INDISPENSAVEL para a gravacao
 archive.close ( );
 } // end recordActions ( )
 

/**
 playActions - metodo para receber comandos de arquivo.
 @param fileName - nome do arquivo
*/
void playActions ( const char *fileName )
{
 // definir dados
 int action;
 // definir arquivos de onde ler dados
 std::ifstream archive ( fileName );
 // repetir enquanto houver dados
 archive >> action; // tentar ler a primeira linha
 while ( ! archive.eof ( ) ) // testar se nao encontrado o fim
 {
 // mostrar mais um comando
 IO_print( IO_toString ( action ) );
 delay ( stepDelay );
 // executar mais um comando
 execute ( action ) ;
 // tentar ler a proxima linha
 archive >> action ; // tentar ler a próxima linha
 } // end for
 // fechar o arquivo
 // RECOMENDAVEL para a leitura
 archive.close ( );
} // end playActions ( )

/**
 * dictionary - Metodo para traduzir um comando.
 * @param action - comando a ser traduzido
 */
 chars dictionary( int action )
 {
 // definir dado
 static char word [80];
 strcpy ( word, "" ); // palavra vazia
 // identificar comando
 switch ( action )
 {
 case 1: // virar para a esquerda
 strcpy ( word, "turnLeft( ); " );
 break;
 case 2: // virar para o sul
 strcpy ( word, "faceSouth( ); " );
 break;
 case 3: // virar para a direita
 strcpy ( word, "turnRight( ); " );
 break;
 case 4: // virar para o oeste
 strcpy ( word, "faceWest( ); " );
 break;
 case 5: // mover
 strcpy ( word, "move( ); " );
 break;
 case 6: // virar para o leste
 strcpy ( word, "faceEast( ); " );
 break;
 case 7: // pegar marcador
 strcpy ( word, "pickBeeper( );" );
 break;
 case 8: // virar para o norte
 strcpy ( word, "faceNorth( ); " );
 break;
 case 9: // colocar marcador
 strcpy ( word, "putBeeper( ); " );
 break;
 } // end switch
 // retornar palavra equivalente
 return ( &(word[0]) );
 } // end dictionary( )

/**
 translateActions - Metodo para receber comandos de arquivo e traduzi-los.
 @param fileName - nome do arquivo
*/
void translateActions ( const char *fileName )
{
// definir dados
 int action;
// definir arquivo de onde ler dados
 std::ifstream archive ( fileName );
// repetir enquanto houver dados
 archive >> action; // tentar ler a primeira linha
 while ( ! archive.eof( ) ) // testar se nao encontrado o fim
 {
 // tentar traduzir um comando
 IO_print ( dictionary ( action ) );
 getchar ( );
 // guardar mais um comando
 execute ( action );
 // tentar ler a proxima linha
 archive >> action ; // tentar ler a proxima linha
 } // end for
// fechar o arquivo
// RECOMENDAVEL para a leitura
 archive.close ( );
} // end translateActions ( )

/**
 appendActions - Metodo para acrescentar comandos ao arquivo e traduzi-los.
 @param filename - nome do arquivo
*/
void appendActions ( const char *fileName )
{
// definir dados
 int action;
// definir arquivo para receber acrescimos ao final
 std::fstream archive ( fileName, std::ios::app );
// repetir enquanto acao diferente de zero
 do
 {
 // ler acao
 action = IO_readint ( "Command? " );
 // testar se opcao valida
 if ( 0 <= action && action <= 9 )
 {
 // executar comando
 execute ( action );
 // guardar o comando em arquivo
 archive << action << std::endl;
 } // end if
 }
 while ( action != 0 );
// fechar o arquivo
// INDISPENSAVEL para a gravacao
 archive.close ( );
} // end appendActions ( )

 void turnRight ( )
 {
 // definir dado local
 int step = 0;
 // testar se o robo esta' ativo
 if ( checkStatus ( ) )
 {

 
 for ( step = 1; step <= 3; step = step + 1 )
 {
 turnLeft( );
 } 
 } 
 } 

 /**
 * pickBeepers - Funcao para coletar marcadores.
 * @return quantidade de marcadores coletados
 */
 int pickBeepers ( )
 {
 // definir dado local
 int n = 0;
 // repetir (com teste no inicio)
 // enquanto houver marcador proximo
 while ( nextToABeeper ( ) )
 {
 // coletar um marcador
 pickBeeper ( );
 // contar mais um marcador coletado
 n = n + 1;
 } // end while
 // retornar a quantidade de marcadores coletados
 return ( n );
 } // end pickBeepers( )

// Fazer putBeeperS
   void putBeepers()

   {
      while (beepersInBag())
      {
         putBeeper();
      }
   }
 
 /**
 doTask - Relacao de acoes para o robo executar.
 */
void doTask()
   {
   
   int xx, yy;
xx = xAvenue( ); // obter posicao atual (avenue)
yy = yStreet( ); // obter posicao atual ( street )
std::ofstream arquivo ( "Tarefa0214b.txt" );

      move();
      turnLeft();
      move();

      while (!areYouHere(4, 8))
      {
         move();
         if (rightIsClear())
         {
            turnRight();
         }
      }
      turnLeft ();
      turnLeft();
      move();
      turnRight();

      while (!areYouHere(5, 3))
      {
         move();

         if (nextToABeeper())
         {
            pickBeepers();
            xx = xAvenue( ); 
            yy = yStreet( ); 
            arquivo << xx << std::endl;
            arquivo << yy << std::endl;
         }
      }
      turnLeft ();
      turnLeft ();

      while (!areYouHere(4, 3))
      {
         move();
         if (leftIsClear())
         {
            turnLeft();
         }
         if (nextToABeeper())
         {
            pickBeepers();
            xx = xAvenue( ); 
            yy = yStreet( ); 
            arquivo << xx << std::endl;
            arquivo << yy << std::endl;
        
         }
      }
      turnLeft ();
      turnLeft ();
      
      while (!areYouHere(3, 7))
      {
         move();
         if (leftIsClear())
         {
            turnLeft();
         }
      }

      while (!areYouHere(4, 8))
      {
         move();

        if (rightIsClear())
         {
            turnRight();
         }
         if (nextToABeeper())
         {
            pickBeepers();
            xx = xAvenue( ); 
            yy = yStreet( ); 
            arquivo << xx << std::endl;
            arquivo << yy << std::endl;

            turnLeft();
            turnLeft ();

         }
      }

      turnLeft ();
      turnLeft ();
       while (!areYouHere(6, 2))
      {
         move();

        if (rightIsClear())
         {
            turnRight();
         }
         
      }


      turnLeft();
      move();
      turnLeft();

      while (!areYouHere(9, 1))
      {
         move();

         if (areYouHere(9, 1))
         {
            putBeepers();
            turnLeft();
            turnLeft();
            move();
         }
         if (areYouHere(1, 1))
         {
            turnLeft();
            turnLeft();
            break;
         }
         

arquivo.close ( );
      }

   
   } // end doTask ( )

}; // end class MyRobot


/**
 Acao principal: executar a tarefa descrita acima.
*/
int main ( )
{
// definir o contexto
// criar o ambiente e decorar com objetos
// OBS.: executar pelo menos uma vez,
// antes de qualquer outra coisa
// (depois de criado, podera' ser comentado)
 world->create ( "" ); // criar o mundo
 decorateWorld ( "Guia0201.txt" );
 world->show ( );
// preparar o ambiente para uso
 world->reset ( ); // limpar configuracoes
 world->read ( "Guia0201.txt" );// ler configuracao atual para o ambiente
 world->show ( ); // mostrar a configuracao atual
 set_Speed ( 0.5 ); // definir velocidade padrao
// criar robo
 MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
 robot->create ( 1, 1, EAST, 0, "Karel" );
// executar tarefaaaaaa
 robot->doTask ( );
// encerrar operacoes no ambiente
 world->close ( );



 getchar ( );
 return ( 0 );
} // end main ( )

