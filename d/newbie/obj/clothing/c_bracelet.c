#include <std.h>
#include "../../newbie.h"
inherit ARMOUR;

#define STONES ({"%^MAGENTA%^amethyst%^RESET%^",\
"%^BOLD%^%^WHITE%^ivory%^RESET%^",\
"%^BOLD%^%^BLACK%^ebony%^RESET%^",\
"%^GREEN%^agate%^RESET%^",\
"%^BOLD%^%^CYAN%^aquamarine%^RESET%^",\
"%^BOLD%^%^BLACK%^onyx%^RESET%^",\
"%^ORANGE%^amber%^RESET%^",\
"%^BOLD%^%^GREEN%^jade%^RESET%^",\
"%^BOLD%^%^WHITE%^crystal quartz%^RESET%^",\
"%^BOLD%^%^MAGENTA%^rose quartz%^RESET%^",\
"%^BOLD%^%^BLACK%^smokey quartz%^RESET%^",\
"%^ORANGE%^tigers eye%^RESET%^",\
"%^RED%^fire agate%^RESET%^",\
"%^BOLD%^%^WHITE%^moonstone%^RESET%^",\
"%^GREEN%^bloodstone%^RESET%^",\
"%^MAGENTA%^jasper%^RESET%^",\
"%^BOLD%^%^RED%^carnelian%^RESET%^",\
"%^YELLOW%^citrine%^RESET%^",\
"%^BLUE%^lapis lazuli%^RESET%^",\
"%^CYAN%^beryl%^RESET%^",\
"%^ORANGE%^topaz%^RESET%^",\
"%^CYAN%^malachite%^RESET%^",\
"%^BOLD%^%^BLUE%^blue spinel%^RESET%^",\
"%^RED%^red spinel%^RESET%^",\
"%^BOLD%^%^RED%^red jasper%^RESET%^",\
"%^GREEN%^moss agate%^RESET%^",\
"%^BOLD%^%^GREEN%^peridot%^RESET%^",\
"%^RED%^garnet%^RESET%^",\
"%^BOLD%^%^BLACK%^hematite%^RESET%^"})

int i, j, val;
string STONE, METAL;

void create_bracelet()
{
   j = random(sizeof(STONES));
   STONE = STONES[j];
   val = random(25)+5;
   switch(val) {
      case 5..7:
         METAL = "%^ORANGE%^brass%^RESET%^";
         break;
      case 8..11:
         METAL = "%^YELLOW%^bronze%^RESET%^";
         break;
      case 12..16:
         METAL = "%^BOLD%^%^WHITE%^silver%^RESET%^";
         break;
      case 17..21:
         METAL = "%^BOLD%^%^CYAN%^mithril%^RESET%^";
         break;
      case 22..25:
         METAL = "%^YELLOW%^gold%^RESET%^";
         break;
      case 26..27:
         METAL = "%^BOLD%^%^MAGENTA%^rose gold%^RESET%^";
         break;
      case 28..29:
         METAL = "%^BOLD%^%^WHITE%^white gold%^RESET%^";
         break;
   }
   set_value(val+1);
   set_cointype("silver");
   set_type("ring");
   set_limbs(({"left hand"}));
   set_weight(1);
   set_name("bracelet");
   set_id(({"bracelet",""+STONE+" bracelet",""+METAL+" bracelet",""+STONE+" "+METAL+" bracelet",""+METAL+" "+STONE+" bracelet"}));
   set_short("%^RESET%^"+STONE+" bracelet");
   set_long("This bracelet is made out of several round and"+
   " polished beads of "+STONE+" that are linked together with "+METAL+""+
   " links. A simple clasp holds it around one's wrist.");
}

void create()
{
   ::create();
   create_bracelet();
}

int query_size()
{
   if(!objectp(ETO)) return 2;
   return ETO->query_size();
}
