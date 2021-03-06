inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIY"斋藤一"NOR, ({"master zhaiteng", "zhaiteng","master","yi"}));
       set("long",
"曾经的新撰组三番队队长，幕末后投靠维新政府，以手中的剑，
继续坚持着恶·即·斩的信念。\n");
       set("title", HIC"壬生狼"NOR);
       set("gender", "男性");
       set("age", 35);
       set("class", "swordman");
       set("attitude", "friendly");
       set("per", 30);
	set("int", 30);
       set("max_kee", 3000);
       set("max_sen", 3000);
       set("force", 6000);
       set("max_force", 3000);
       set("force_factor", 150);
       set("max_mana", 3000);
       set("mana", 6000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
       set("daoxing", 3000000);

       set_skill("literate", 200);
       set_skill("unarmed", 200);
       set_skill("dodge", 200);
       set_skill("force", 200);
       set_skill("parry", 200);
       set_skill("sword", 240);
       set_skill("spells", 200);
   set_skill("renshu", 200);
   set_skill("guixi-force", 200);
   set_skill("lixin-sword", 240);
   set_skill("fengyu-piaoxiang", 200);
   map_skill("spells", "renshu");
   map_skill("force", "guixi-force");
   map_skill("sword", "lixin-sword");
   map_skill("parry", "lixin-sword");
   map_skill("dodge", "fengyu-piaoxiang");

create_family("剑客联盟", 2, "弟子");
setup();

       carry_object("/d/obj/cloth/zhanpao")->wear();
	carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
 if ( (string)ob->query("family/family_name")=="剑客联盟") {
 if (((int)ob->query("swordman/dead_perform"))) {
   command("say " + RANK_D->query_respect(ob) +
"你不适合在我的门下学习。\n");
   return;
   }

 if (((int)ob->query("combat_exp") < 800000 )) {
   command("say " + RANK_D->query_respect(ob) +
"还是先打好基础再来。\n");
   return;
   }
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把恶·即·斩的信念坚持下去。\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", "剑客警官");
	   ob->set("class", "swordman");
   return;
   }
}