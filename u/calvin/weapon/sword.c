// 莫邪圣剑 by Calvin

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIW"莫邪圣剑"NOR, ({"moxie sword", "moxie","sword"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100000);
               set("no_sell", "卖?别逗了,这种罕见的东西可以买卖吗!\n");
//                 set("no_get", "什么,你想捡? 做梦！\n");
                set("material", "steel");
                set("long", "相传为莫邪专用的宝剑，剑身透亮,锋利无比。\n");
                set("wield_msg", "一道紫光闪过，$N手中已多了把$n。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_sword(60);
        setup();
}

void init()
{
  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
        add_action("do_xiulian","xiulian");
}
void destruct_me(object where, object me)
{
        object pearl;
        if( pearl=new("/d/obj/weapon/sword/changjian"))
                pearl->move(where);
        message_vision("$N手中的$n突然一道白光，一阵烟雾过后便失去了颜色。\n",where,me);
        destruct(me);
}

int do_xiulian()
{
        object me,a,b,real;
        me=this_player();
        a=this_object();

        if( (int)me->query("force") < 2000)
                return notify_fail("你的内力不够,莫邪剑的心诀总是参悟不到。\n");
        if( (int)me->query("mana") < 2000)
                return notify_fail("你的法力不够,莫邪剑的心诀总是领悟不透。\n");

         if ( !(c=present("ganjiang sword",me)))
                return notify_fail("你努力参悟日月心诀,可是总是不能领会其奥妙。\n");

        if( real=new("/d/calvin/weapon/rysj")){
                destruct(b);
        real->move(me);

        message_vision("$N终于通过努力参悟日月心诀而使得干将莫邪双剑合二为一。\n",me);
        destruct(a);
        }
        return 1;
}
