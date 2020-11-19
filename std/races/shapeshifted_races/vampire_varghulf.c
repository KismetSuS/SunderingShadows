#include <std.h>
#include <daemons.h>

inherit SHAPESHIFT;

#include "mage_shapes.h"

void create()
{
    ::create();

    set_attack_limbs( ({ "maw" }) );
    set_new_damage_type("piercing");
    set_limbs( ({ "maw","head","torso","right leg","left leg","right wing","left wing","tail" }) );
    set_attack_functions( ([ "maw" : (:TO,"shape_attack":) ]) );
    set_ac_bonus(2);
    set_base_attack_num(3);
    set_castable(0);
    set_can_talk(0);
    set_shape_race("varghulf");
    set_shape_profile("vampire_varghulf_999");
    set_shape_bonus("survival",6);
    set_shape_bonus("perception",4);
    set_shape_bonus("damage bonus",6);
    set_shape_bonus("attack bonus",6);
    set_shape_bonus("sight bonus",4);
    set_shape_bonus("damage resistance",8);
    set_shape_height(90);
    set_shape_weight(450);
}

int default_descriptions(object obj)
{
    if(!objectp(obj)) { return 0; }

    obj->set_description("is a creature vaguely resembling a bat, with huge powerful build, giant maw and predatory glowing eyes.");

    obj->setDescriptivePhrase(" $R with intense red eyes");

    obj->set("speech string","growl");
    obj->set("describe string","angrily");

    obj->force_me("message in trots in quickly");
    obj->force_me("message out darts quickly to the $D");

    return 1;
}


