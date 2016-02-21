// 玩家NPC.nothing by Calvin of 2001.6

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("将臣", ({"dun's"}));
        set("title", HIR"八部天龙之天神"NOR);
        set("gender", "男性" );
        set("age", 30);
        set("per", 37);
        set("str", 240);
    set("long","左手锤右手叉龙搏是空手雷龙在胯下人挡叉人佛挡叉佛的小淫虫--周伯通。\n");

//        set("attitude", "aggressive");

       set("shen_type", 1);
       set("combat_exp", 7308249);
       set("daoxing", 8000000);
       set("max_kee", 3118);
       set("max_gin", 210);
       set("max_sen", 2030);
       set("force", 5500);
       set("max_force", 5500);
       set("force_factor", 210);
       set("max_mana", 7500);
       set("mana", 15000);
       set("mana_factor", 210);

       set_skill("dodge", 400);
       set_skill("force", 286);
       set_skill("fork", 207);
       set_skill("literate", 155);
       set_skill("makeup", 159);
       set_skill("parry", 399);
       set_skill("spells", 208);
       set_skill("unarmed", 400);
       set_skill("dragonfight", 399);
       set_skill("dragonforce", 400);
       set_skill("dragonstep", 400);
       set_skill("fengbo-cha", 399);
       set_skill("huntian-hammer", 399);
       set_skill("seashentong", 212);
        map_skill("dodge", "dragonstep");
        map_skill("force", "dragonforce");
        map_skill("fork", "fengbo-cha");
        map_skill("parry", "fengbo-cha");
        map_skill("spells", "seashentong");
        map_skill("unarmed", "dragonfight");

       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "hufa" :),
                (: perform_action, "unarmed", "sheshen" :),
                (: perform_action, "unarmed", "leidong" :),
                }) );

        set_temp("apply/armor",50);
        set_temp("apply/damage",25);
        setup();
        carry_object("/d/obj/armor/jinjia")->wear();
        carry_object("/d/city/npc/obj/pifeng")->wear();
        carry_object("/d/city/npc/obj/kui")->wear();
        carry_object("/d/wizz/calvin/longzhu/zhu3");
        carry_object("/d/city/npc/obj/shoes")->wear();
}
//void init()
//{
//        object ob;
//        ::init();
//        set("chat_chance", 10);
//        set("inquiry", (
//           "name" : "我就是鼎鼎大名的将臣,怎么连我都不知道啦？\n",
//            "here" : "这里是我最喜欢来的地方,因为这里风景不错。\n", 
//            "将臣" : "将臣就是我了,有什么事吗?\n", 
//         ]) );

//        set("chat_msg", ({
//            "将臣说道:天极之处便是人间最美丽的地方,那是一片极乐的圣地!\n",       
//            "将臣说道:要想取的真经可不是件容易的事啊!\n",       
//            "将臣说道:我将臣是一代天骄傲子,天下无人可相比拟!\n",       
//            "将臣说道:我的最爱是那位肌肤若雪,面暇绯红的小火舞仙子。\n",       
//                (: random_move :)
//        }) );
//}

