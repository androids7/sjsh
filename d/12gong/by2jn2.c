// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向肖犬宫的路上，只见前面可以看到奇特的戍宫耸立在佛陀峰上！
云雾中隐隐约约还可以看见山下的肖猪宫。
LONG);


        set("exits", ([
        "southup"    :       __DIR__"jinniu",
            "westdown"  :       __DIR__"by2jn1",
        ]));

        set("outdoors", "12gong");
        setup();
}
