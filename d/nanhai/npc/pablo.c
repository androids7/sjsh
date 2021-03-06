 
// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

#include <ansi.h>

inherit NPC;

void create()
{
  set_name("杨雄", ({ "yang xiong", "yang", "laoban" }) );
  set("title", "当铺老板");
  set("gender", "男性");
  set("age", 40);
  set("combat_exp", 10000+random(1000));
  set("attitude", "heroism");

  set("str", 30);
  set("max_kee", 200);
  set("max_gin", 200);
  set("force", 200);
  set("max_force", 200);
  set("force_factor", random(10)+15);
  set_skill("unarmed", 30);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set_skill("blade", 30);

  setup();

  carry_object("/d/nanhai/obj/guazi")->wear();
}

