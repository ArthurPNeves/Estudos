
#include "karel.hpp"

// --------------------------- methods section

/**
   Put objects in the world.
 */
void decorateWorld ( const char* fileName )
{
 // create wall
   
world->set (  8,  1, VWALL  );
world->set (  8,  2, VWALL  );
world->set (  8,  3, VWALL  );

world->set (  8,  3, HWALL  );


 // create Box
world->set (  7,  5, VWALL  );
world->set (  7,  4, VWALL  );
world->set (  7,  3, VWALL  );


world->set (  2,  5, VWALL  );
world->set (  2,  4, VWALL  );
world->set (  2,  3, VWALL  );
world->set (  2,  6, VWALL  );

world->set (  5,  2, HWALL  );
world->set (  6,  2, HWALL  );
world->set (  3,  2, HWALL  );
world->set (  4,  2, HWALL  );
world->set (  7,  2, HWALL  );

world->set (  5,  6, HWALL  );
world->set (  6,  6, HWALL  );
world->set (  3,  6, HWALL  );
world->set (  4,  6, HWALL  );
world->set (  7,  6, HWALL  );

 // put beepers
     world->set (  2,  3, BEEPER );
     world->set (  3,  7, BEEPER );
     world->set (  8,  3, BEEPER );

 // save world
    world->save( fileName );

} // decorateWorld ( )

class MyRobot : public Robot
{
  public:

  /**
     Turn robot direction to right.
   */
     void turnRight ( )
     {
      // test if robot is active
         if ( checkStatus ( ) )
         {
            turnLeft ( );
            turnLeft ( );
            turnLeft ( );
         } // end if
     } // end turnRight ( )

  /**
     stepUp - Climb one step at a time (sub-action).
   */
     void stepUp ( )
     {
        turnLeft ( );
        move ( );
        turnRight ( );
        move ( );
     } // end stepUp ( )

  /**
     stepDown - one step at a time (sub-action).
   */
     void stepDown ( )
     {
         turnLeft ( );
         move ( );
         turnRight ( );
         move ( );

     } // end stepUp ( )

  /**
     doTask - Script robot actions to be executed.
   */
     void doTask ( )
     {
      // prepare
         
move ( );
move ( );
move ( );
move ( );
move ( );
move ( );
move ( );

turnLeft ( );
move ( );
move ( );
pickBeeper ( );
turnLeft ( );
turnLeft ( );
move ( );
turnRight ( );
move ( );
move ( );
move ( );
move ( );
move ( );
move ( );
turnRight ( );
move ( );
pickBeeper ( );
move ( );
move ( );
move ( );
move ( );
turnRight ( );
move ( );
pickBeeper ( );
move ( );
move ( );
move ( );
move ( );
move ( );
turnRight ( );
move ( );
turnRight ( );
move ( );
turnLeft ( );
move ( );
move ( );
move ( );
turnRight ( );
move ( );
move ( );
 putBeeper ( );
 putBeeper ( );
 putBeeper ( );
 turnLeft ( );
 turnLeft ( );
 move ( );
 move ( );
 turnLeft ( );
 move ( );
 move ( );
 move ( );
 turnRight ( );
 move ( );
 turnLeft ( );
 move ( );
 turnLeft ( );
 move ( );
 move ( );
 move ( );
 move ( );
 move ( );
 move ( );
 turnLeft ( );
 move ( );
 move ( );
 move ( );
 move ( );
 move ( );
 move ( );
 turnRight ( );
 move ( );
 turnLeft ( );
 turnLeft ( );


      // execute
        


      // stop
         turnOff ( );
     } // end doTask ( )

}; // end class MyRobot

// --------------------------- main action

int main ( )
{
 // define context
    MyRobot *robot = new MyRobot( );

 // set the stage and decorate with objects

    world->create ( "" );
    decorateWorld ( "Guia_00.txt" );
    world->show   ( );

    world->reset  ( );
    world->read   ( "Guia_00.txt" );
    world->show   ( );

    set_Speed  ( 2 );

 // put robot on the stage
    robot->create  ( 1, 1, EAST, 0, "Karel" );

 // execute action
    robot->doTask ( );

 // world shutdown
    world->close ( );

//  program shutdown
    getchar ( );
    return ( 0 );
} // end main ( )