
#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
       "north" : ROOMS"ogremaze49",
       "east" : ROOMS"ogremaze51",
   ]));

}