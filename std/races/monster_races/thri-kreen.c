#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 3, 3, 3, 3, 3, 3 }); }
int *max_stats() { return ({ 18, 18, 18, 18, 18, 18 }); }
int *stat_adj()  { return ({ 0, 0, 0, 0, 0, 0 }); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 17, 45, 60, 90 }); }

int *restricted_alignments() { return ({}); }

string *restricted_classes() { return ({}); }

int is_restricted() { return 1; } // restricted races by approval



// Stuff needed to replace what was in the old race database

string race_name() { return "thri-kreen"; }

int sight_bonus() { return 4; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 10000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "upper right hand", "upper left hand", "right hand", "left hand", "lower right hand", "lower left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : 0, "con" : 0, "int" : 0, "wis" : 0, "dex" : 0, "cha" : 0 ]); }

int size() { return 3; }

int natural_AC() { return 2; }


string *limbs()
{
    return ({   "head",
                "upper right arm",
                "upper right hand",
                "upper left arm",
                "upper left hand",
                "lower right arm",
                "lower right hand",
                "lower left arm",
                "lower left hand",
                "right arm",
                "right hand",
                "left arm",
                "left hand",
                "waist",
                "neck",  });
}