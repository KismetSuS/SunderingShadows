
#include <std.h>

inherit "/d/attaya/spec/cliff2";

void create(){
	::create();
    set_exits(([
                   "up":"/d/attaya/cliff26",
                   "down":"/d/attaya/cliff24",
                   ]));
}

