// Room: /d/shaolin/zhonglou7.c
// Date: YZC 96/01/19

inherit ROOM;
void create()
{
        set("short", "钟楼顶层");
	set("long", @LONG
这里就是钟楼之顶。直入眼帘的便是那口大钟和一根悬挂空
中的巨杵。细看大钟，整整有两丈来高，直径也有丈许。钟身似
由青铜浇铸，上面满是密密麻麻的印文古篆，估计重逾数千斤。
巨杵粗可合抱，丈把来长，一头裹以厚皮，正对着钟腰。尽管山
风吹人欲倒，谁都禁不住想撞一下钟试试。往外看，有个很
大的汉白玉窗台，上面足可站一个人。
LONG );
	set("exits", ([
                "out" : __DIR__"zhonglou",
	]));
		set("objects",([
                __DIR__"npc/saodiseng" : 1,
                        ]));
//	set("no_clean_up", 0);
	setup();
}

