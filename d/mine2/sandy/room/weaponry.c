#include "abolition.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors", 1);
    set_property("noattack",1);
    set_short("Sandy's Weaponry Shop.");
    set_long(
" "
"This is Sandy's Weaponry Shop.  There are several weapons "
"hanging on the wall.  A large desk sits in the far corner of the "
"room.  A man sits at the desk polishing up some weapons.  "
"He looks very busy, and you don't bother to disturb him.  "
""
""
      );

    set_smell("default","You smell hot ashesh.");
    set_listen("default","You hear the sound of metal hitting metal.");

    set_exits( ([
    "out" : "/d/mine2/sandy/room/sandy5"
        ]) );
    set_items( ([
	"desk" : "A man sits at it polishing up some weapons.",
	"room" : "The room is very hot, and weapons are hung from the wall.",
	"weapons" : "There are several type of weapons here."
		]));		    	

}
void init(){
    ::init();
    if(!present("steve"))
	    new("/d/mine2/sandy/mon/steve.c")->move(TO);


}
