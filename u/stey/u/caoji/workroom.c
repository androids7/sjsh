// Room: /u/guoth/workroom.c
inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short",HIR "八大王屠宰场" NOR);
         set ("long", @LONG

你现在正站在游戏兔子开发部最靠东的客厅，四处杂乱放着蚊香，电热杯
等。到处都可以看到用过的一次性杯子堆满在桌面上，其中有几个还盛满了
烟头。几台开了机箱，裸露着各个零步件的的电脑可怜兮兮地工作着。音箱
里正传出Beyond的歌--《大地》。客厅的墙壁上还挂着一张zmud的地图
(Maps),仔细看上去地图上边好象还写了一首诗(shi)。
LONG);

            set("exits", ([
                    "kezhan" :  "/d/city/kezhan",
                    "wizroom" :  "/d/wiz/wizroom",
                    "system" :  "/d/wiz/system",
                    "guest" :  "/d/wiz/guest",
                      "up" :  "/u/caoji/sleeproom",
                      "center" :  "/u/city/center",
                     ]));   

            set("item_desc", ([
                "Maps" : HIB "\n不识情恶枉少年，檐下赐酒结仙缘,情难消受美人恩，仗剑江湖为红颜。\n" NOR,
                "shi" : BLINK HIW "\n☆游戏兔子 提☆ 2000.10.27\n" NOR,
           ]));

       set("no_fight",1);
       set("valid_startroom", 1);

        set("no_clean_up", 0);
       setup();
        replace_program(ROOM);

}
