// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

//created by night 7/24/2000
 
inherit ROOM;

void create ()
{
  set ("short", "太和街");
  set ("long", @LONG

太和街从蠙城中心广场直达东门外，延伸三里，是城内主要街道。街面是
由碗口大的彩色石块铺成，青兰紫绿，煞是好看。东面就是城门，几个卫
士在城门下巡视，查看着来往的人们。
LONG);

  set("exits", ([
        "east"   : __DIR__"dongmen",
        "west"   : __DIR__"jiedao9",
        "southwest"   : __DIR__"jiedao12",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}


