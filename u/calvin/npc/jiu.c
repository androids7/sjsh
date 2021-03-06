// 九重天神 calvin,2001.5

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("九重天神", ({"jiu tianshen", "jiu", "jiuchong", "tianshen"}));
        set("title", "天宫守卫");
        set("gender", "男性" );
        set("age", 45);
        set("per", 30);
        set("str", 30);
set("long","这便是九重天界的守护神了,他手持一只九天战爪,那样貌煞是威风!\n");

        set("attitude", "aggressive");
       set("class", "sanjie");
       set("shen_type", 1);
       set("max_kee", 5500);
       set("max_gin", 100);
       set("max_sen", 5500);
       set("force", 5500);
       set("max_force", 5500);
       set("force_factor", 285);
       set("max_mana", 5500);
       set("mana", 5500);
       set("mana_factor", 285);
       set("combat_exp", 5000000);
       set("daoxing", 45000000);

        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("spells", 350);  
        set_skill("tianmogong", 350);
        set_skill("literate", 350);
        set_skill("blade", 350);  
        set_skill("zileidao", 350);
        set_skill("zhaoyangbu", 350);
        set_skill("force", 350);   
        set_skill("huntianforce", 350);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("blade", "zileidao");
        map_skill("parry", "zileidao");
        map_skill("dodge", "zhaoyangbu");

        set("chat_msg_combat", ({
        (: perform_action, "blade", "tulong" :),
        }) );

        setup();
        carry_object("/d/sanjie/obj/jinjia")->wear();
        carry_object("/d/sanjie/obj/leidao")->wield();
        carry_object("/d/calvin/armor/zhua")->wield();
}

void init()
{
object who=this_player();
add_action("do_error", "mark");
add_action("do_error", "fight");
add_action("do_error", "fly");
add_action("do_error", "perform");
}

int do_error(string arg)
{
object who = this_player();
message_vision("不要捣蛋哦,小心被天界引起重视！\n",who);
return 1;
}
