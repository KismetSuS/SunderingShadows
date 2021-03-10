
#include <std.h>
#include <daemons.h>
#include "/d/stella/short.h"

inherit OBJECT;
object owner;

void heart_beat(){
    object holder, env;
    env = ETO;
    if(!objectp(ETO)) return;
    if(objectp(env) && living(env) && interactive(env)){
        holder = env->query_name();
        } else {
        return;
    }
    if(holder != owner){
        tell_object(env,"You have no right to a medallion which you have not earned!");
        TO->remove();
        } else {
        return;
    }
}

void init(){
        if(interactive(TP) && !owner) owner = TPQN;
	::init();
	}
	
void create(){
	::create();
	
        set_heart_beat(1);
	set_name("Scorpion Token");
	set_id(({"medallion","scorpion medallion","scotoken"}));
        set_short("Scorpion Medallion");
        set_long("A small round medallion inscribed with the following symbol:\n\n"
" /_     \n"
" | \\  | \n"
"    |_/ \n\n");
	set_weight(1);
	set_value(1000);
	}
