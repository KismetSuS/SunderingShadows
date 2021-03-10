#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow214" ,
	          "south" : ROOMS + "ziglow212"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid110",5,6,20}),
     "descend":({ROOMS + "ziglow116",5,6,20}),
  ]));

}
