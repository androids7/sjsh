#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
        set_name(CYN "铜牌" NOR, ({ "tongpai", "pai" }));
        set("long", @LONG
这是一块黑黝黝的铜牌，上面写着“王府令牌”四个小字。�
LONG);
        set("weight", 100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("value", 0);
                set("material", "铜");
                set("armor_prop/armor", 1);
        }
        setup();
}

