#include "../brew.h"
inherit BREWPOTION;

void create() {
    ::create();
    set_property("instant potion",1); // ok to stack, heroism tracker is now doing the legwork.
}

int potion_effect(object drinker,int mystrength,string str) {
    ::potion_effect(drinker,mystrength,str);
    if(drinker->query_property("morale-boost")) {
      tell_object(drinker,"%^GREEN%^The potion settles in your stomach, but doesn't seem to do anything.%^RESET%^");
      return 1;
    }
    tell_object(drinker,"%^GREEN%^Your sense of the world around you seem to grow heightened.%^RESET%^");
    drinker->set_property("morale-boost",1); // prevent stacking with heroism, as this is a lesser vers.
    drinker->add_skill_bonus("perception",2);
    drinker->add_skill_bonus("academics",2);
    "/daemon/delay_d"->sleep(base_name(TO),"potion_ending",1500,({ TP, mystrength, str }));  // 25min duration
    return 1;
}

int potion_backfire(object drinker,int mystrength,string str) {
    ::potion_backfire(drinker,mystrength,str);
    if(drinker->query_property("morale-boost")) {
      tell_object(drinker,"%^GREEN%^The potion settles in your stomach, but doesn't seem to do anything.%^RESET%^");
      return 1;
    }
    tell_object(drinker,"%^MAGENTA%^Your sense of the world around you seem to grow dulled.%^RESET%^");
    drinker->set_property("morale-boost",1); // prevent stacking with heroism, as this is a lesser vers.
    drinker->add_skill_bonus("perception",-2);
    drinker->add_skill_bonus("academics",-2);
    "/daemon/delay_d"->sleep(base_name(TO),"potion_backfire_ending",1500,({ TP, mystrength, str }));
    return 1;
}

int potion_ending(object drinker,int mystrength,string str) {
    ::potion_ending(drinker,mystrength,str);
    if(!objectp(drinker)) return 0;
    tell_object(drinker,"%^GREEN%^Your senses return to normal.%^RESET%^");
    drinker->set_property("morale-boost",-1);
    drinker->add_skill_bonus("perception",-2);
    drinker->add_skill_bonus("academics",-2);
    drinker->remove_property("potion effect");
    return 1;
}

int potion_backfire_ending(object drinker,int mystrength,string str) {
    ::potion_backfire_ending(drinker,mystrength,str);
    if(!objectp(drinker)) return 0;
    tell_object(drinker,"%^MAGENTA%^Your senses return to normal.%^RESET%^");
    drinker->set_property("morale-boost",-1);
    drinker->add_skill_bonus("perception",2);
    drinker->add_skill_bonus("academics",2);
    drinker->remove_property("potion effect");
    return 1;
}