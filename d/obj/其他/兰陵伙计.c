// huoji.c

inherit NPC;

void create()
{
  set_name("伙计", ({"huoji"}));
  set("long","一个俊俏的男子。\n");
  set("gender", "男性");
  set("age", 18);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("combat_exp",600);
  setup();
  carry_object("/d/obj/其他/菩提衫")->wear();
}
