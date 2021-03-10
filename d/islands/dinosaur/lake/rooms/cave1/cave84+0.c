#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit MAIN;

void create(){
    ::create();
    set_short("Underwater Cave");
    set_long(
      "You are in a great underwater cavern.  All around you there is nothing but water and more water."
    );
    set_light(-1);
    set_property("indoors", 1);
    set_items( ([
      "water" : "water water everywhere AND YOU'RE GONNA DROWN IN IT!",
    ]) );
    set_exits( ([
      "west" : CAVEONE "cave85+0.c",
      "east" : CAVEONE "cave83+0.c",
      "up" : CAVEONE "cave74+0.c",
      "down" : CAVEONE "cave94+0.c",
      "north" : CAVEONE "cave84-1.c",
      "south" : CAVEONE "cave84+1.c",
    ]) );
}
