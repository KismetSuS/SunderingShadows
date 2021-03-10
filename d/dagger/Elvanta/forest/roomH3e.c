#include <std.h>
inherit ROOM;

void create()
{
:: create();
set_property("light", 2);
set_property("indoors", 1);
set_short ("Elvanta city, a home");
set_long ("%^GREEN%^This is another bedroom, however, must be a childs.  Toys, books and games lie all over the room creating an image of chaos.  A <clothes press>, a <bed>, a small <table> and <fireplace> are located in this room as well.  Pale yellow drapes cover the porthole <window>.%^RESET%^");
set_smell ("default", "%^MAGENTA%^\nThe smell of lavender reaches your nose from small sachets placed in the clothes press.");
set_listen ("default", "You heave only the whisper of the wind through the trees.");
set_exits( ([
"east" : "/d/dagger/Elvanta/forest/roomH3c"
]) );
set_items(([
"clothes press" : "This is a wooden box, five feet long, three feet wide and two and a half feet tall.  It is to hold clothes and extra blankets for those who live here.",
"bed" : "This bed is so inviting.  It is a large four posted bed, with comforters filled with down.  The colour are pale blue, green, and yellow and blend well with the wood.",
"table" : "A small oval table rising three feet high upon a finely carved base holds a bouquet of heart's ease.",
"fireplace" : "The fireplace is set on the north wall, created by dark green stone, and has a grate of iron loaded with tinder waiting for a strike.",
"window" : "The window is draped by deep green velvet.  It looks out upon the forest and the small creatures dwelling there."
]) );
}
void reset(){
::reset();
if(!present("elfchild"))
new("/d/dagger/Elvanta/forest/mon/elfchild")->move(this_object());
}
