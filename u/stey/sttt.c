//yitianjian.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIC "飞舞神剑" NOR, ({ "feiwu jian", "feiwu","jian" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
                set("value", 100000);
//        	set("no_drop", "1");
        	set("material", "iron");
                set("long", "这是飞舞杀神的第一利器，有“非神不杀，非怪不诛”之说。\n");
        	set("wield_msg","直如矫龙吞水，长虹冠日一般，$n已在$N手中，天地为之变色。\n");
        	set("unwield_msg", "$N将$n插回腰间，华光顿敛，天地间只闻龙鸣。\n");
				set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
               	}
        init_sword(140);
	setup();
}
