#include <std.h>
#include <objects.h>

inherit "/d/dagger/Torm/graveyard/rooms/graveyard.c";

void create() {
  ::create();
set_property("light",1);
set_property("outdoors",1);
set_short("Graveyard");
    set_long(
"You are wandering in the graveyard, lost and confused. On "+
"the ground are the remains of animals and unfortunate adventurers. Small "+
"gravestones indicate those dead who were rich enough to have a proper funeral. "+
"You see paths to the north, east, south, and west. To the north-west, you see a grand "+
"mausoleum...the resting place of someone obviously important.");
set_exits((["north":"/d/dagger/Torm/graveyard/rooms/grave2",
            "east":"/d/dagger/Torm/graveyard/rooms/grave9",
	"south":"/d/dagger/Torm/graveyard/rooms/grave15",
            "west":"/d/dagger/Torm/graveyard/rooms/grave7"]));
set_smell("default","The scent of fresh dirt and rotting corpses fills the air.");
set_listen("default","You hear activity all around you...");
}

void init() {
  :: init();
do_random_encounters(({"/d/dagger/Torm/graveyard/mon/bat.c"}),50,3);
do_random_encounters(({"/d/dagger/Torm/graveyard/mon/tree.c"}),100,1);
do_random_encounters(({"/d/dagger/Torm/graveyard/mon/snake.c"}),30,2);
do_random_encounters(({"/d/dagger/Torm/graveyard/mon/skeleton.c"}),20,1);}
