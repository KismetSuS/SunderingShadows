#include <std.h>
inherit ARMOUR;

string symbol1;
string symbol2;
string weapon1;
string weapon2;
string initial1;
string initial2;
string background;
void create(){
	::create();
	set_name("signet ring");
	set_id(({"ring","signet ring","signet"}));
	set_short("signet ring");
	weapon1 = "a two-handed %^GREEN%^scythe %^RESET%^with blade raised";
	weapon2 = "a two-handed %^GREEN%^scythe %^RESET%^with blade raised";
	background = "a lone %^ORANGE%^mountain %^RESET%^with a %^BOLD%^snowcapped peak%^RESET%^";
	set_long("This finely crafted signet ring is made of high quality %^BOLD%^white gold%^RESET%^.  It is a rather thick ring with a round, flat top that features "+(string)TO->query_seal()+"");
	set_weight(1);
	set_value(750);
	set_ac(0);
	set_limbs(({"right hand"}));
	set_type("ring");
set_lore("This signet ring was made by Edric, the firbolg jeweler in the village of Lothwaite.  Its symbols bear meaning for one person and refer to him or her alone.");
set_property("lore difficulty",12);
}
int query_weapon(){ return ""+weapon1+"";}
int query_weapon2(){ return ""+weapon2+"";}
int query_seal(){ return "a backdrop of "+background+".  On top of the background is the finely detailed image of "+weapon1+" beside an intricate depiction of "+weapon2+"."; }
int query_is_seal_device(){ return 1;}
