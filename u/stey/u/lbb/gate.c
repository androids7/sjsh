inherit ROOM;

void create ()
{
  set ("short", "大门");
  set ("long", @LONG

走着走着，不知不觉来到一座大门前，这座大门很高，两旁静悄悄的，
你四处打量了一下，确定冷冰冰就是从这里进去的，不容多想，抬脚就往里面走，
刚到门口，忽然看见门楣上有幅对联

        站 着 进 来           躺 着 出 去

正在你一楞间，门后闪出两个全副武装的哨兵来......
LONG);

    set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"workroom.c",
  "west" : __DIR__"workroom.c",
  "south" : __DIR__"workroom.c",
  "north" : __DIR__"huayuan.c",
]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/guard" : 2,
        ]));

        setup();
}
