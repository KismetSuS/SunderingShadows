#include <std.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("ignite_func","ignite");
}
void create() {
    ::create();
    set_id(({"stick","incense","stick of incense",
	"incense stick","wis_stick"}));
    set_short("%^RED%^Stick of incense%^RESET%^");
    set_long(
	"%^RED%^This is a stick of incense of plain design. "
	"It is probably "
    	"used for some sort of worship. It may be burned "
	"by <ignite stick>."
	"%^RESET%^"
);
    set_weight(1);
    set_value(50);
}
void save_me(string file) { return 1; }
int ignite_func(string str) {
    if(!str) {
	notify_fail("Ignite what?\n");
	return 0;
    }
    if(str != "stick") {
	notify_fail("Ignite what?\n");
	return 0;
    }
    if((int)TP->query_stats("wisdom") > 17) {
	write(
      "%^RED%^You ignite the stick and relish in its unusual "
	    "smell.%^RESET%^"
	);
	say(
	    "%^RED%^"+TPQCN+" burns a stick of incense.%^RESET%^"
	,TP);
        TO->remove();
	return 1;
    } else {
	write(
	    "%^RED%^You ignite the stick and the aroma sparks wise "
	    "feelings within you!%^RESET%^"
	);
	say(
	    "%^RED%^"+TPQCN+" burns a stick of incense.%^RESET%^"
	,TP);
        TP->add_stat_bonus("wisdom",1);
        TO->remove();
	return 1;
    }
}
