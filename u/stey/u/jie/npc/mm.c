inherit NPC;
#include <ansi.h>
void create()
{
              set_name("林仙儿", ({"lin xianer", "lin","xianer"}));
             set("long",
             "武林第一大美人。\n");
             set("title", HIR"妖冶仙子"NOR);
            set("gender", "女性");
             set("age", 20);
             set("attitude", "friendly");
             set("per", 40);
             set("int", 30);
             set("chat_chance",5);
             set("chat_msg", ({
            HIM"林仙儿仰天长叹:柳哥，不世出的英雄！\n"NOR,
            }));
            setup();
             carry_object("/d/moon/obj/luoyi")->wear();
}
inherit NPC
void create()
{
              set_name(林仙儿, ({lin xianer, lin,xianer}))
             set(long,
             "武林第一大美人。\n")
             set(title, HIR妖冶仙子NOR)
            set(gender, 女性)
             set(age, 20)
             set(attitude, friendly)
             set(per, 40)
             set(int, 30)
             set(chat_chance,5)
             set(chat_msg, ({
            HIM林仙儿仰天长叹:柳哥，不世出的英雄！\nNOR,
            }))
            setup()
             carry_object(/d/moon/obj/luoyi)->wear()
}

