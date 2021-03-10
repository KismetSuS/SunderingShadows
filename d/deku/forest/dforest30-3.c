#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit LAKEBANK;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"31-3",
       "east" : F_ROOMS"29-3",
       "north" : F_ROOMS"30-4",
       "south" : F_ROOMS"30-2",
       "southeast" : F_ROOMS"29-2",
       "southwest" : F_ROOMS"31-2",
       "northeast" : F_ROOMS"29-4",
    ] ));
}
