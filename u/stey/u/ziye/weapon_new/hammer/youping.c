//add keenness by ziye 2001/3

#include <weapon.h>

inherit HAMMER;
inherit F_LIQUID;

void create()
{
        set_name("��ƿ", ({"youping"}));
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ��װ�͵�ƿ�ӣ�\n");
                set("unit", "��");
		set("value", 30);
              set("keenness", 0);
		set("max_liquid", 5);
                set("wield_msg", "$Nץ��һ��$n���������е�������\n");
                set("material", "bone");
        }

        set("liquid", ([
                "type": "water",
                "name": "����",
                "remaining": 5,
        ]) );
        init_hammer(1);
        setup();

}
