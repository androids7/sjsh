// �С�P ���P��   cfblade.c        created 17-06-2001 ����Ʈ(piao)


#include <weapon.h>
#include <ansi.h>


inherit BLADE;

void create()
{
        set_name(CYN"���P��"NOR, ({ "chaofeng blade", "blade", "chaofeng" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "½С��ı�����������װ����һֻ����������ˡ�\n");
                set("unit", "��");
	    set("wield_msg", "$N�ӵ��ʳ��һ��$n���������У�̾��������üë�ĵ���Ȼ������\n");
	    set("unwield_msg", "$N��������$n���뵶�ʣ�̾��������üë�ĵ���Ȼ������\n");
                set("value", 40000);
                set("material","wood");
        }
        init_blade(160);
        setup();
}
