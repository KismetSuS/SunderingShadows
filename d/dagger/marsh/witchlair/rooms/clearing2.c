#include <std.h>
#include "../witchlair.h"
inherit BASE"clearing_inherit.c";

void create() {
  ::create();
  set_exits(([
    "southwest":"/d/dagger/marsh/witchlair/rooms/clearing1",
    "east":"/d/dagger/marsh/witchlair/rooms/clearing3",
    "south":"/d/dagger/marsh/witchlair/rooms/clearing5",
    "southeast":"/d/dagger/marsh/witchlair/rooms/clearing6",
 ]));
}
