
#include "karel.hpp"
#include "io.hpp"
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{

int w = 3;
 while (7>=w)
 {
    world->set(1, w, VWALL);
    
    world->set(4, w, VWALL);
    
    world->set(5, w, VWALL);
    
    world->set(8, w, VWALL);
    w = w +1;
 }

int a = 2;
 while ( 4 >= a )
 {
    world->set(a, 2, HWALL);
    
    world->set(a, 7, HWALL);
    
    a = a +1;
 }

  a = 6;
 while ( 8 >= a )
 {
    world->set(a, 2, HWALL);
    
    world->set(a, 7, HWALL);
    
    a = a +1;
 }

 world->set ( 1, 5, BEEPER );
 world->set ( 3, 2, BEEPER );
 world->set ( 3, 8, BEEPER );


 world->save( fileName );
} 

 
class MyRobot : public Robot
{
 public:
 
 void turnRight ( )
 {
 // definir dado local
 int step = 0;
 // testar se o robo esta' ativo
 if ( checkStatus ( ) )
 {
 // o agente que executar esse metodo
 // devera' virar tres vezes 'a esquerda
 for ( step = 1; step <= 3; step = step + 1 )
 {
 turnLeft( );
 } // end for
 } // end if
 } // end turnRight ( )
 /**
 execute - Metodo para executar um comando.
 @param action - comando a ser executado
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
   void recordActions(const char *fileName)
   {
      // definir dados
      int action;
      // definir arquivo onde gravar comandos
      std::ofstream archive(fileName);
      // ler acao
      action = IO_readint("Command? ");
      // repetir enquanto acao maior ou igual a zero
      while (action >= 0)
      {
         // testar se opcao valida
         if (0 <= action && action <= 9)
         {
            // executar comando
            execute(action);
            // guardar o comando em arquivo
            archive << action << "\n";
         } // end if
         // ler acao
         action = IO_readint("Command? ");
      } // end while
      // fechar o arquivo
      // INDISPENSAVEL para a gravacao
      archive.close();
   } // end recordActions ( )
/**
 metodo para executar comandos de arquivo.
 @param length - quantidade de comandos
 @param commands - grupo de comandos para executar
*/
void appendActions(const char *fileName)
   {
      // definir dados
      int action;
      // definir arquivo para receber acrescimos ao final
      std::fstream archive(fileName, std::ios::app);
      // repetir enquanto acao diferente de zero
      do
      {
         // ler acao
         action = IO_readint("Command? ");
         // testar se opcao valida
         if (0 <= action && action <= 9)
         {
            // executar comando
            execute(action);
            // guardar o comando em arquivo
            archive << action << std::endl;
         } // end if
      } while (action != 0);
      // fechar o arquivo
      // INDISPENSAVEL para a gravacao
      archive.close();
   } // end appendActions ( )
  void translateActions(const char *fileName)
   {
      // definir dados
      int action;
      // definir arquivo de onde ler dados
      std::ifstream archive(fileName);
      // repetir enquanto houver dados
      archive >> action;     // tentar ler a primeira linha
      while (!archive.eof()) // testar se nao encontrado o fim
      {
         // tentar traduzir um comando
         IO_print(dictionary(action));
         getchar();
         // guardar mais um comando
         execute(action);
         // tentar ler a proxima linha
         archive >> action; // tentar ler a proxima linha
      }                     // end for
                            // fechar o arquivo
                            // RECOMENDAVEL para a leitura
      archive.close();
   } // end translateActions ( )

 void moveI()
   {
      // definir dados
      int action;
      // repetir (com testes no fim)
      // enquanto opcao diferente de zero
      do
      {
         // ler opcao
         action = IO_readint("Command? ");
         // executar acao dependente da opcao
         execute(action);
      } while (action != 0);
   } // end moveI( )

chars dictionary(int action)
   {
      // definir dado
      static char word[80];
      strcpy(word, ""); // palavra vazia
      // identificar comando
      switch (action)
      {
      case 1: // virar para a esquerda
         strcpy(word, "turnLeft( ); ");
         break;
      case 2: // virar para o sul
         strcpy(word, "faceSouth( ); ");
         break;
      case 3: // virar para a direita
         strcpy(word, "turnRight( ); ");
         break;
      case 4: // virar para o oeste
         strcpy(word, "faceWest( ); ");
         break;
      case 5: // mover
         strcpy(word, "move( ); ");
         break;
      case 6: // virar para o leste
         strcpy(word, "faceEast( ); ");
         break;
      case 7: // pegar marcador
         strcpy(word, "pickBeeper( );");
         break;
      case 8: // virar para o norte
         strcpy(word, "faceNorth( ); ");
         break;
      case 9: // colocar marcador
         strcpy(word, "putBeeper( ); ");
         break;
      } // end switch
      // retornar palavra equivalente
      return (&(word[0]));
   } // end dictionary( )

void playActions ( const char *fileName )
   {
      // definir dados
      int action;
      // definir arquivos de onde ler dados
      std::ifstream archive(fileName);
      // repetir enquanto houver dados
      archive >> action;     // tentar ler a primeira linha
      while (!archive.eof()) // testar se nao encontrado o fim
      {
         // mostrar mais um comando
         IO_print(IO_toString(action));
         // executar mais um comand
         execute(action);
         delay(stepDelay);
         // tentar ler a proxima linha
         archive >> action; // tentar ler a próxima linha
      }                     // end for
      // fechar o arquivo
      // RECOMENDAVEL para a leitura
      archive.close();
   } // end playActions ( )



}; // end class MyRobot
// --------------------------- acao principal


int main ( )
{

 world->create ( "" ); // criar o mundo
 decorateWorld ( "Guia0311.txt" );
 world->show ( );
// preparar o ambiente para uso
 world->reset ( ); // limpar configuracoes
 world->read ( "Guia0311.txt" );
 world->show ( ); // mostrar a configuracao atual
 set_Speed ( 0.5 ); // definir velocidade padrao
// criar robo
  MyRobot *robot = new MyRobot( );
 robot->create ( 1, 1, EAST, 0, "Karel" );

// executar tarefa
 
 robot-> recordActions ( "Tarefa0311.txt" );
 robot-> playActions ( "Tarefa0311.txt" );

// encerrar operacoes no ambiente
 world->close ( );
// encerrar programa
 getchar ( );
 return ( 0 );
} 