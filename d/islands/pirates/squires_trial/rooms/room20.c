#include <std.h>
#include "../squires_trial.h"

inherit CHASMBASEROOM;

void create(){
  ::create();
  set_name("Squire's Trial Room 20");
  set_short("A carved tunnel");
  set_long( 
  
            "%^RESET%^%^BLUE%^" + 
            "The rock has changed here.  It is a brittle, sharp and " +
            "broken corridor.  A small stream flows through, probably " +
            "the reason for the vast crevasse.  Broken chips of stone " +
            "have collected over centuries and form a solid, but somewhat " +
            "crunchy bed.  This stone path leads to the north and south."
          );
          
  set_exits(([
            "south" : SQUIREROOMS+"room19",
            "north" : SQUIREROOMS+"room21"
  ]));

}          


