#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(15000);
	set_id(({ "small tattoo", "tattoo" }));
	set_short("a small tattoo of an open right hand gauntlet");
	set_long(
@MYLONG
This small tattoo is inked in the shape of a right handed gauntlet. the gauntlet itself is open with the palm facing outward.

MYLONG
	);
	set_limbs(({"right hand"}));
	set_wear((:TO,"wear_me":));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "small"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

