//forest114.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "southeast":TFOREST"forest113",
                "southwest":TFOREST"forest115",
                ]));
}

