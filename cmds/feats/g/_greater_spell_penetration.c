#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() 
{
    ::create();
    feat_type("permanent");
    feat_category("MagicAccuracy");
    feat_name("greater spell penetration");
    feat_prereq("Perfect Caster OR Flawless Control");
    feat_desc("Greater Spell Penetration adds an additional +1 to spell save DCs. Additionally, they gain +2 to spell penetration.");
    permanent(1);
    set_required_for(({"armored caster"}));
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if(!objectp(ob)) { return 0; }

    if(!FEATS_D->has_feat(ob,"perfect caster") && !FEATS_D->has_feat(ob, "flawless control"))
    {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}

