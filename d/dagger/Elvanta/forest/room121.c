#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the Deep Shadow Forest");
set ("day long", "%^ORANGE%^The city <walkway> is crowded with elves, dwarves and men.  They seem to be busy going about their daily business, rushing to and fro.  <Children> race past you, laughing, people smile at you as you travel.  As you look southeast you being to notice the <spires> of either a castle or a church.%^RESET%^");
set ("night long", "%^CYAN%^The city <walkway>, lit by <globes> is less crowded at night, however, you see elves, dwarves and men travelling past you.  They smile as they pass.  In the distance you see <light> emanating from <spires> of either a church or a castle.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell the forest, green and alive.");
set_listen ("default", "Low murmurs of people passing by, laughter from children, general sounds of a small city surround you.");
set_exits (([
"northwest" : "/d/dagger/Elvanta/forest/room120",
"southeast" : "/d/dagger/Elvanta/forest/room122"
]));
set_items
(([
"spires" : "You see spires rise above the trees in the distance.  Whethere they belong to a church or castle has yet to be seen.",
"buildings" : "You see many buildings ahead of you, bank, stores, stables.",
"planks" : "Planks of wood line the walkway, intricate designs carved into each, the time spent on such artistry must have been someones lifetime.",
"globes" : "You see great round glass globes hung in delicate silver chains.  They may be used to light the way on a dark night.",
"light" : "You see small round beams of light throughout the trees, it gives a warm and gentle feeling to the forest.",
"branches" : "The branches can be walked upon they are so wide.  They travel through the forest like a maze.  It looks as though somehow they were coaxed to form roadways for the elves who live here.",
"children" : "Children scramble through the forest, running up and down the huge trees as if it was their personal playground, but, perhaps it is and you are the intruder.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"staircase" : "The staircase appears in front of you, how is that possible?  The vines holding the staircase above ground seems to be molded to the stairs.  Intricate designs of animals and flowers entweined adorn the stairs themselves.  The artwork is phenomenal.  Someone spent a lifetime carving these.",
"walkway" : "As you travel along the walkway you can't help notice how well it is built.  There is no swaying or shaking of the walkway.  The trees themselves seem to have molded the walkway and it is as sturdy as the ground below.",
"building" : "You look ahead and see a small building within the trees.  It looks like a guard post, perhaps.",
"tree" : "You now understand why you couldn't find the city before, it is HERE, in the trees themselves.  As you look around you see small and large buildings laid out in a spiral in front of you."
]));
}
void reset(){
::reset();
if(!present("elf"))
new("/d/dagger/Elvanta/forest/mon/elf")->move(TO);
if(!present("dwarf"));
new("/d/dagger/Elvanta/forest/mon/dwarf")->move(TO);
if(!present("ironroot treefolk"))
new("/d/dagger/Elvanta/forest/mon/ironroot")->move(TO);
}
