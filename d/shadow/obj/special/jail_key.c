//  Jail Key-Opens Doors

inherit  "/std/armour";
void create() {
  ::create();
  set_name("Shadow jail key");
  set_id(({"key", "skeleton key", "Shadow jail key", "Shadow_jail_key_x"}));
  set_short("a skeleton key");
  set_long("This is a large black skeleton key on a very large, heavy chain "
     "that is attached to a wide leather belt.");
  set_property("no animate", 1);
  set_weight(20);
  set("value", 10);
  set_type("clothing");
  set_limbs( ({"waist"}) );
}
