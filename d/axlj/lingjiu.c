#include <ansi.h>
inherit ROOM;
string *msgs = ({
  "求经者，万缘都罢。",
  "了性者，诸法皆空。",
  "大智闲闲，澹泊在不生之内。",
  "真机默默，消遥于寂灭之中。",
  "三界空而百端治，六根净而千种穷。",
  "若乃坚诚知觉，须当识心。",
  "心净则孤明独照，心存则万境皆清。",
  "真容无欠亦无余，生前可见。",
  "幻相有形终有坏，分外何求。",
  "行功打坐，乃为入定之原。",
  "布惠施恩，诚是修行之本。",
  "大巧若拙，还知事事无为。",
  "善计非筹，必须头头放下。",
  "但使一心不动，万行自全。",
  "若云采阴补阳，诚为谬语，服饵长寿，实乃虚词。",
  "只要尘尘缘总弃，物物色皆空。",
  "素素纯纯寡爱欲，自然享寿永无穷。",
});

void create ()
{
  set ("short", "大雪山灵鹫密室");
  set ("long", @LONG
[1;33m这里就是当年如来佛祖得道成佛的地方大雪山灵鹫洞密室,[2;37;0m
[1;33m现在是佛母-[2;37;0m-[1;33m孔雀大明王菩萨的道场，[2;37;0m
[1;33m这里仙气四溢，不愧为当世修佛者梦寐以求的圣地。[2;37;0m
LONG);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kongque" : 1,
]));
  set("no_magic", 1);
  setup();
}
void init ()
{
  add_action ("do_canwu", "canwu");
  add_action("do_out","out");
add_action("do_action", ({"ji","cast"}));  
}
int do_action(string arg)
{
        write("没有参悟就想跑了?\n");
        return 1;
}
int do_canwu ()
{        object m;

  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query_temp("xiuluo/lingjiu_canwu");
  int j;

       if( who->query("xiuluo/lingjiu_ok") == 1 ) 
   return notify_fail ("你已经很明白了，你还需要参悟吗？\n");

  if (who->is_busy())
    return notify_fail ("你正忙着呢！\n");

  message_vision ("$N盘膝而坐，开始参悟灵鹫洞中的奥妙。\n",who);
  if (i >= size)
  {      
    message_vision ("\n$N沉思少顷，觉得已经领悟到了灵鹫洞中的秘密。\n",who); 
    message_vision("$N站起身来，向洞顶中心望去，顿时灵台一片清明(out dong)。\n", who);
    who->set("xiuluo/lingjiu_ok",1);  
  }  
  else
  {
    j = i*18+10;
    who->start_busy (j,j);
    call_out ("start_canwu",5,who,i);
    call_out ("finish_canwu",j,who);
  }
  return 1;
}
void start_canwu (object who, int i)
{
//  message_vision ("\n$N念道："+msgs[i]+"\n",who); 
//  message_vision ("\n片刻，$N开始参悟灵鹫洞中的秘密。\n",who); 
  who->set_temp("xiuluo/lingjiu_canwu",i+1);
}

void finish_canwu (object who)
{
  object where = environment(who);

  who->interrupt_me ();
  message_vision ("\n$N参悟完毕，站了起来，似乎还没有领悟到灵鹫洞中的秘密。\n",who); 
  // much slower than normal speed, just a symbolic reward
  where->add("times",1);
  if (where->query("times") < 1)
  {
    who->add("potential",random(3)+1);
    tell_object(who,"你发觉自己好象得到了什么东西一样！\n");
  }
}
int do_out(string arg)
{
        object me;
        me = this_player();
        if (!arg||arg!="dong") return 0;
        write("你运力双臂，双手扶着一块岩石，大喝一声：“开！”\n");
       if( me->query("xiuluo/lingjiu_ok") != 1 ) 
                {
                write("你没有参悟出洞中的奥秘，无论如何是出的去的。\n");
                return 1;
                };
        write("洞顶开始缓缓转动，刹时间你回到了灵山脚下。\n");
        me->move("/d/qujing/lingshan/shanjiao");
        return 1;
}
