#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"32-10",
       "east" : F_ROOMS"30-10",
       "north" : F_ROOMS"31-11",
       "south" : F_ROOMS"31-9",
       "southeast" : F_ROOMS"30-9",
       "southwest" : F_ROOMS"32-9",
       "northeast" : F_ROOMS"30-11",
       "northwest" : F_ROOMS"32-11",
    ] ));
}
