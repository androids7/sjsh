
//Room: lianhuashi.c 莲花石
//Date: Oct. 2 1997 by That

inherit ROOM;
#include <ansi.h>

void create()
{
	  set("short","莲花石");
	  set("long",@LONG
这是莲花石。此处岩石纹理纵横，形似莲花，颜如芙蓉，仿佛萼瓣层叠，
细蕊欲绽。上有一庵，叫「莲花社」。由此往西上直达洗象池，东下左通十二
盘，右通九老洞。
LONG);
	  set("objects", ([
          __DIR__"npc/boydizi": 1,
	  ]));
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
	  "eastdown"  : __DIR__"shierpan",
          "southeast" : __DIR__"jldongkou",
          "westup"      : __DIR__"ztpo1",  
	  ]));
//	  set("no_clean_up", 0);
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
	 me->add("kee",-10);
	 if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		 me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	 tell_object(me,HIW"你在钻天坡往上爬了一阵，好累人。\n"NOR);
	  }
	  return 1;
}

