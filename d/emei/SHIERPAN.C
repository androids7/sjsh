
//Room: shierpan4.c 十二盘
//Date: Oct. 2 1997 by That

inherit ROOM;
#include <ansi.h>

void create()
{
	  set("short","十二盘");
	  set("long",@LONG
这里石阶陡折多弯，号称「十二盘」。由此向西过数坡，即到莲花石，东
下可到华严顶。
LONG);
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
	  "westup"	: __DIR__"lianhuashi",
	  "eastdown"  : __DIR__"huayanding",

	  ]));
	  set("no_clean_up", 0);
	  setup();
}
int valid_leave(object me, string dir)
{
	  int c_exp,c_skill;
	  me = this_player();
	  if (dir == "westup" )
	  {
	 c_exp=me->query("combat_exp");
	 c_skill=me->query_skill("dodge",1);
	 me->add("kee",-1);
	 if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		 me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	 tell_object(me,HIW"你沿十二盘又往上爬了一阵，终于到了莲花石，好累人。\n"NOR);
	  }
	  return 1;
}

