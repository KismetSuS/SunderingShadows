//Coded by Bane//
#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_name("Nirvana avenue");
    set_short("Nirvana avenue");
    set_long(
	"%^BOLD%^Nirvana avenue%^RESET%^
You are in Asgard's residential area.  The cobblestone street leads south "+
	"along the residential district and north towards Asgard's main "+
	"road Excalibur.  You can see a few run down houses to the east, a "+
	"couple peasants sit on the steps of some of the homes."
    );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","A cool breeze blows through the street.");
    set_listen("default","You can hear the chatter of peasants.");
*/
    set_exits( ([
	"east":"/d/laerad/parnelli/asgard/as36",
	"north":"/d/laerad/parnelli/asgard/as04",
	"south":"/d/laerad/parnelli/asgard/as29"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("peasant")){
	new("/d/laerad/mon/peasant")->move(this_object());
    }
}
*/