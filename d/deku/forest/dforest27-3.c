#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^YELLOW%^A dirt trail through the forest.%^RESET%^");
    
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A %^YELLOW%^dirt "+
    "trail%^BOLD%^%^BLACK%^ here leads northwest or east through "+
    "the forest.%^RESET%^");
    set_exits(([
       "west" : F_ROOMS"28-3",
       "east" : F_ROOMS"26-3",
       "north" : F_ROOMS"27-4",
       "south" : F_ROOMS"27-2",
       "southeast" : F_ROOMS"26-2",
       "southwest" : F_ROOMS"28-2",
       "northeast" : F_ROOMS"26-4",
       "northwest" : F_ROOMS"28-4",
    ] ));
    bandit_ambush("northwest","east","east",TO);
}
