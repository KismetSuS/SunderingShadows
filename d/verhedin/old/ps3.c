
// Prince Street, Verhedin 
// Thorn@ShadowGate
// 001027
// New City, Verhedin
// som4.c

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit ROOM;

void create() {
  room::create();
  set_light(2);
  set_short("%^BOLD%^Prince Street, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Prince Street, Verhedin%^RESET%^

You can go northwest, southwest,or east down the street from here.
VERHEDIN
    );
  set_exits(([
    "northwest" : VOLD+"ps2",
    "east" : VOLD+"ps4",
    "southwest":VOLD+"ms10"
   ]));
  set_listen("default","Default listen.");
  set_smell("default","Default smell.");
 }

void reset(){
	::reset();
}
