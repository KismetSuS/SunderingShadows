#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "south" : ROOMS + "ziglow133" ,
	          "north" : ROOMS + "ziglow131"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow226",5,6,20})
  ]));
}
