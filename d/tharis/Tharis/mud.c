//cstarage.c

#include <std.h>
#include "/d/shadow/mon/melnmarn.h"

inherit ROOM;

void create(){
	::create();
	set("short","Why bother");
	set("long","The long for a storage room");
	set_property("no teleport", 1);
}
	
void reset(){
	object ob;
	::reset();
	
	if(!present("plate")){
		ob=new("/d/common/obj/armour/plate");
//		ob->set_property("enchantment",1);
		ob->move(TO);
	}
	
	if(!present("ring")){
		new("/d/deku/armours/ring_p")->move(TO);
	}
	if(!present("ring")){
		new("/d/deku/armours/ring_p")->move(TO);
	}
	
/*
	if(!present("book")){
		ob=new("/d/magic/spellbook");
		ob->set_spellbook("magic missile");
		ob->set_spellbook("lightning bolt");
		ob->set_spellbook("monster summoning iii");
		ob->set_spellbook("cone of cold");
		ob->set_spellbook("burning hands");
		ob->set_spellbook("web");
		ob->move(TO);
	}
*/
	
	if(!present("sword")){
		ob=new("/d/common/obj/weapon/two_hand_sword");
		ob->set_property("enchantment",1);
	}
   if(!present("scroll")) {
           ob=new("/d/magic/scroll");
           ob->set_spell(4);
           ob->move(TO);
   }
   if(!present("scroll 2")) {
           ob=new("/d/magic/scroll");
           ob->set_spell(4);
           ob->move(TO);
   }
}
 
