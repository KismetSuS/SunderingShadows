#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
    base_exits = ([
      "north" : TABAXROOM + "jungle01"
   ]);
  set_basic_exits();
  r_path = JUNG_ROOM4;
}
int is_map_transition(){
  return 1;
}

