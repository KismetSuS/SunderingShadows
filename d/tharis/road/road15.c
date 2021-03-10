 //d/tharis/road/road15.c//
#include <std.h>
#include <objects.h>
inherit "/d/tharis/road/road.c";

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_light(2);
    set_indoors(0);
    set_short("Road around the wall of Tharis");
    set_long(
@OLI
        The walls stand twenty feet above you. The marvelous
stone work rougher because of time. The street you walk on
wraps around the city. Many travelers line the streets. You take
no notice of these. The occasional beggar screams for alms.
The bustle outside the city strikes you as stiff, unnaturally rigid.
OLI
    );
    set_smell("default","Your senses are accosted by the normal smells of a city.");
    set_listen("default","The city bustles about you.");
    set_exits(([
"east": "/d/tharis/road/road14",  
"west": "/d/tharis/road/road16"   
    ] ));
      set_items(([
       "road" : "The road is deeply rutted by the eons of travel by heavily laden wagons of trade.",
       "wall":"You notice that the base of the wall has been over grown. It looks climbable."
    ] ));
   set_dest("/d/tharis/Tharis/wall5");
}