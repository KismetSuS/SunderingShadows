//ring1.c

#include <std.h>

inherit OBJECT;

void create(){
   ::create();

   set_name("Silver ring of the South");
   set_short("%^BOLD%^Silver ring of the South");
   set_id(({"ring","silver ring","south","ring2"}));
   set_long(
@OLI
   This is the south or bottom ring in the symbol of Ibrandul.
OLI
   );
   set_weight(3);
   set_value(1);
}
