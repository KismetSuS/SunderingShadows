#include "../../undead.h"

inherit INH+"maze_one.c";

void create() 
{
    ::create();
 
    set_exits(([
        "west"      :MAZ+"room26",
        "east"      :MAZ+"room8",
        "southeast" :MAZ+"room31"
             ]));

}
