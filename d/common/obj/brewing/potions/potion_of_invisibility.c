#include "../brew.h"
inherit BREWPOTION;

void create() {
    ::create();
    set_property("instant potion",1); // ok to stack, spell is now doing the legwork.
}

int potion_effect(object drinker,int mystrength,string str) {
    object spellob;
    ::potion_effect(drinker,mystrength,str);
    spellob=new("/cmds/spells/i/_invisibility");
    spellob->set_silent_casting(1);
    spellob->set_cast_string("");
    spellob->use_spell(drinker,drinker,mystrength,100,"potion");
    return 1;
}

int potion_backfire(object drinker,int mystrength,string str) {
    object spellob;
    ::potion_effect(drinker,mystrength,str);
    spellob=new("/cmds/spells/f/_faerie_fire");
    spellob->set_silent_casting(1);
    spellob->set_cast_string("");
    spellob->use_spell(drinker,drinker,mystrength,100,"potion"); // using same ff effect as the backfire here, rather than writing it into invis.
    return 1;
}