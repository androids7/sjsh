//shulin 密林

inherit ROOM;

void create ()

{
        set ("short", "密林深处");
        set ("long", @LONG
这里一片朦胧,一切都是那么的飘渺...虚幻...
只有一些小路,领着偶尔到访的少些人迷恋此处.
不过前方似乎有一丝明亮,想是快到出口了.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));
        set("exits", 
        ([ //sizeof() == 4
                "east" : "/d/calvin/milin/milin5",
       "south" : "/d/calvin/milin/milin7",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
