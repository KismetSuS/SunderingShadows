#include <std.h>
inherit OBJECT;
object owner;
void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TP->query_true_name();
}
void create() {
    ::create();
    set_name("blade");
    set_id(({"blade2","hm_quest_silver","silver blade"}));
    set_short("%^RESET%^%^WHITE%^Silver blade%^RESET%^");
    set_long(
	"%^WHITE%^This long silver blade is from a sword that has seen much use "
	"yet appears to glow with an inner aura. It was detached at the hilt "
	"and you marvel at the being capable of destroying such a weapon."
	"%^RESET%^"
    );
    set_weight(10);
    set_value(200);
    set_heart_beat(1);
}
void heart_beat() {
    object holder,env;
    if(!objectp(ETO)) return;
    env = ETO;
    if(interactive(env) ) {
        holder = env->query_true_name();
    } else {
	return;
    }
    if(holder != owner) {
	tell_object(env,
	    "The silver blade vanishes!"
	);
	TO->remove();
        return;
    } else {
	return;
    }
}
