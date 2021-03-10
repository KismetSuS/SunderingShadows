#include "../../newbie.h"

inherit INH"townmove.c";

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Highspire Avenue in Offestry");
   set_short("Highspire Avenue in Offestry");
   set_long(
@NEWBIE
You are walking along Highspire Avenue, the northern border of the city.
A wooden palisade runs along the road. A flower garden for the temple of 
Offestry can be seen over a fence on south side of the road. The temple 
is apparently the namesake of this street, as the spire can be seen all
along its length.
NEWBIE
   );
   set("night long", ""+TO->query_long()+"\n%^BOLD%^The street light glows brightly and lights your way.");
   set_listen("default","You hear snatches of conversation from passersby.");
   set_smell("default","The air is fresh and clean.");
   set_property("light",2);
   set_items(([
      "streets":"The streets are cobbled and new. They lead throughout the city.",
      "palisade":"The palisade stands around 12 feet high, surrounding the city. You notice a few archers and guardsman patrolling.",
      "garden":"Someone spends a great deal of time taking care of the flowers in this garden.",
      "spire":"The temple's spire rises to a point high above the other buildings along this street.",
   ]));
   set_exits(([
      "east":MAINTOWN"nstreet4",
      "west":MAINTOWN"wrstreet8",
   ]));
}

void reset(){
	::reset();
	if(!present("street_light",TO))
	new(MISCDIR+"street_light")->move(TO);
}
