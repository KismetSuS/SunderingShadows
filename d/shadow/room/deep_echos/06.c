//06.c  inherits from 01 like many others

#include <std.h>
#include "deep_echo.h"

inherit DEEP;

void create(){
    ::create();
    set_exits(([
      
        "east"  : ROOMS"15",
        "west"  : ROOMS"05"
        ]));
}
