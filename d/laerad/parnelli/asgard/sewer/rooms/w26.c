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
   "northeast":LROOMS+"dw18",
   "east":LROOMS+"dw27",
   "southeast":LROOMS+"dw32",
   "west":LROOMS+"w25",
   "northwest":LROOMS+"w17"
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