// 地狱怒神 by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int do_drop(object, object);

void create()
{
  set_name(HIY"地狱怒神"NOR, ({ "diyu nushen", "diyu", "nushen","shen" }));
  set("title", HIC"三重门神之"NOR);
  create_family("陷空山无底洞", 1, "祖师");
  set("class", "xian");
  set("long", "一位高深莫测的神者。\n");
  set("gender", "男性");
  set("age", 3000);
  set("attitude", "heroism");
  set("rank_info/respect", "无敌魔神");
  set("rank_info/rude", "无敌魔神");
  set("per", 15);
  set("str", 30);
  set("cor", 30);
  set("con", 20);
  set("int", 40);
  set("spi", 40);
  set("cps", 40);
  set("kar", 40);
  set("max_kee", 2400);
  set("max_gin", 2400);
  set("max_sen", 2400);
  set("force", 3000000);
  set("max_force", 2400);
  set("force_factor", 1000);
       set("max_mana", 3000);
       set("mana", 3000000);
  set("mana_factor", 1000);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);

  set_skill("spells", 350);
  set_skill("dao", 350);
  set_skill("unarmed", 350);
  set_skill("yinfeng-zhua", 350);
  set_skill("dodge", 350);
  set_skill("lingfu-steps", 350);
  set_skill("parry", 350);
  set_skill("force", 350);
  set_skill("yaofa", 350);
  set_skill("huntian-qigong", 350);
  set_skill("blade", 350);
  set_skill("wuhu-blade", 350);
  set_skill("sword", 350);
  set_skill("qixiu-jian", 350);
  map_skill("spells", "dao");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("blade", "wuhu-blade");
  map_skill("parry", "huoyun-qiang");
  map_skill("sword", "qixiu-jian");
  map_skill("dodge", "lingfu-steps");
  map_skill("force", "huntian-qigong");
  set("inquiry", ([
        "name": "我乃地狱守护神是也。",
        "here": "这里是地狱之门。",
        ]));

  setup();
  carry_object("/d/obj/cloth/taijicloth")->wear();
  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

void attempt_apprentice(object ob)
{
  if ((string)ob->query("family/family_name")=="陷空山无底洞") {
    if(ob->query("combat_exp") > 1000000 && ob->query("daoxing") > 1000000) {
                command("say 请好生学习,免得我...哼~~~");
                command("say "+RANK_D->query_respect(ob)+"既然有心向善，就收下你吧。");
                command("recruit "+ob->query("id"));
        }
        else {
                command("say "+RANK_D->query_respect(ob)+"是无底洞的弟子，拜我不大合适吧！");
                command("say "+RANK_D->query_respect(ob)+"若愿意学,我到可以点拨一二。");
        }
  }
  else {
        command("say 我不认识你,请你离开这。");
        command("nip");
  }
}

int prevent_learn(object me, string skill)
{
  int myyaofa=me->query_skill("yaofa",1);

  if (skill == "dao") {
        if(myyaofa!=0) {
                command("sigh");
                command("say "+RANK_D->query_respect(me)+"妖气太重，不能学道家仙法。");
                return 1;
        }
  }
  return 0;
}
