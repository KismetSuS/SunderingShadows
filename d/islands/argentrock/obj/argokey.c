#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("orange key");
    set_id( ({"key","orange","orange key"}) );
    set("short","Orange key");
     set("long","This an orange key. It is made of unknown materials and is "
   "extremely light in weight.");
    set_weight(3);
    set_value(5);
}
