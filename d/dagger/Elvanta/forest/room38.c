#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property ("light", 2);
set_property("indoors", 0);
set_short ("A pathway through the trees in the Deep Shadow Forest");
set ("day long", "%^ORANGE%^The inn still lies to the north of you, and perhaps it would be a good idea to rest.  There doesn't seem to be much ahead of you and a rest would do you good.  Large boughs from the redwoods now form the pathway, they are wide enough to have a party here.  The <boughs> themselves seem to have melded together to make a roadway above the ground.%^RESET%^");
set ("night long", "%^CYAN%^The inn still lies to the north of you, and perhaps it would be a good idea to rest.  There doesn't seem to be much ahead of you and a rest would do you good.  Large <boughs> from the redwoods now form the pathway, they are wide enough to have a party here.  The boughs themselves seem to have melded together to make a roadway above the ground.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nYou smell the scent of the forest but also a heady flower coming from ahead of you.");
set_listen ("default", "The sounds of the forest are all around you, and also the sounds of merrymaking is coming from the inn.");
set_exits (([
"north" : "/d/dagger/Elvanta/forest/Inn2",
"northeast" : "/d/dagger/Elvanta/forest/Inn1",
"east" : "/d/dagger/Elvanta/forest/room37",
"northwest" : "/d/dagger/Elvanta/forest/room39"
]));
set_items
(([
"boughs" : "At this point you wonder how the city was formed.  The boughs you walk upon now have formed pathways of their own accord.  How was this done, you wonder?  Who could have the power to tell trees how and where to grow.",
"globes" : "These globes are welcome in this forest and light your way.  They are approximately two feet in diameter and give off a warm blue light.  They are hung from intricately braided silver chains.",
"owls" : "Very large owls live here in this forest.  They stand about four feet tall, and have large talons and a wicked beak.  They hoot from thier perches, and it would be wise to give them a wide berth.",
"forest" : "This forest feels comfortable, you are not afraid as you walk through the circle of trees.  However, it might not be a bad idea to still be on your guard.",
"squirrels" : "These little creatures are of all colours, brown, black and grey.  Their chittering reminds you of small children laughing.",
"birds" : "Birds of many different hues live in this forest, protected it seems, by the keepers.",
"animals" : "As you walk through this city you notice how many small animals make their homes here as well, mice, crickets, rabbits, and other four legged and six legged creatures.  They seem not to be alarmed by your passing.",
"light" : "You see small round beams of light throughout the trees, it gives a warm and gentle feeling to the forest.",
"lights" : "Large globes held in silver chains hang from the trees.  It appears they mark the way through the forest.  At least you hope so.",
"trees" : "The trees in this forest appear to be larger than you first thought.  You could build a home within any one of them and have room left over.  Now you understand why you couldn't find the city of Elvanta.",
"tree" : "You now understand why you couldn't find the city before, it is HERE, in the trees themselves.  As you look around you see small and large buildings laid out in a spiral in front of you."
]));
}
void reset(){
::reset();
if(!present("dwarf"))
new("/d/dagger/Elvanta/forest/mon/dwarf")->move(TO);
}
