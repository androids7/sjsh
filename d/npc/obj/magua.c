// magua.c

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIY"黄马褂"NOR, ({ "magua"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "皇上穿的黄马褂．\n");
                set("unit", "件");
                set("value", 0);
                set("no_give",1);
                set("no_zm",1);
                set("no_put",1);
                set("material", "cloth");
                set("armor_prop/armor", 50);
        }
        setup();
}

