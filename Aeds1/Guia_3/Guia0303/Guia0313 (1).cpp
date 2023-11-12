
#include "karel.hpp"
#include "io.hpp"
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld(const char *fileName)
{
   // VWALL
   int w = 4;
   while (8 >= w)
   {
      world->set(1, w, VWALL);
      

      w = w + 1;
   }

    w = 4;
   while (7 >= w)
   {
   
      world->set(7, w, VWALL);

      w = w + 1;
   }

   w = 5;
   while (7 >= w)
   {
      world->set(2, w, VWALL);

      w = w + 1;
   }
   world->set(6, 6, VWALL);
   world->set(6, 5, VWALL);
   world->set(4, 7, VWALL);
   world->set(5, 7, VWALL);
   world->set(3, 6, VWALL);
   world->set(3, 5, VWALL);

   // HWALL
   int a = 2;
   while (7 >= a)
   {
      world->set(a, 3, HWALL);

      world->set(a, 8, HWALL);

      a = a + 1;
   }

   world->set(3, 7, HWALL);
   world->set(6, 6, HWALL);
   world->set(4, 6, HWALL);
  world->set(4, 7, HWALL);
 
   a = 5;
   while (7 >= a)
   {
      world->set(a, 7, HWALL);

      a = a + 1;
   }
   a = 5;
   while (6 >= a)
   {
      world->set(a, 4, HWALL);

      a = a + 1;
   }

   // beepers

   world->set(4, 7, BEEPER);
   world->set(5, 7, BEEPER);
   world->set(5, 7, BEEPER);
   world->set(6, 7, BEEPER);
   world->set(6, 7, BEEPER);
   world->set(6, 7, BEEPER);

   world->save(fileName);
}

class MyRobot : public Robot
{
public:
   void turnRight()
   {
      // definir dado local
      int step = 0;
      // testar se o robo esta' ativo
      if (checkStatus())
      {
         // o agente que executar esse metodo
         // devera' virar tres vezes 'a esquerda
         for (step = 1; step <= 3; step = step + 1)
         {
            turnLeft();
         } // end for
      }    // end if
   }       // end turnRight ( )
           /**
           execute - Metodo para executar um comando.
           @param action - comando a ser executado
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
         if (0 <= action && action <= 11)
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
         if (0 <= action && action <= 11)
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


int main()
{

   world->create(""); // criar o mundo
   decorateWorld("Guia0313.txt");
   world->show();
   // preparar o ambiente para uso
   world->reset(); // limpar configuracoes
   world->read("Guia0313.txt");
   world->show();  // mostrar a configuracao atual
   set_Speed(0.5); // definir velocidade padrao
                   // criar robo
   MyRobot *robot = new MyRobot();
   robot->create(1, 1, EAST, 0, "Karel");

   // executar tarefa

   robot->recordActions("Tarefa0313.txt");
   robot->playActions("Tarefa0313.txt");

   // encerrar operacoes no ambiente
   world->close();
   // encerrar programa
   getchar();
   return (0);
}