#include <std.h>
#include "../lizard.h"

inherit WROOM;

/* changing to have inherit use CROOM  *Styx*  6/18/03
object ob;
object *monsArray;
int i;
*/

void create(){
	::create();
//	monsArray = allocate(3);
set_exits(([
   "north":LROOMS+"w5",
   "northeast":LROOMS+"w6",
   "east":LROOMS+"w15",
   "southeast":LROOMS+"w24",
   "south":LROOMS+"w23",
   "southwest":LROOMS+"w22",
   "west":LROOMS+"w13"
   ]));
}
/*
void reset() {
        ::reset();
       for(i = 0;i < sizeof(monsArray);i++){
        	if(!objectp(monsArray[i])){
        		if(!random(5)) {
            		ob = new(LMON+"lman");
            		ob->move(TO);
            		monsArray[i] = ob;
        		}
        		if(!random(10)) {
            		ob = new(LMON+"plead");
            		ob->move(TO);
            		monsArray[i] = ob;
        		}
        		if(!random(20)) {
            		ob = new(LMON+"warlead");
            		ob->move(TO);
            		monsArray[i] = ob;
        		}
		}
	}
}
*/