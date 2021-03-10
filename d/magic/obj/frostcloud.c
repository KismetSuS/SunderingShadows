#include <std.h>

inherit OBJECT;

int blocking = 0;
string exitname;
object caster;
int level;

void remove_wall();

void create() {
   ::create();
   set_name("cloud of frost");
   set_short("A cloud of frost");
   set_long("%^BOLD%^%^CYAN%^You see a massive cloud of frosty air drifting here, %^BOLD%^%^WHITE%^chilling %^BOLD%^%^CYAN%^everything it touches.");
   set_id( ({"wall","cloud of frost","frost cloud","frost"}) );
   set_weight(10000);
   set_value(0);
   set_property("no animate",1);
}

void init() {
   ::init();
   add_action("end_walls","remove");
   if(blocking)
      add_action("damager",exitname);
}

void surround(object ob) {
   int k,j,dmg;
   object *foes;
   string whose,wallname;

   caster = ob;
   add_action("end_walls","remove");
   foes = caster->query_attackers();
   whose = caster->query_name();
   level = caster->query_guild_level("mage");
   wallname = whose+"surroundingfirewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"The new wall simply melts into the wall that is already surrounding you!\n");
      tell_room(environment(caster),"The wall surrounding "+caster->query_cap_name()+" glows brighter for a second.\n");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!present(wallname,environment(caster))) continue;
      if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"cold") != -1)
         continue;
      tell_room(environment(foes[k]),"%^BOLD%^%^CYAN%^"+foes[k]->QCN+" is chilled by the icy cloud and leaps back as it forms!",foes[k]);
      tell_object(foes[k],"%^BOLD%^%^RED%^You get chilled by the icy cloud and jump away from "+caster->QCN+" as it forms up around "+caster->QO+".");
      if(foes[k]->query_property("undead")) dmg = 4+random(21);
      else dmg = 2+random(11);
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"cold" );
      if(objectp(foes[k]))
         foes[k]->continue_attack();
//          foes[k]->set_attackers((object *)foes[k]->query_attackers() -({caster}) );
//          caster->set_attackers((object *)caster->query_attackers() -({foes[k]}) );
   }
   call_out("monitor",7);
}

void monitor() {
   int k,j,dmg;
   object *foes;

   if((!objectp(caster) || !present(caster->query_name(),ETO)) && !blocking) {
      if(objectp(query_property("spell"))) {
         query_property("spell")->dest_effect();
         return;
      }
      remove_call_out("monitor");
      TO->remove();
   }
   if(objectp(caster)) {
   foes = caster->query_attackers();
   j = sizeof(foes);
   for(k=0;k<j;k++) {
      if(!objectp(foes[k])) continue;
      if(foes[k]->query_property("strength") &&
         strsrch(foes[k]->query_property("strength"),"cold") != -1)
         continue;
      tell_room(environment(foes[k]),"%^BOLD%^%^CYAN%^"+foes[k]->QCN+" is chilled by the cloud of frost!",foes[k]);
      tell_object(foes[k],"%^BOLD%^%^CYAN%^You get chilled by the cloud of frost!");
      if(foes[k]->query_property("undead")) dmg = 4+random(21);
      else dmg = 2+random(11);
      foes[k]->cause_typed_damage(foes[k],foes[k]->return_target_limb(),dmg,"cold" );
      if(objectp(foes[k]))
         foes[k]->continue_attack();
   } }
   call_out("monitor",7);
}

void block(object ob, string exitn) {
   string whose, wallname;

   blocking = 1;
   caster = ob;

   level = caster->query_guild_level("mage");
   exitname = exitn;
   set_short("A cloud of frost blocking the "+exitname);
   set_long("%^BOLD%^%^CYAN%^You see a massive cloud of frosty air drifting here, %^BOLD%^%^WHITE%^chilling %^BOLD%^%^CYAN%^everything it touches. It fully blocks the "+exitname+".");
   whose = caster->query_name();
   wallname = whose+exitname+"firewall";
   if(present(wallname,environment(caster))) {
      tell_object(caster,"The new wall simply melts into the wall that is already blocking the "+exitname+"\n");
      tell_room(environment(caster),"The wall blocking the "+exitname+" glows brighter for a second.\n");
      if(objectp(query_property("spell")))
         query_property("spell")->dest_effect();
      return;
   }
   add_id(wallname);
}

void remove_wall() {
   object *notsee = ({});
   string exitdesc = "";

   if(blocking)
      exitdesc = ", blocking the "+exitname+",";
   if(objectp(caster) && objectp(ETO)) {
      if(present(caster,ETO)) {
         notsee = ({caster});
         if(blocking)
            tell_object(caster,"%^RED%^Your cloud of frost"+exitdesc+" dissipates away.");
         else {
            tell_object(caster,"%^RED%^The cloud of frost that surrounds you dissipates away.");
            caster->move(ETO);
         }
      }
      tell_room(ETO,"%^RED%^"+caster->QCN+"'s cloud of frost"+exitdesc+" dissipates away.", notsee);
   }
   destruct(TO);
   return;
}

int damager(string str) {
   int dmg;
   if(TP->query_paralyzed() || TP->query_bound() || TP->query_tripped() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(caster)
      if((string)caster->query_name()==(string)TPQN )
         return 0;
   if(TP->query_property("strength") && strsrch(TP->query_property("strength"),"cold") != -1 ) {
      tell_object(TP,"%^BOLD%^%^CYAN%^You step into the cloud of frost, walking calmly through the chilled air, unharmed.");
      tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" walks calmly into the cloud of frost blocking the "+exitname+", unaffected by the chill.",TP);
      return 0;
   }
   tell_object(TP,"%^BOLD%^%^CYAN%^You step into the cloud of frost, rushing through before the air chills you badly.");
   tell_room(ETP,"%^BOLD%^%^CYAN%^"+TPQCN+" rushes into the cloud of frost blocking the "+exitname+", as the air chills "+TP->QO+"!",TP);
   if(TP->query_property("undead")) dmg = (roll_dice(2,6)+level+level/2)*2;
   else dmg = roll_dice(2,6)+level+level/2;
   TP->cause_typed_damage(TP,TP->return_target_limb(),dmg,"cold" );
   if(TP) TP->continue_attack();
   return 0;
}

int end_walls(string str) {
   if(!caster || (TP != caster))
      return 0;
   if(str != "wall")
      return 0;
   if(objectp(query_property("spell")))
      query_property("spell")->dest_effect();
   return 1;
}

int query_blocking(){
   return blocking;
}
