#include <ansi.h>
inherit ROOM;
void create()
{
   set("short", "简陋的办公室");
    set("long", 
"房间四周扔满了一些废纸张。一张写字台上就一台破旧的电脑。
四周堆放着一些书，凌乱不堪，主人找起来却似乎很方便\n"
HIY "           月儿弯弯\n"
   "           香烟袅袅\n\n"
HIG "     电子信箱:jie_xixi@cnnb.net\n\n" NOR
);
set("sleep_room", 1);
        set("no_death", 1);
        set("valid_startroom", 1);
        set("exits", ([
            "down" :"/d/city/kezhan.c",
            "up" :"/d/wiz/wizroom.c",
            "city" :"/d/city/center.c",
           "moon" :"/d/moon/lotuspond.c",
        ]));
       setup();
        replace_program(ROOM);
}
