#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFCE;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^BLUE%^The cellar appears to end here. "+
    "An opening to the northeast offers the only exit.%^RESET%^");
    set_exits( ([ "northeast" : FFCR"5"]) );
}

