#include <std.h>
#include "../inherits/area_stuff.h"
inherit CY;

void create() 
{
    ::create();
    set_long(TO->query_long() + "%^BOLD%^%^WHITE%^ The path around the "+
    "house continues to the north and the west.%^RESET%^");

    set_exits((["north" : HHROOMS+"cy7", "west" : HHROOMS+"cy5" ]));		

}
