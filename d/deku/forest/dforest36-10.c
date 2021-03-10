#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"37-10",
       "east" : F_ROOMS"35-10",
       "north" : F_ROOMS"36-11",
       "south" : F_ROOMS"36-9",
       "southeast" : F_ROOMS"35-9",
       "southwest" : F_ROOMS"37-9",
       "northeast" : F_ROOMS"35-11",
       "northwest" : F_ROOMS"37-11",
    ] ));
}
