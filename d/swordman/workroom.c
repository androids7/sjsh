//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
void create ()
{
  set ("short","警示厅办事处");
  set ("long", @LONG

剑客警示厅处理大小事物的地方，正中坐着一个警官模样的人，正用冷
峻的眼神打量着你。
LONG);
   set("exits", ([      
       "west" : __DIR__"jingshiting",
       "north" : __DIR__"woshi",
  ]));
   set("objects", ([ 
      __DIR__"npc/zhaitengyi" : 1,
       ]));

  setup();
}









