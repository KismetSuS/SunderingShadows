#include "../../undead.h"

inherit INH+"field_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BF+"room31",
        "east"      :BF+"room26",
        "south"     :BF+"room14"
             ]));

}