
#include "karel.hpp"
#include "io.hpp"

// --------------------------- methods section

/**
   Put objects in the world.
 */
void decorateWorld(const char *fileName)
{
   // paredes verticais de fora
   for (int i = 3; i <= 8; i = i + 1)
   {
      world->set(2, i, VWALL);
   }

   int mm = 3;
   while (mm <= 8)
   {
      world->set(5, mm, VWALL);
      mm = mm + 1;
   }

   // paredes verticais de dentro

   mm = 3;
   while (mm <= 7)
   {

      world->set(3, mm, VWALL);
      world->set(4, mm, VWALL);
      mm = mm + 1;
   }

   // paredes horizontais
   mm = 3;
   while (mm <= 5)
   {
      world->set(mm, 2, HWALL);
      mm = mm + 1;
   }

   world->set(3, 8, HWALL);
   world->set(5, 8, HWALL);

   // put beepers
   world->set(3, 3, BEEPER);
   world->set(3, 4, BEEPER);
   world->set(3, 4, BEEPER);
   world->set(3, 5, BEEPER);
   world->set(3, 5, BEEPER);
   world->set(3, 5, BEEPER);
   world->set(4, 4, BEEPER);
   world->set(4, 4, BEEPER);
   world->set(4, 3, BEEPER);
   world->set(5, 3, BEEPER);

   // save world
   world->save(fileName);

} // decorateWorld ( )

class MyRobot : public Robot
{
public:
   /* execute
    * execute - Metodo para executar um comando.
    * @param action - comando a ser executado
    */
   void execute(int option)
   {
      // executar a opcao de comando
      switch (option)
      {
      case 0: // terminar
         // nao fazer nada
         break;
      case 1: // virar para a esquerda
         if (leftIsClear())
         {
            turnLeft();
         } // end if
         break;
      case 2: // virar para o sul
         while (!facingSouth())
         {
            turnLeft();
         } // end while
         break;
      case 3: // virar para a direita
         if (rightIsClear())
         {
            turnRight();
         } // end if
         break;
      case 4: // virar para o oeste
         while (!facingWest())
         {
            turnLeft();
         } // end while
         break;
      case 5: // mover
         if (frontIsClear())
         {
            move();
         } // end if
         break;
      case 6: // virar para o leste
         while (!facingEast())
         {
            turnLeft();
         } // end while
         break;
      case 7: // pegar marcador
         if (nextToABeeper())
         {
            pickBeeper();
         } // end if
         break;
      case 8: // virar para o norte
         while (!facingNorth())
         {
            turnLeft();
         } // end while
         break;
      case 9: // colocar marcador
         if (beepersInBag())
         {
            putBeeper();
         } // end if
         break;
      default: // nenhuma das alternativas anteriores
         // comando invalido
         show_Error("ERROR: Invalid command.");
      } // end switch
   }    // end execute( )
   /*
    append actions
    appendActions - Metodo para acrescentar comandos ao arquivo e traduzi-los.
    @param filename - nome do arquivo
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
   /*
    playActions
    playActions - metodo para receber comandos de arquivo.
    @param fileName - nome do arquivo
   */
/*
   void playActions(const char *fileName)
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
         delay(stepDelay);
         // executar mais um comando
         execute(action);
         // tentar ler a proxima linha
         archive >> action; // tentar ler a próxima linha
      }                     // end for
      // fechar o arquivo
      // RECOMENDAVEL para a leitura
      archive.close();
   } // end playActions ( )
*/
   /*
    * recordActions - Metodo para mover o robot interativamente
    * e guardar a descricao da tarefa em arquivo.
    * @param fileName - nome do arquivo
    */
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
     /*
      Movel
      * moveI - Metodo para mover o robot interativamente.
      * Lista de comandos disponiveis:
      * 0 - turnOff
      * 1 - turnLeft 2 - to South
      * 3 - turnRight 4 - to West
      * 5 - move 6 - to East
      * 7 - pickBeeper 8 - to North
      * 9 - putBeeper
      */
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
     /*
      dictionary
      * dictionary - Metodo para traduzir um comando.
      * @param action - comando a ser traduzido
      */
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

   /*
    translateActions - Metodo para receber comandos de arquivo e traduzi-los.
    @param fileName - nome do arquivo
   */
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

   void turnRight()
   {

      if (checkStatus())
      {
         int step = 1;
         while (step <= 3)
         {
            turnLeft();
            step = step + 1;
         }
      }
   }

   // fazer pickBeeperS
   void pickBeepers()
   {

      while (nextToABeeper())
      {
         pickBeeper();
      }
   }

   // Fazer putBeeperS
   void putBeepers()

   {
      while (beepersInBag())
      {
         putBeeper();
      }
   }

   // acao
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

// --------------------------- main action

int main()
{
   // define context
   MyRobot *robot = new MyRobot();
   // set the stage and decorate with objects

   world->create("");
   decorateWorld("Guia_0210.txt");
   world->show();

   world->reset();
   world->read("Guia_0210.txt");
   world->show();

   set_Speed(0.5);

   // put robot on the stage
   robot->create(1, 1, EAST, 0, "Karel");

   // execute action
robot-> recordActions ( "Tarefa0215.txt" );
robot-> playActions ( "Tarefa0215.txt" );

   // world shutdown
   world->close();
   //  program shutdown
   getchar();
   return (0);
} // end main ( )