// created 17-06-2001 ����Ʈ(piao)


inherit ROOM;
#include <room.h>
void create()
{
	set("short", "����");
	set("long", @LONG
�����ﳱʪ�����������Ӳ���ʮ��խС����ֻ��һ����һ
����һ�ʣ����Ե��ı���Ȼ���ն���į��Ҳ�ĵ���һյ�µƸ�
��ư��������ϵĻ���δ���������ϻ�����������
LONG
               );
	 set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/yegucheng": 1, 
__DIR__"obj/blood": 1, 

]));
  set("exits", ([ /* sizeof() == 4 */
 "south" : __DIR__"stone2",


]));
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
]));

create_door("south", "խ��", "north", DOOR_CLOSED);
  setup();
}