#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int tracker, tracker2;

void create() {
   ::create();
   set_name("mark");
   set_id(({"mark","marking","racial mark","dark mark","dark marking"}));
   set_short("a small dark marking");
   set_long("%^RESET%^%^ORANGE%^This is a small marking, almost a smudge. "
"It must be some kind of birthmark.%^RESET%^\n");
   set_type("ring");
   set_limbs(({"left arm"}));
   set_weight(0);
   set_value(0);
   set_size(2);
   set_ac(0);
   set_property("no remove",1);
   set_property("death keep",1);
   set_property("enchantment",-1);
   while((int)query_property("enchantment") >= 0){
     remove_property("enchantment");
     set_property("enchantment",-1);
   }
   set_wear((:TO,"wear_fun":));
   tracker = 0;
}

void init() {
   ::init();
   add_action("myracial","racial");
}

int wear_fun() {
   tell_object(ETO,"%^ORANGE%^The mark adheres to your skin.%^RESET%^\n"
"%^RED%^You can %^YELLOW%^<racial blind target>%^RESET%^%^RED%^ and 
%^YELLOW%^<racial blur>%^RESET%^%^RED%^ once per SG day (8 hours "
"realtime).%^RESET%^\n");
   return 1;
}

void set_property(string prop, mixed value){
   if(prop == "enchantment" && value > 0) return;
   ::set_property(prop, value);
}

int myracial(string str){
   string mytarg;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!TO->query_worn()) {
     tell_object(TP,"You need to be wearing the mark.");
     return 1;
   }
   if(!str) {
     tell_object(TP,"You can only use <racial blur> or <racial blind target> as a svirfneblin.");
     return 1;
   }
   if(str == "blur") {
     if(tracker > time()) {
       tell_object(TP,"You've already used your innate blur ability today.");
       return 1;
     }
     tracker = time() + 28800;
     new("/cmds/spells/b/_blink")->use_spell(TP,TP,(int)TP->query_level(),100,"mage");
     return 1;
   }
   if(sscanf(str,"blind %s",mytarg) == 1) {
     if(tracker > time()) {
       tell_object(TP,"You've already used your innate blindness ability today.");
       return 1;
     }
     if(!present(mytarg,ETP)) {
       tell_object(TP,"You don't see any "+mytarg+" here to cast that on.");
       return 1;
     }
     tracker = time() + 28800;
     new("/cmds/spells/c/_cause_blindness")->use_spell(TP,present(mytarg,ETP),(int)TP->query_level(),100,"cleric");
     return 1;
   }
   tell_object(TP,"You can only use <racial blur> or <racial blind target> as a svirfneblin.");
   return 1;
}
