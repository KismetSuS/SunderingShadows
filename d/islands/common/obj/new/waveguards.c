//Added Psion and cleaned up code - Cythera 5/06
//Runs from inherit properly now. Nienne, 08/07
#include <std.h>

inherit "/d/common/obj/armour/bracers.c";


void create()
{
    ::create();
    set_name("bracers");
    set_id(({ "wave guards", "bracers", "guards" }));

    set_short("%^RESET%^%^CYAN%^W%^BOLD%^a%^RESET%^%^BLUE%^v" +
              "%^BOLD%^e%^RESET%^%^CYAN%^ G%^BOLD%^u%^RESET%^%^BLUE%^" +
              "a%^BOLD%^r%^RESET%^%^CYAN%^d%^BOLD%^s%^RESET%^");

    set_obvious_short("%^RESET%^%^CYAN%^A pair of %^BLUE%^bluish%^CYAN%^ bracers%^RESET%^");

    set_long("%^RESET%^%^CYAN%^These bracers are made of an odd metal with a " +
             "slightly %^BLUE%^%^BOLD%^bluish %^RESET%^%^CYAN%^tint. The hue " +
             "changes with the light seemingly like shadows over the %^BOLD%^o" +
             "%^BLUE%^c%^RESET%^%^CYAN%^e%^BLUE%^a%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^" +
             " floor when the sun shines through the water. Small %^BOLD%^" +
             "%^BLUE%^w%^RESET%^%^CYAN%^a%^BOLD%^t%^RESET%^e%^BOLD%^r " +
             "o%^RESET%^p%^CYAN%^%^BOLD%^a%^RESET%^%^CYAN%^l%^BLUE%^%^BOLD%^s" +
             " %^RESET%^%^CYAN%^and %^BLUE%^a%^RESET%^%^CYAN%^q%^BOLD%^u" +
             "%^RESET%^a%^BOLD%^m%^RESET%^a%^BOLD%^r%^RESET%^i%^CYAN%^" +
             "%^BOLD%^n%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^s %^RESET%^%^CYAN%^" +
             "line the front ends of the bracers and they sparkle softly " +
             "with a faint %^BOLD%^%^BLUE%^blue%^RESET%^%^CYAN%^ glow. On " +
             "top of each bracers there is an ornate circle with an " +
             "intricate %^BOLD%^%^CYAN%^cresting wave%^RESET%^%^CYAN%^ motif.%^RESET%^");

    set_value(300000);

    set_property("no curse", 1);
    set_property("enchantment", 7);

    set_item_bonus("spell penetration", 4);
    set_item_bonus("caster level", 3);

    set_wear((: TO, "wear_func" :));
    set_remove((: TO, "remove_func" :));
    set_struck((: TO, "strike_func" :));

    set_lore("This set of bracers was made by the mage only known as " +
             "Tornado, a follower of Akadi. Fascinated with the power and grace" +
             " of the elements for everyday and combat use, he thought he would" +
             " honor them with bracers. He made a set of each element he thought" +
             " worthy, it is no accident no guards of the earth were never made.");

    set_property("quest required", "%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required", 35);
}

int wear_func()
{
    ::check();
    tell_room(EETO, "%^CYAN%^Beads of condensation appear on " + ETOQCN + "'s bracers as " + ETO->QS + " secures them. %^RESET%^", ETO);
    tell_object(ETO, "%^CYAN%^You feel a cooling sensation as you secure the bracers on.%^RESET%^");
    return 1;
}

int remove_func()
{
    tell_room(EETO, "%^CYAN%^" + ETO->QCN + "%^CYAN%^%^BOLD%^ reluctantly removes the bracers.%^RESET%^", ETO);
    tell_object(ETO, "%^CYAN%^You reluctantly remove the bracers and feel a bond lessen.%^RESET%^");
    return 1;
}

int strike_func(int damage, object what, object who)
{
    if (!random(2)) {
        tell_room(environment(query_worn()), "%^CYAN%^Droplets of water drip off of " +
                  "" + ETO->QCN + "'s bracers as " + ETO->QS + " surges forward to parry " +
                  "" + who->QCN + "'s attack.%^RESET%^", ({ ETO, who }));
        tell_object(ETO, "%^CYAN%^You feel power surge through you like a tidal" +
                    " wave as parry " + who->QCN + "%^CYAN%^%^BOLD%^'s wild thrust with your bracers.%^RESET%^");
        tell_object(who, "%^CYAN%^" + ETO->QCN + " surges forward to parry your attack as" +
                    "droplets of water drip off " + ETO->QP + " bracers.%^RESET%^");
        return 0;
    }
    return damage;
}
