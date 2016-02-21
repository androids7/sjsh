inherit ROOM;;
#include <ansi.h>
void create ()
{
set ("short",HIG"茶室--谈心室");
set ("long", @LONG

    烦闷的生活，人的心情也跟着时代的脚步日渐浮躁起来，唯有这间
茶室，百年立于风雨中，依旧清新如昔。
    茶室堂中挂着一块匾，好好的写着：君子之交淡如水。
    女主人喜欢在这儿招待自己的朋友，一杯清茶，徐徐热烟，还有从
香坊里飘来“夜水心”的异香，使得整间茶室宁静而朴素。在这里，人
心能够很容易静下来。
    茶室虽简陋，但唯物德馨。真正的品茶之人将此地视为“心灵的静
化区”。

LONG);;;
set("exits",([
"west" : __DIR__"loveroom",
"north" : __DIR__"workroom",
]));
set("objects",([
"/u/rainy/npc/lan":1,
"/u/rainy/obj/tea":1]));
setup();
}
