//tianpei 天篷
//by calvin and leox 共同开发
//版权所有,未经许可不得翻录

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "寝室");
        set ("long", @LONG
这是一间很大的寝室,地面干净明洁,房间布局合理
摆放整齐的休息案板上有好多弟子盘膝而坐,看得出都
是在不断进修自己。
LONG);
        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4]
        "east" :"/d/tianpeng/mingyue",
]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("sleep_room",1);
        set("if_bed",1);                             
//      set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
