//Ekibi Caverns by Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit EKIBI;

void create(){
   ::create();
   set_exits(([
      "southwest" : PATHEXIT"c4",
      "east" : PATHEXIT"c6"
   ]));
}
