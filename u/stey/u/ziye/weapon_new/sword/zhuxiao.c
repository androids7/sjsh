//Cracked by Roath
// created by ajax on 7/8/1999

#include <weapon.h>


inherit SWORD;

void create()
{
    set_name("竹箫", ({ "zhu xiao","xiao","zhuxiao"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("material", "wood");
        set("long", "韩湘子的紫金箫掉了，只好拿竹子重新做了一根。\n");
                set("no_sell", 1);
                set("no_drop", 1);
                set("no_put", 1);
                set("value", 0);
                set("wield_msg", "$N拿起一根$n放在唇边轻轻一吹。\n");
                set("unwield_msg", "$N笑了一笑，将$n插回腰间。\n");
                set("weapon_prop/int", 1);
                set("music/type", "xiao");
	}
    init_sword(5);
	setup();
}
