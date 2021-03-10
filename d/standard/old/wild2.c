inherit "std/room";

void init() {
    ::init();
    add_action("enter_opening", "enter");
    add_action("go_southeast", "southeast");
}

void create() {
  ::create();
    set_property("light", 2);
    set("short", "The tropical wilderness");
    set("long",
	"You are inside a jungle that thickens along the path "
	"northeast.  The path widens west as it heads towards "
	"the adventuring village of Praxis.  You also notice "
	"a small opening in the thick jungle cover southeast.");
    set_items(
	(["jungle" : "A wilderness area full of outlaws and "
	    "mysterious things.\n",
	  "village" : "The adventurer's town of Praxis.",
	  "vegetation" : "It gets thicker to the east.",
	  "path" : "You can see it opening up towards the village west.",
	  "opening" : "Perhaps you could enter it?"]) );
    set_exits( 
	      (["northeast" : "/d/standard/jungle",
		"west" : "/d/standard/wild1"]) );
}

int enter_opening(string str) {
    if(!str) {
	notify_fail("Enter what?\n");
	return 0;
    }
    if(str != "opening" && str != "hole" && str != "jungle") {
	notify_fail("That is not here to be entered.\n");
	return 0;
    }
    this_player()->move_player("/d/standard/outland1", "into the jungle");
    return 1;
}

int go_southeast() {
    this_player()->move_player("/d/standard/outland1", "into the jungle");
    return 1;
}

