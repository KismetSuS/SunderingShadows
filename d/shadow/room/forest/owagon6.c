
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "east":FORESTDIR+"owagon5",
               "west":FORESTDIR+"owagon8",
               ]));


}

