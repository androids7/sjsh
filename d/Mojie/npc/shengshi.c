// worker.c

inherit NPC;
#include <ansi.h>
string ask_go();

void create()
{
        set_name("黑莲圣使", ({"sheng shi","shi"}));
        set("gender", "男性" );
        create_family("魔界", 3, "弟子");
        set("title","魔界接引");
        set("age", 30);
        set("long", "魔界接引黑莲圣使。\n");
        set("combat_exp", 300000);
        set("daoxing", 300000);
        set("max_mana", 1000);
        set("max_force", 1000);
        set_skill("dodge",100);
        set_skill("moshenbu",100);
        set_skill("shifo-zhi",100);
        set_skill("unarmed",100);
        map_skill("dodge","moshenbu");              
        map_skill("unarmed","shifo-zhi");              
        set("attitude", "peaceful");
        set("inquiry", ([
                "魔界" : (: ask_go :),
                "mojie" : (: ask_go :),
        ]) );
        setup();
}

string ask_go()
{
        object who,me,room;
        
        who = this_player();
        me = this_object();
        write("黑莲圣使对你说道：本圣使这就送你去！\n");
        write("黑莲圣使轻声念了几句咒语，天下飞下一朵巨大的黑莲，你坐了上去.......\n");
        if(!( room = find_object("/d/mojie/chang")) )
            room = load_object("/d/mojie/chang");
        if(objectp(room))
            who->move(room);
        return "\n黑莲圣使轻声念了几句咒语，天下飞下一朵巨大的黑莲，一个人坐了上去.......\n\n";
}
