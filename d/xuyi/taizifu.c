// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /xuyi/taizifu.c
//cglaem...12/12/96.
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "太子府");
  set ("long", @LONG

这里是小太子的府邸，里面虽然不华丽，但是自然有一种高贵的幽雅的气
息，正首上坐着一个剑眉虎目的年轻人在那里吟诗做画。旁边小丫鬟端着
茶水，探头欣赏。
LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/d/xuyi/npc/prince" : 1,
  "/d/xuyi/npc/yahuan2" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"piandian",
]));

  setup();
}

