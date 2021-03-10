#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_property("no sticks",1);
        set_terrain(WOOD_BUILDING);
        set_travel(PAVED_ROAD);
        set_short("%^BOLD%^%^GREEN%^A nice but simple house");
        set_long(
@STYX
This is a small and plain but nice house.  It has a %^BOLD%^%^BLACK%^stove %^RESET%^for both cooking and heating in winter in one corner.  Nearby is a washbasin that sits on cabinets to store dishes.  A table and chairs to sit and eat at are also nearby and oil lamps hang on the walls for lighting.  There is a %^BOLD%^%^GREEN%^couch %^RESET%^and a few more comfortable looking chairs.  A small bedroom is in another corner with walls for privacy but you can see into it since the curtain used to cover the door is pulled aside.  There is a small desk with some %^BOLD%^papers %^RESET%^on it against the east wall.        
STYX
        );
        set_smell("default","The house smells of wood and smoke.");
        set_listen("default","Little disturbs the quiet here.");
        set_items(([
        ({"chair","chairs"}) : "All the chairs are simple wooden ones but the ones near the sofa have nice cushions and arms on them.",
        "stove" : "A pile of wood sits next to it.",
        "cabinet" : "The cabinet has open shelves with dishes and cooking utensils and shelves behind doors for the linens.",
        "couch" : "%^BOLD%^%^GREEN%^The couch has a wooden frame but has nice thick cushions covered with a heavy but pretty bright green fabric.",
        "bedroom" : "The bedroom has a dresser for a few clothes and a washbasin sitting on it.  It's barely large enough for the single bed and a curtain is used for a door.",
        "floor" : "The floor is simply wooden planks but it looks pretty clean.",
        ({"wall","walls"}) : "The walls are plain but curtains brighten it up a little.",
        ({"lamps","lamp","oil lamps"}) : "Lamps that burn oil hang from the walls and ceiling for light.",
		({"paper", "papers"}) : "You notice some of the papers are addressed to Gleveth and seem to be about boring banking business.",
        ]));
        set_exits(([
        "north" : MAINTOWN"erstreet3",
        ]));
        set_door("green door","/d/newbie/rooms/town/erstreet3","north",0);
}