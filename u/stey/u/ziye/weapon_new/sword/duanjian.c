//add keenness by ziye 2001/3

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�̽�", ({ "duan jian", "sword", "duanjian", "jian" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������С�ľ��ֽ���\n");
		set("value", 500);
		set("material", "steel");
              set("keenness", 5);
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(15);
	setup();
}