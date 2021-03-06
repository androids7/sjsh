#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"桫椤刀"NOR,({ "suoluo dao", "dao", "blade" }) );
        set_weight(29000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "副");
                set("value", 1000000);
                set("unique", 1);
                set("rigidity", 6);
                set("sharpness", 4);
                set("weapon_prop/dodge", -8);
                set("weapon_prop/parry", 8);        
                set("material", "gold");
                set("wield_force", 300);
                set("wield_maxforce", 1100);
                set("wield_str", 25);
                set("wield_msg", HIY"只听见「啪」地一声，桫椤刀跃入$N手中，四周响起阵阵棼唱！\n"NOR);
                set("long", HIY"\n一把金色的长刀，上面刻有伏魔降妖真言。你可以将它分(fen)开。\n"NOR);
                set("unwield_msg", HIY "$N将桫椤刀放下，轻轻吁了口气。\n" NOR);               
        }
        init_blade(120);
        setup();
}

void init()
{
    add_action("do_sub",({"fen", "分"}));
}

int do_sub()
{
     object me, obj;
     me = this_player();
     obj = this_object();

     message_vision(HIY"\n只听霹雳 一声巨响，$N将桫椤刀向半空掷出，桫椤刀在空中一分为二，化为两道金光又飞回了$N的手中！\n"NOR, me);
     new("/u/xintai/weapon/fumodao")->move(me, 1);
     new("/u/xintai/weapon/xiangyaochan")->move(me, 1);  
     destruct(obj); 
     return 1;

}
