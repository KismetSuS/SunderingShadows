//whouse1.c - Nicculis' (armor shop guy) estate in Newbietown

#include <std.h>
#include "../../newbie.h"
inherit INH"townmove.c";

void create() {
        ::create();
        set_property("indoors",1);
        set_property("light",2);
        set_property("no sticks",1);
        set_terrain(STONE_BUILDING);
        set_travel(PAVED_ROAD);
        set_short("%^ORANGE%^A spacious and well-built home");
        set_long(
@STYX
This is a very spacious and well-built home.  Thick stone walls block out the sounds from outside and help keep the temperature moderate while various rugs decorate and insulate the floors.  You can see most of the rooms from here through open doors.  Each room has a fireplace for heating and oil lamps hang from the walls or sit on tables for light.  The master bedroom is down a short hall to the left from the entrance and a smaller one is just across from it.  The dining room is directly ahead and you can see the kitchen just beyond it.  A parlor for relaxing and entertaining guests is to the right from the entrance.  The decorating is primarily in %^ORANGE%^earth tones %^RESET%^here.  Several rooms almost seem to be guarded by suits of armor mounted on wire frames so they seem to stand on their own.
STYX
        );
        set_smell("default","The house smells of mortar and scented oil from the lamps.");
        set_listen("default","Little disturbs the quiet here.");
        set_items(([
        ({"walls","wall","stone"}) : "The stones for the walls have been carefully placed and mortar seals the spaces between them.",
        "bedroom" : "The bedrooms look spacious and have real wooden doors on them.  They are open at the moment, allowing you to see the neatly made beds and nice furniture.",
        "kitchen" : "You can see heavy cast iron pots and pans hanging from a rack in the kitchen over the cabinets and sink.  A stove for cooking has wood piled beside it.",
        "parlor" : "The parlor has a cozy couch with nice thick cushions in a sturdy fabric in %^ORANGE%^earth tone stripes%^RESET%^.  A large oval woven rug covers the center of the room.  Several chairs are grouped around the fireplace and a chess set sits on a table with a chair on each side.",
        "dining room" : "The dining room has a massive oak table with ten chairs around it.  The chairs at each end have arms and look very comfortable.",
        ({"floor", "rugs"}) : "The floor is nicely polished wood.  The wood is inlaid in interesting patterns in some of the rooms or mostly covered with fur hides or woven rugs in others.",
        ({"lamps","lamp","oil lamps"}) : "Oil lamps hang from decorative wrought iron holders and give off a pleasant scent as they burn.",
		({"suits", "armor", "suits of armor"}) : "The various armors are firmly mounted to the wire frames.  From a distance, the full sets look like they could be a warrior standing there.  Many of them are signed by Nicculis himself.  A set of small sized armor has a plaque reading 'Crafted by dwarves of Kinaro in the northeast'.",
        ]));
        set_exits(([
        "north" : MAINTOWN"wrstreet3",
        ]));
        set_door("brown door","/d/newbie/rooms/town/wrstreet3","north",0);
}