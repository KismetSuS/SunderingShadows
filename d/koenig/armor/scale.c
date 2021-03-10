inherit "/std/armour";

void create() {
    	::create();
    	set_name("scale");
    	set_id( ({ "scale","armor", "scale mail","mail" }) );
    	set_short("a suit of scale mail armor");
    	set_long("This is a coat and leggings of leather covered with overlapping "+
		"pieces of metal, much like the scales of a fish or snake."
    	);
    	set_weight(40);
    	set("value", 120);
    	set_type("armour");
    	set_limbs( ({ "torso" }) );
    	set_ac(4);
}
