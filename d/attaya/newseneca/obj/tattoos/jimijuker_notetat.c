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
	set_value(25000);
	set_id(({ "tattoo", "tat" }));
	set_short("a large sized BOLD-BLACK music-note tattooed on his left fore-arm");
	set_long(
@MYLONG
Its simpley a standard music-note tattooed in BOLD-BLACK ink on his fore-arm.

MYLONG
	);
	set_limbs(({"left arm"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "large"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

