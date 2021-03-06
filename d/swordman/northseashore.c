inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_zuo(string arg);
void reset();


void create ()
{
  set ("short", "北海之滨");
  set ("long", @LONG

这里是北海海岸。西面茫茫大海望不到边际。海面上波涛汹涌，
也许这里便是路的尽头，面前的大海对一个凡人来说是不可逾
越的。离岸不远处漂着一艘木船(chuan)。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "chuan" : "一艘木船，在岸边游来游去。你不禁想坐(zuo)上去试一试。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : "/d/changan/eastseashore",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
    add_action("do_zuo", "zuo");
    add_action("do_zuo", "sit");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"chuan")) )
            room = load_object(__DIR__"chuan");
        if( room = find_object(__DIR__"chuan") ) {
            if((int)room->query("zuo_trigger")==0 ) {
                room->set("zuo_trigger", 1);
                set("exits/enter", __DIR__"chuan");
                room->set("exits/out", __FILE__);
                message("vision", "一艘木船从海上漂了过来。\n", this_object() );
                message("vision", "木船缓缓的靠岸了。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "木船正驶向岸边，看样子还得耐心地等等。\n",this_object() );
        }
        else
            message("vision", "ERROR: chuan not found\n", this_object() );
    }
    else 
        message("vision", "木船已经靠岸了，随时都可上去。\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "一个浪头打来，木船向海上漂去。\n",
        this_object() );

    if( room = find_object(__DIR__"chuan") )
    {
        room->delete("exits/out");
        message("vision", "周围是白茫茫的一片汪洋，已经看不到任何陆地的迹象了...\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"chuan") )
    {
        room->set("exits/out", __DIR__"haian");
        message("vision", "木船一震，搁浅了。显然是到陆地了，赶紧上去吧。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"chuan") ) {
        room->delete("exits/out");
        message("vision","一个浪头打来，木船向海上漂去。\n", room);
room->set("zuo_trigger", 0);
    }
}

int do_zuo(string arg)
{
    string dir;

    if( (arg=="chuan") || (arg=="木船")){ 
        message_vision("$N试着想坐上木船。\n", this_player());
        check_trigger();
        return 1;
    }
    else return notify_fail("你要坐上什么？\n");
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"chuan") )
        room->delete("zuo_trigger"); 
}
