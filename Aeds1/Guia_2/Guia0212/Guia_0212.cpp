
#include "karel.hpp"
#include "io.hpp"

// --------------------------- methods section

/**
   Put objects in the world.
 */
void decorateWorld(const char *fileName)
{
   // parte de baixo dos quadrados
   world->set(2, 1, HWALL);
   world->set(3, 1, HWALL);
   world->set(4, 1, HWALL);

   world->set(6, 1, HWALL);
   world->set(7, 1, HWALL);
   world->set(8, 1, HWALL);

   world->set(2, 5, HWALL);
   world->set(3, 5, HWALL);
   world->set(4, 5, HWALL);

   world->set(6, 5, HWALL);
   world->set(7, 5, HWALL);
   world->set(8, 5, HWALL);

   // parte vertical de dentro
   world->set(4, 2, VWALL);
   world->set(4, 3, VWALL);

   world->set(5, 3, VWALL);
   world->set(5, 2, VWALL);

   world->set(4, 7, VWALL);
   world->set(4, 8, VWALL);

   world->set(5, 7, VWALL);
   world->set(5, 8, VWALL);

   world->set(4, 5, VWALL);
   world->set(5, 5, VWALL);

   // parte de cima dos quadrados
   world->set(2, 4, HWALL);
   world->set(3, 4, HWALL);
   world->set(4, 4, HWALL);

   world->set(6, 4, HWALL);
   world->set(7, 4, HWALL);
   world->set(8, 4, HWALL);

   world->set(2, 8, HWALL);
   world->set(3, 8, HWALL);
   world->set(4, 8, HWALL);

   world->set(6, 8, HWALL);
   world->set(7, 8, HWALL);
   world->set(8, 8, HWALL);

   // parte vertical de fora
   world->set(1, 2, VWALL);
   world->set(1, 3, VWALL);
   world->set(1, 4, VWALL);

   world->set(8, 3, VWALL);
   world->set(8, 2, VWALL);
   world->set(8, 4, VWALL);

   world->set(1, 7, VWALL);
   world->set(1, 8, VWALL);
   world->set(1, 6, VWALL);

   world->set(8, 7, VWALL);
   world->set(8, 8, VWALL);
   world->set(8, 6, VWALL);

   // 2 linhas no meio
   world->set(5, 6, HWALL);
   world->set(5, 3, HWALL);

   // put beepers
   world->set(5, 3, BEEPER);
   world->set(5, 7, BEEPER);
   world->set(4, 5, BEEPER);
   world->set(6, 5, BEEPER);

   // save world
   world->save(fileName);

} // decorateWorld ( )

class MyRobot : public Robot
{
public:
   /**
      Turn robot direction to right.
    */
   void turnRight()
   {
      // test if robot is active
      if (checkStatus())
      {
         int step = 1;
         while (step <= 3)
         {
            turnLeft();
            step = step + 1;
         }

      } // end if
   }    // end turnRight ( )

   void moveN(int steps)
   {
      // definir dado local
      int step = 0;
      // testar se a quantidade de passos e' maior que zero
      for (step = steps; step > 0; step = step - 1)
      {
         // dar um passo
         move();
      } // end if
   }    // end moveN( )

   void doTask()
   {

      move();
      while (!areYouHere(1, 1))
      {
         move();
         if (rightIsClear())
         {
            turnRight();
            
         }
         if (nextToABeeper())
         {
            pickBeeper ();
            turnLeft ();
            turnLeft ();
            
         }
      }

   } // end doTask ( )

}; // end class MyRobot

// --------------------------- main action

int main()
{
   // define context
   MyRobot *robot = new MyRobot();

   // set the stage and decorate with objects

   world->create("");
   decorateWorld("Guia_00.txt");
   world->show();

   world->reset();
   world->read("Guia_00.txt");
   world->show();

   set_Speed(2);

   // put robot on the stage
   robot->create(1, 1, NORTH, 0, "Karel");

   // execute action
   robot->doTask();

   // world shutdown
   world->close();

   //  program shutdown
   getchar();
   return (0);
} // end main ( )