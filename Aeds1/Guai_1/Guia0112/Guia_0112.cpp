
#include "karel.hpp"

// --------------------------- methods section

/**
   Put objects in the world.
 */
void decorateWorld ( const char* fileName )
{
 // create wall
    world->set (  6,  1, VWALL  );
    world->set (  6,  2, VWALL  );
    world->set (  6,  3, VWALL  );
    world->set (  6,  4, VWALL  );
    world->set (  6,  5, VWALL  );
    world->set (  6,  6, VWALL  );

 // create stair
    world->set (  3,  2, HWALL  );
    world->set (  6,  2, HWALL  );
    world->set (  4,  2, HWALL  );
    world->set (  5,  2, HWALL  );
    world->set (  2,  2, VWALL  );
    world->set (  2,  1, HWALL  );
    world->set (  1,  1, VWALL  );
 // put beepers
     world->set (  3,  3, BEEPER );
 world->set (  6,  3, BEEPER );
  world->set (  6,  6, BEEPER );
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
         
         stepUp ( );
         stepUp ( );  
         move ( );
          move ( );
           move ( );
           turnLeft ( );
          move ( );
          move ( );
          move ( );
          
          turnLeft ( );
          turnLeft ( );

          pickBeeper ( );

          move ( );
           move ( );
            move ( );
            turnRight ( );
            pickBeeper ( );
             move ( );
              move ( );
               move ( );
               pickBeeper ( );
               move ( );
               

               stepDown ( );
               turnLeft ( );
               move ( );
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