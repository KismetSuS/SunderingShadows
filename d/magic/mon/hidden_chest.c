#include <std.h>
inherit WEAPONLESS;

object caster;
string castname, fname;

void create(){
    ::create();
    set_name("chest");
    set_id(({"chest","hidden chest","wooden chest","greater summon"}));
    set_short("%^RESET%^%^BLUE%^wooden %^RESET%^%^ORANGE%^chest %^RESET%^with %^BOLD%^%^YELLOW%^golden latches%^RESET%^");
    set_long("%^RESET%^%^BLUE%^This is an %^BOLD%^%^ORANGE%^iro%^BLACK%^n%^ORANGE%^-bound%^RESET%^%^BLUE%^ wooden chest that rests on the ground. It is quite large and could probably fit a lot of things inside. You could probably %^BOLD%^%^YELLOW%^<rehide> %^RESET%^%^BLUE%^it to make it disappear again.%^RESET%^");
    set_attacks_num(1);
    set_exp(1);
    set_gender("neuter");
    set_hp(40);
    set_hd(4,1);
    set_race("chest");
    set_stats("constitution",24);
    set_stats("dexterity",2);
    set_stats("strength",24);
    set_body_type("humanoid");
    remove_limb("left hand");
    remove_limb("right hand");
    remove_limb("left foot");
    remove_limb("right foot");
    remove_limb("left leg");
    remove_limb("right leg");
    add_limb("chest",0,0,0,0);
    set_attack_limbs(({"chest"}));
    setenv("MIN", "$N floats in.");
    setenv("MOUT", "$N floats off to the $D.");
}

void setup_chest(object invoker)
{
    caster = invoker;
	"/daemon/yuck_d"->load_inventory(this_object(),"/d/save/summons/fart/chest");

    drop_containers();
}

init()
{
  ::init();
  add_action("rehide","rehide");
}

int rehide(string str){
	
	if (str=="chest") {
        tell_object(ETO,"%^RESET%^%^ORANGE%^You push down on the chest and you hear mechanical gears nearby grind as it disappears back into the ground.%^RESET%^");
		 call_out("save_chest",1);
		 return 1;
    }
}

void die(object obj)
{
    if (objectp(caster)) {
        caster->remove_property("has_elemental");
    }
    remove();
}

void drop_containers()
{
    object invitem;
    object* myinven;
    string* ids;

    if (!objectp(ETO)) {
        return;
    }

    myinven = all_inventory(TO);

    foreach(invitem in myinven)
    {
        if (!invitem->is_container()) {
            continue;
        }

        if (sizeof(all_inventory(invitem))) {
            ids = invitem->query_id();
            force_me("drop " + ids[0]);
        }
    }
}

void save_chest()
{
    /* seteuid(getuid()); */
    if(!objectp(TO))
        return;
    if(!objectp(ETO))
        return;

	"/daemon/yuck_d"->save_inventory(this_object(),"/d/save/summons/fart/chest");
	all_inventory(TO)->remove();
	TO->remove();
}

void receive_given_item(object obj)
{
    string * ids;

    if (!obj->is_container()) {
        return;
    }

    if (sizeof(all_inventory(obj))) {
        ids = obj->query_id();
        force_me("drop " + ids[0]);
    }
}
