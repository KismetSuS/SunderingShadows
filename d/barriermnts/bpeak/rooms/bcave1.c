//bcave1
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;



void create(){
::create();
   set_property("light",1);
   set_property("indoors",1);
   set_travel(FOOT_PATH);
   set_terrain(ROCKY);
   set_name("%^BOLD%^%^BLACK%^Just inside of a cave%^RESET%^");
   set_short("%^RESET%^Just inside the opening of a cave");
   set_long((:TO,"ldesc":));
   set_smell("default","A foul odor drifts in from down the corridor.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^The muffled howls of wolves can be heard from somewhere on the cliffs above you.");
   set_items((["walls":"The walls of the corridor are carved out of the natural rock of the cliffs.  The rocks are loose and look as though they are ready to fall at any time.  The only thing helping to hold them in place are the few spindly tree trunks that have been propped up against the walls.",
   "opening":"%^YELLOW%^Light filters in through the opening of the cave.%^RESET%^",
    "ceiling":"The ceiling of the cave is high above you.  The way some of the loose rock hangs make you feel very nervous.",
    ({"tree trunks","trunks","trunk","trees","pine trees","pine tree trunks"}):"%^RESET%^%^ORANGE%^A few spindly tree trunks shore up the walls of the corridor. The fact that the root balls are still attached give you the indication that perhaps they have just been ripped out of the ground.%^RESET%^", 
   ]));
   set_search("default", "%^ORANGE%^Yeah, lots of rocks.%^RESET%^");
   set_exits((["out":INRMS+"ce1",
               "southwest":INRMS+"bcave2"]));
}

string ldesc(string str){
   return("%^RESET%^%^BLUE%^At first glance you thought this was a natural cave,"
" but you now realize that you are standing just inside the opening of a large"
" corridor carved into the side of the mountain.  The ceiling is at least twenty"
" feet above you and the corridor itself actually opens out to be about fifteen"
" feet wide.  A few spindly pine trees look like they've been ripped out of the"
" ground and lean against the walls, but other than that, little has been done to"
" shore up the unstable rock.  The corridor bends to the southwest from here,"
" making it impossible to see what's further inside.%^RESET%^ \n");
} 
