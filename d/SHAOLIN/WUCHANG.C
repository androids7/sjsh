// Room: /d/shaolin/wuchang.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡�
��ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����߽��ϻ�
��������ɳ�ӣ�ʮ����ɮ��������ϰ���ա������������һ����
����
LONG );
	set("exits", ([
		"south" : __DIR__"houdian",
                "east" : __DIR__"luohan5",
                "west" : __DIR__"banruo5.c",
		"north" : __DIR__"fzlou",
	]));
set("objects", ([
                __DIR__"npc/xiao": 3, 
               __DIR__"npc/zhangmen": 1,
		__DIR__"obj/rack": 1,
]));
	set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
}


