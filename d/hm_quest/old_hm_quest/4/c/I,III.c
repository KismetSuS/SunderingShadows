#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(4);
  set_exits( ([
                "north" : MAZEDIR+"4/c/I,II",
                "south" : MAZEDIR+"4/c/I,IV",
                "east"  : MAZEDIR+"4/c/II,III"
           ]) );
}
