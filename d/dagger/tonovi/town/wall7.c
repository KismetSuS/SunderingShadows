#include "/d/dagger/tonovi/town/short.h"

inherit "/d/dagger/tonovi/town/wall4"; 

void create(){
    ::create();
    set_exits( ([
	"east" : RPATH "wall6",
	"west" : RPATH "wall8",
      ]) );

}
