// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("castle1");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^CYAN%^Castle Path%^RESET%^");

    set_long("Castle 1");

    set_smell("default","
smells");
    set_listen("default","noise");


    set_exits(([ 
		"northeast" : "/d/av_rooms/mystra/castle2",
		"southwest" : "/d/av_rooms/mystra/morel5",
	]));

}