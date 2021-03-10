#include "../../newbie.h"
#include <std.h>

inherit TEMPLE"beshaba";

void create(){
   ::create();
   set_property("no teleport",1);
   set_exits(([
      "out": MAINTOWN"portals"
   ]));
}

void reset(){
   ::reset();
   if(!present("npc cleric")) new(TEMPLENPC"p_beshaba")->move(TO);
}
