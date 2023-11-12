
#include "karel.hpp"

// --------------------------- methods section

/**
   Put objects in the world.
 */
void decorateWorld ( const char* fileName )
{
 // create stars
   world->set (  2,  1, VWALL  );
   world->set (  3,  1, HWALL  );
   world->set (  3,  2, VWALL  );
   world->set (  4,  2, HWALL  );
   world->set (  4,  3, VWALL  );
   world->set (  5,  3, HWALL  );
   world->set (  6,  3, HWALL  );
   world->set (  7,  3, HWALL  );
   world->set (  7,  3, VWALL  );
   world->set (  8,  2, HWALL  );
   world->set (  9,  1, HWALL  );
   world->set (  8,  2, VWALL  );
   world->set (  9,  1, VWALL  );


 // create Box



 // put beepers
      world->set (  8,  3, BEEPER );
      world->set (  9,  2, BEEPER );
      world->set (  9,  2, BEEPER );
      world->set (  10,  1, BEEPER );
       world->set (  10,  1, BEEPER );
       world->set (  10,  1, BEEPER );     

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
   void stepUpRight( ){
   turnLeft ();
   move ( );
   turnRight ( );
   move ();


     } // end stepUp ( )

void stepDownRight( ){
move ( );
turnRight ();
move ( );
turnLeft ();
}

void stepUpLeft(){
turnRight ( );
move ( );
turnLeft ();
move ();
}
void stepDownLeft(){
move ( );
turnLeft ();
move ( );
turnRight ();


}





  /**
     doTask - Script robot actions to be executed.
   */
     void doTask ( )
     {
      // prepare
         


move ( );



      // execute
   stepUpRight ();
   stepUpRight ();    
   stepUpRight ();
   move ();
   move ();
   stepDownRight ();
   pickBeeper ();
   stepDownRight ();
   pickBeeper ();
   pickBeeper ();
   stepDownRight ();
   pickBeeper ();
   pickBeeper ();
   pickBeeper ();
   turnLeft ();
   turnLeft ();
   stepUpLeft ();
   stepUpLeft ();
   stepUpLeft ();
   move ();
   move ();
   stepDownLeft ();
   putBeeper ();
   stepDownLeft ();
   putBeeper ();
   putBeeper ();
   stepDownLeft ();
   putBeeper ();
   putBeeper ();
   putBeeper ();
   move ();
   turnLeft ();
   turnLeft (); 

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