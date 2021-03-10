#include <std.h>
#include "../lizard.h"
inherit ROOM;  // changed to use ROOM instead of VAULT to save memory (no doors)
void create(){
::create();
set_name("Dry Caves");
set("short","Dry well lit cavern.");
set("long","%^ORANGE%^You find yourself in a small dry room of the cavern.  "+
   "The walls and floor look like the stone has been worked in this area. Torches line the walls "+
   "and this area is very well lit.  %^RESET%^");
set_property("indoors",1);
set_property("no teleport",1);
set_property("light",2);
set_terrain(NAT_CAVE);
set_travel(DIRT_ROAD);
set_smell("default","The room smells dusty and dry.");
set_listen("default","It is very quiet in these rooms save for the sounds you make.");
set_items(([
   "walls":"Much like what you would expect cave walls to be like, hard, dry and cool to the touch.",
   "floor":"Smooth and flat as if from some stoneworking and much usage. One of the tiles looks different.",
   "tile":"Somehow it seems out of place, different.",
   "torches":"Sputtering and flickering the torches on the walls illuminate the room completely.",
   "torch":"Sputtering and flickering the torches on the walls illuminate the room completely."
   ]));
set_exits(([
   "north":LROOMS+"lk11",
   "northeast":LROOMS+"lk12",
   "south":LROOMS+"lk14",
   "northwest":LROOMS+"lk10"
 ]));
set_trap_functions(({"south"}),({"lguards"}),({"south"}));
}
int lguards(){
    object ob;
    if(interactive(TP)){
    tell_object(TP,"As you attempt to walk south you hear an audible click!");
    tell_room(ETP,""+TPQCN+" starts to walk south and you hear an audible click!",TP);
    tell_room(TO,"%^BOLD%^%^GREEN%^Lizardmen rush from the south to see what set off their trap!%^RESET%^");
         new(LMON+"nwplead")->move(TO);
         new(LMON+"nwplead")->move(TO);
         new(LMON+"nwwarlead")->move(TO);
toggle_trap("south");
    return 1;
    }
}
void reset(){
    ::reset();
    if(!trapped("south")){
        toggle_trap("south");
    }
}
