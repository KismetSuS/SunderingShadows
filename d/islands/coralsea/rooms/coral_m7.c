#include <std.h>
#include "../defs.h"
inherit BASE"coralmaze1";

// Coral Sea Area - Created January 2009 by Ari

void create(){
	::create();
		set_exits(([
			"east":ROOMS"coral_m8",
			"south":ROOMS"coral_m11"
		]));
}