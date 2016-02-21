//kunlun
inherit ROOM;

void create ()
{
        set ("short", "凌云阁");
        set ("long", @LONG
    这座大殿里金碧辉煌紫气瑞瑞，根根玉柱雕麒麟，殿窗是金钉
银檐，殿顶亦上是金银鸳鸯双双对对，正中有一白玉玛瑙莲花
台。东南方是休息室。北面传来阵阵练武声。
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "south" : __DIR__"shijie1",
                "north" : __DIR__"lianwu",
                "southeast" : __DIR__"xiuxishi",
        ]));
        set("objects", ([ 
                __DIR__"npc/jinzha" : 1,

   ]));
       setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "southeast" ) {
        if (objectp(present("jin zha", environment(me)))) {
        if((string)me->query("family/family_name")=="昆仑山玉虚洞") {
        return ::valid_leave(me, dir);
        }
        return notify_fail("金吒喝到：你不是本门弟子，那不是你该去的地方！\n");
        }
        }
        return ::valid_leave(me, dir);
}

