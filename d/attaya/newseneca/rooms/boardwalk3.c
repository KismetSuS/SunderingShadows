//adapted by ~Circe~ 11/22/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
   set_climate("tropical");
    set_light(1);
    set_indoors(0);
    set_name("On the Boardwalk");
    set_short("On the Boardwalk");
    set_long("This %^ORANGE%^wooden boardwalk %^RESET%^leads over a small "+
       "chasm to the town of %^BOLD%^Seneca%^RESET%^.  Its tall %^BOLD%^"+
       "co%^MAGENTA%^q%^WHITE%^ui%^BLACK%^n%^WHITE%^a walls %^RESET%^rise "+
       "high in the sky to the south, with much of the town hidden behind "+
       "them.  You can see a few buildings peeking above, most notably "+
       "the %^BOLD%^Castillo Blanco %^RESET%^and the famed %^YELLOW%^Cathedral"+
       "%^RESET%^ of Seneca.  Far below the %^ORANGE%^boardwalk%^RESET%^, "+
       "you see the %^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
       "%^RESET%^n sand of the beach.  Directly to the south is "+
       "the great %^BOLD%^%^BLACK%^portcullis %^RESET%^"+
       "leading into the city itself.\n");
    set_smell("default","The clean scent of the ocean rises on the breeze.");
    set_listen("default","Occasional noises from the city rise above the pounding of the ocean's waves.");
    set_items(([
       ({"boardwalk","wooden boardwalk"}) : "%^ORANGE%^The boardwalk is "+
          "made of wooden slats and supports and is very well-maintained.  "+
          "It runs between the wilder regions of Attaya over a chasm to the "+
          "walled city of %^BOLD%^%^WHITE%^Seneca%^RESET%^%^ORANGE%^.%^RESET%^",
       ({"town","city","Seneca","seneca"}) : "More properly called a city "+
          "than a town, Seneca has grown over the past several hundred years "+
          "despite the menace of the one called Intruder.  From here, you "+
          "can see many shops and homes, all crowded together within the "+
          "white walls that surround the city protectively.",
       ({"castillo","castillo blanco","Castillo Blanco"}) : "The pure white "+
          "walls of Castillo Blanco shimmer in the light.  The building "+
          "rises three stories, with a belltower soaring high above the walls.",
       ({"cathedral","Cathedral"}) : "The cathedral is encased in gold and "+
          "silver leaf, making it positively sparkle as long as there is "+
          "even a tiny bit of light.  It is almost dazzling to look upon "+
          "from here.",
       ({"sand","golden sand","beach"}) : "Looking down, you see the "+
          "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e"+
          "%^RESET%^n sand of the beach below.  It looks to be a drop of "+
          "about fifteen feet, though the boardwalk is not very wide.  "+
          "Still, you can't help but wonder if it was a man-made defense after "+
          "Intruder first made himself known."
    ]));
    set_exits(([
	"north" : ROOMS"boardwalk2",
	"south" : ROOMS"town_entry"
    ]));
   set_door("portcullis","/d/attaya/newseneca/rooms/town_entry","south","Seneca gate key","lock");
   set_door_description("portcullis","The portcullis is made from %^ORANGE%^"+
      "oaken planks %^RESET%^plated and bound with %^BOLD%^%^BLACK%^iron"+
      "%^RESET%^.  It may be raised or lowered from inside the guard house "+
      "by means of a series of pulleys and chains.");
   lock_difficulty("portcullis",-90, "lock");
   set_open("portcullis",1);
   set_lock_description("portcullis", "lock",
      "You cannot see the means to open the gate from here.  It would likely be barred from the other side.");
   set_string("portcullis","open","Screeching, the porcullis shudders into motion and rises.");
   set_string("portcullis","close","The portcullis shuts quickly, sliding into place.");
}
