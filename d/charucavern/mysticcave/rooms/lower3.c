#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();    
    set_long(TO->query_long()+"%^RESET%^%^CYAN%^ The air stirs here ever so slightly.%^RESET%^");    
    set_exits((["east" : CRROOMS +"lower4", "southwest" : CRROOMS+"lower2"]));		    
}
