
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

   world->set(5, 3, BEEPER);
   world->set(5, 3, BEEPER);
   world->set(5, 3, BEEPER);
   world->set(4, 3, BEEPER);
   world->set(4, 3, BEEPER);
   world->set(3, 3, BEEPER);

   // save world
   world->save(fileName);

} // decorateWorld ( )

class MyRobot : public Robot
{
public:
   // fazer turnright
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

   void doTask()
   {

      move();
      turnLeft();
      move();

      while (!areYouHere(3, 8))
      {
         move();
         if (rightIsClear())
         {
            turnRight();
         }
      }

      turnLeft();
      move();

      while (!areYouHere(3, 3))
      {
         move();

         if (nextToABeeper())
         {
            pickBeeper();
            turnLeft();
            turnLeft();
            move();
            break;
         }
      }

      while (!areYouHere(5, 8))
      {
         move();
         if (rightIsClear())
         {
            turnRight();
         }
         if (nextToABeeper())
         {
            pickBeepers();
            turnLeft();
            turnLeft();
         }
      }
      move();

      while (!areYouHere(5, 8))
      {
         move();

         if (nextToABeeper())
         {
            pickBeepers();
            turnLeft();
            turnLeft();
         }
      }

      turnLeft();

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

   set_Speed(0.5);

   // put robot on the stage
   robot->create(1, 1, EAST, 0, "Karel");

   // execute action
   robot->doTask();

   // world shutdown
   world->close();

   //  program shutdown
   getchar();
   return (0);
} // end main ( )