#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TUNI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  The tunnel of flames "+
    "continues east and west here.%^RESET%^");
    set_exits(([
       "west" : FTUN_ROOMS"firetunnele6",
       "east" : FTUN_ROOMS"firetunnele8"
    ] ));
}
