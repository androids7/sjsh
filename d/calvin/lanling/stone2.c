//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "石头大街");
        set ("long", @LONG

这里是兰陵城的第二发达大街,这的交通发达,路上来往
游人特别的多.再往西去就是南海之滨了.大街两边的商
店也特别的多,真不亏为天下第一城 ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : "/d/calvin/lanling/stone3",
                "east" : "/d/calvin/lanling/stone1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
   "/d/qujing/zhuzi/npc/people" : 2,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
