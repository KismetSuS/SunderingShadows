//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains11",
	"east":"/d/laerad/plains/plains34",
	"south":"/d/laerad/plains/plains22",
	"north":"/d/laerad/plains/plains20",
    ]) );
}
