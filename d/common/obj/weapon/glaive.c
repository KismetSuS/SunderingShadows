//updated base damage - Circe 4/29/04
#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_id(({"sharp glaive","a sharp glaive","pole arm","polearm","glaive"}));
    set_name("glaive");
    set_short("A sharp glaive");
    set_long("This weapon consists of a huge, single edged "+
       "knifeblade on a long pole.  Looks like you could certainly "+
       "get a bit of leverage into any cutting blow.");
    set_size(3);
    set_weight(10);
    set_value(10);
    set_type("slash");
    set_prof_type("polearm");
    set_weapon_speed(8);
//    set_wc(1,6);
//    set_large_wc(1,8);
   set_wc(3,4);
   set_large_wc(3,4);
   set_weapon_prof("martial");
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("slashing");
}
