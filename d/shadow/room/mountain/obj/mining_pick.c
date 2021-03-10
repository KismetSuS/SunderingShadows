// mining_pick.c.  Changed by Circe 11/27/03 to fix problems with bugging

#include <std.h>

inherit "/d/common/obj/weapon/pick";

int count;

void create(){
    ::create();
    set_id(({"pick","mining pick"}));
    set_name("mining pick");
    set_short("a mining pick");
    set_long("This pick has a long wooden handle set into a sturdy metal head.  "+
       "One side of the metal head is more like a hammer, while the other tapers "+
       "to a blunt point that helps break away rock in the mines.  Despite its "+
       "fitness for manual labor, it would probably bludgeon someone fairly well "+
       "if the wielder was attacked.");
    set_lore("This mining pick looks to have been made by the dwarves.  "+
       "No runes are carved into its surface, but the precise bevelling "+
       "of the head and the small wooden crosspiece that reinforces "+
       "the joint are both tell-tale signs of dwarven craftsmanship.  "+
       "Further, the slightly greenish cast of the iron suggests that "+
       "it was probably mined in Echoes Mountains - most likely where "+
       "it was used as well.");
    set_property("lore difficulty",5);
   //set_weight(6);
   //set_size(2);
   //set_wc(1,6);
   //set_large_wc(2,4);
   //set_type("bludgeoning");
   //set_prof_type("tool");
   //set_weapon_speed(5);
    set_value(10);
}

void init(){
    ::init();
    add_action("mining","mine");
}

int mining(string str){
    if(!str) return notify_fail("Mine what?\n");
    if(member_array(str,({"walls","wall","rock","gems"})) == -1) return notify_fail("You cannot mine that!\n");
    if(!ETP->is_mine()) return notify_fail("You cannot mine here.\n");
    if(TP->query_property("is_mining")) return notify_fail("You are already mining!\n");
    if(!TO->query_wielded()) return notify_fail("You must be wielding the pick to use it.\n");
    if(present("dwarven miner",environment(ETO))){
      object grumpy;
      grumpy = present("dwarven miner",environment(ETO));
      grumpy->force_me("emote grunts and looks around stonily.");
      grumpy->force_me("say These here mines belong to us!");
/*       tell_object(TP,"The dwarven miner grunts and looks at you stonily.");
       tell_room(environment(ETO),"The dwarven miner grunts and looks at "+ETO->query_cap_name()+" stonily.",ETO);
       tell_room(environment(ETO),"%^MAGENTA%^Dwarven worker says%^RESET%^: These here mines belong to us!");
*/
       tell_object(TP,"You start swinging the pick, looking for anything interesting. Gee this is hard work!");
       tell_room(ETP,TPQCN+" starts swinging a pick.",TP);
    }
    else{
       tell_object(TP,"You start swinging the pick, looking for anything interesting. Gee this is hard work!");
       tell_room(ETP,TPQCN+" starts swinging a pick.",TP);
    }
    TP->set_property("is_mining",1);
    TP->set_paralyzed(5,"You are busy mining.");
    call_out("while_mining",10,TP);
	 TP->use_stamina(20);
    count == 1;
    return 1;
}

void while_mining(string str2){
   count++;
    if(!TO->query_wielded()) {
    	tell_object(TP,"You can't keep mining without the pick.");
//    	call_out("end_mining",5,TP); - Removed so they don't get anything if they unwield the pick.  Circe
		TP->remove_property("is_mining");
		return;
	}
	if(!ETP->is_mine()) {
    	tell_object(TP,"You can't mine here.");
		TP->remove_property("is_mining");
		return;
	}
	if(TP->query_unconscious()) {
    	tell_object(TP,"You probably should have rested sooner.");
		TP->remove_property("is_mining");
		return;
	}

  	TP->set_paralyzed(5,"You are busy mining.");
   switch (count) {
      case 1..2: 
      	tell_object(TP,"Dirt and chips of rock fly from the walls from your pick striking them.");
			tell_room(ETP,"Dirt and chips of rock fly from the walls where "+TPQCN+"'s pick strikes them.",TP);
			TP->use_stamina(5);
    		call_out("while_mining",5,TP);
    		break;
	   case 3: 
			tell_object(TP,"The dirt and rocks are piling up but no gems yet.");
			tell_room(ETP,"The dirt and rocks are piling up from where "+TPQCN+" is mining.",TP);
			TP->use_stamina(10);
    		call_out("while_mining",7,TP);
    		break;
    	case 4:
 			tell_object(TP,"Some sweat runs in your eyes and burns as you keep working at the mining.");
			tell_room(ETP,TPQCN+" is getting sweaty and looking tired from swinging the pick.",TP);
			TP->use_stamina(10);
    		call_out("while_mining",10,TP);
    		break;
    	case 5:
 			tell_object(TP,"Your arms are getting sore and you realize you're going to need some rest after this.");
			tell_room(ETP,TPQCN+" is getting sweaty and looking tired from swinging the pick.",TP);
			TP->use_stamina(15);
    		call_out("end_mining",10,TP);
         break;
   }
}

int end_mining(object who){
    int total, found, i;
    object ob, where;

    if(!objectp(who)) return 1;
    where = environment(who);
    if(!objectp(where)) return 1;
    tell_object(who,"You stop swinging the pick and look to see if you found anything.");
    tell_room(where,who->query_cap_name()+" stops swinging "+who->query_possessive()+" pick and looks around.",who);
    who->remove_property("is_mining");
    total = where->query_to_find();
    if(!random(2)){ 
        found = random(total)+1;
        where->set_found(found);
        for(i=0;i<found;i++) {
            ob = where->get_found_ob();
            ob->move(where);
        }
        tell_room(where,"You hear something fall to the ground.");
        tell_object(who,"Your hard work has paid off!");
    }
    else{
        tell_object(who,"After all your work, you still find nothing here this time!");
    }
    count = 1;
    return 1;
}
