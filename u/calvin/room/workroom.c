// Room: /d/wiz/punish.c

inherit ROOM;
#include <ansi.h>

void create()
{
 set("short", HIM"%%%%%%%%%%%%%%%
  %%世 外 桃 源%%
  %%%%%%%%%%%%%%%"NOR);
        set("long", NOR@LONG不似晚风摄落叶 扮若又生弄英雄
***************************************************************************
***************************************************************************
*** 这是一块没有人间烦恼,没有地狱丑恶的快乐世界!这里鸟语花香,四季温和。****
***************************************************************************
***************************************************************************

LONG NOR);

        set("valid_startroom", 1);
                set("exits", 
        ([ //sizeof() == 8
                "kz" :   "/d/city/kezhan",
                "jail":  "/d/wiz/punish",
                "wiz" :  "/d/wiz/wizroom",
                "guest" :"/d/wiz/guest",
                "ll" :   "/d/lanling/兰陵城心",
        ]));
        set("objects", ([ /* sizeof() == 1 */
                "/d/ourhome/npc/bigeye" : 1,
               "/d/obj/其他/高脚椅" : 1,
                "/u/calvin/obj/table" : 1,
        ]));


        setup();

}
void init()
{   
        if (!wizardp(this_player())) 
             add_action("block_cmd","",1);      
        else
             add_action("read_book","read");
}

int block_cmd()
{
        string verb = query_verb();

        if (verb=="say") return 0; //allow say
        if (verb=="help") return 0;
        if (verb=="chat") return 0;//allow chat
        if (verb=="rumor") return 0;//allow rumor
        if (verb=="quit") return 0;
        if (verb=="look") return 0;
        return 1;
}
int valid_leave(object me, string dir)
{
        object mbox;

        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "你将信箱交回给邮差。\n");
                destruct(mbox);
        }

        return ::valid_leave(me, dir);
}

int read_book(string arg)
{
   if (!arg) return 0;
   if (arg!="death" && arg!="call" && arg!="mon" ) return 0;
   if (arg=="death") {
                if(file_size("/log/death")>0)
                this_player()->start_more( read_file("/log/death"));
        }
   if (arg=="call") {
                if(file_size("/log/static/call_player")>0)
                this_player()->start_more( read_file("/log/static/call_player"));
        }
   if (arg=="mon") {
                if(file_size("/log/monitord")>0)
                this_player()->start_more( read_file("/log/monitord"));
        }       
   write("\n");   
      return 1;
}
