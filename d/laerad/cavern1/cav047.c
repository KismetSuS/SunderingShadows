//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern1/special/cavern.c";
void create(){
    ::create();
    set_short("Laerad caverns");
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is surprisingly clean and refreshing.");
    set_listen("default","You can hear the trickling of the stream.");
    set_exits( ([
	"west":"/d/laerad/cavern1/cav044",
	"southwest":"/d/laerad/cavern1/cav053"
    ]) );
}
