// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("long14");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Long St.%^RESET%^");

    set_long("Long 14");

    set_smell("default","
Scents");
    set_listen("default","Sounds");


    set_exits(([ 
		"south" : "/d/av_rooms/mystra/long13",
		"north" : "/d/av_rooms/mystra/long15",
	]));

}