// custom shapeshift messages here, override this function
int change_into_message(object obj)
{
    if(!objectp(obj)) { return 0; }
    tell_object(obj,"%^RESET%^%^RED%^%^BOLD%^You turn your mind out to the bloodline as you focus on the core of your spirit.");
    tell_object(obj,"%^RESET%^%^RED%^You can feel your body beginning to change!");
    tell_object(obj,"%^RESET%^%^BOLD%^%^BLACK%^Your senses heighten, you can feel the pulse of the night, smell countless scents, you can taste the very air. You are the one with the night.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+" grows very still and appears to concentrate deeply.",obj);
    tell_room(environment(obj),"%^RESET%^%^BOLD%^%^BLACK%^"+obj->QCN+" begins to change in front of your very eyes!",obj);
    tell_room(environment(obj),"%^RED%^Where "+obj->QCN+" once stood, is now a large varghulf!",obj);

    return 1;
}


// custom unshapeshift messages here, override this function
int change_outof_message(object obj)
{
    if(!objectp(obj)) { return 0; }

    tell_object(obj,"%^RESET%^%^RED%^You relax your focus on the darkness.");
    tell_object(obj,"%^RESET%^%^RED%^You can feel the sharpness of your senses beginning to fade and the strength returning.");
    tell_object(obj,"%^RESET%^%^RED%^You inhale a breath and stretch as you grow accustomed to the foreign sensation of your another body once again.");

    tell_room(environment(obj),"%^RESET%^%^BOLD%^"+obj->QCN+"'s muscles slacken and "+obj->QS+" gets a far-away look in "+obj->QP+" eyes.",obj);
    tell_room(environment(obj),"%^RESET%^%^BLUE%^"+obj->QCN+"'s body begins to change shape, elongating and curving!",obj);
    tell_room(environment(obj),"%^RESET%^%^BOLD%^%^BLACK%^Where "+obj->QCN+" once stood, now stands a "+obj->query_race()+"!",obj);

    return 1;
}


int can_cast()
{
    return 1;
}

// custom unarmed attack functions go here, functions can be added just like hit functions for weapons
int shape_attack(object tp, object targ)
{
    object etp;
    string *specials=({});
    int i,chance,dice;

    etp = environment(tp);

    if(!objectp(tp)) { return 0; }

    chance = (int)tp->query_level();

    if(chance > 50) { chance = 50; }

    dice = ( chance / 5) + 2;

    if (roll_dice(1, 100) > chance) {
        return roll_dice(2, dice);
    }

    specials = ({"heal", "trip", "high damage", "extra attack", "low damage"});

    switch(specials[random(sizeof(specials))])
    {
    case "heal":
        tell_object(tp,"%^RESET%^%^BOLD%^%^BLACK%^You pull on "+targ->QCN+"'s essence with your attack, draining "+targ->QO+" and restoring some of your vital health!");
        tell_object(targ,"%^RESET%^%^BOLD%^%^BLACK%^"+tp->QCN+"'s pulls at your essence, leaving you drained!");
        tell_room(etp,"%^RESET%^%^BLUE%^"+tp->QCN+"'s wounds look less severe after "+tp->QS+" attacks "+targ->QCN+"!",({tp,targ}));
        tp->do_damage(tp->return_target_limb(),(dice * -1 * 2));
        targ->cause_typed_damage(targ,targ->return_target_limb(),dice*2,get_new_damage_type());
        break;

    case "trip":
        tell_object(tp,"%^RESET%^%^BOLD%^%^BLACK%^You dig your teeth into "+targ->QCN+"'s shoulder and drag "+targ->QO+" to the ground!");
        tell_object(targ,"%^RESET%^%^BOLD%^%^BLACK%^"+tp->QCN+" digs "+tp->QP+" teeth into your shoulder and drags you to the ground!");
        tell_room(etp,"%^RESET%^%^BOLD%^%^BLACK%^"+tp->QCN+" digs "+tp->QP+" teeth into "+targ->QCN+"'s shoulder and drags "+targ->QO+" to the ground!",({tp,targ}));
        if(!targ->fort_save(chance)) { targ->set_tripped(1,"%^RESET%^%^YELLOW%^You are struggling to get your feet back under you!"); }
        break;

    case "high damage":
        tell_object(tp,"%^RESET%^%^BOLD%^%^BLACK%^You snarl angrily and lunge, tearing deeply into "+targ->QCN+"'s flank!");
        tell_object(targ,"%^RESET%^%^BOLD%^%^BLACK%^"+tp->QCN+" snarls angrily and lunges, tearing painfully into your side!");
        tell_room(etp,"%^RESET%^%^BOLD%^%^BLACK%^"+tp->QCN+" snarls angrily and lunches, tearing deeply into "+targ->QCN+"'s flank!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,4),get_new_damage_type());
        break;

    case "extra attack":
        tell_object(tp,"%^RESET%^%^BOLD%^%^BLACK%^You hit the ground and twist, immediately launching another quick attack at "+targ->QCN+"!");
        tell_object(targ,"%^RESET%^%^BOLD%^%^BLACK%^"+tp->QCN+" hits the ground and twists, immediately launching another attack at you!");
        tell_room(etp,"%^RESET%^%^BOLD%^%^BLACK%^"+tp->QCN+" hits the ground and twists, immediately launching another attack at "+targ->QCN+"!",({tp,targ}));
        tp->execute_attack();
        break;

    case "low damage":
        tell_object(tp,"%^RESET%^%^BOLD%^%^BLACK%^You quickly snap inside "+targ->QCN+"'s defenses and bite a vulnerable spot!");
        tell_object(targ,"%^RESET%^%^BOLD%^%^BLACK%^"+tp->QCN+" quickly snaps inside of your defenses and bites you!");
        tell_room(etp,"%^RESET%^%^BOLD%^%^BLACK%^"+tp->QCN+" quickly snaps inside of "+targ->QCN+"'s defenses and bites "+targ->QO+"!",({tp,targ}));
        targ->cause_typed_damage(targ,targ->return_target_limb(),roll_dice(dice,2),get_new_damage_type());
        break;


    }
    return roll_dice(2,dice);
}
