
#include <std.h>
#include "../../serakii.h"

inherit STORAGE"fallow_field.c";



void create(){
   ::create();


set_exits(([

"north" : FALLOW"2",
"northeast" : FALLOW"3",
"south" : FALLOW"13",


]));

}
