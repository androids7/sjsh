// hell_guard.c

#include <ansi.h>

inherit NPC;

void create()
{
    	object ob1, ob2;
	
        set_name("天降女神", ({"nushen"}));
        set("long", "这是一位来自天国的女神，体态婀娜。\n");
        set("attitude", "friendly");
        set("gender", "女性");

        set("max_gin", 800);
        set("per", 30);
        set("max_kee", 800);
        set("max_sen", 800);

        set("max_atman", 180);
        set("atman", 180);
        set("max_mana", 180);
        set("mana", 180);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 5);
        set("str", 40);
        set("cor", 30);
        set("cps", 25);

        set("combat_exp", 180000);
	set("daoxing", 180000);


        set_skill("whip", 180);
        set_skill("parry", 180);
        set_skill("dodge", 180);

        setup();

        ob1=carry_object("/d/ourhome/obj/ironarmor");
	ob1->wear();
	ob1->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
        ob2=carry_object("/d/obj/weapon/whip/tielian");
	ob2->wield();
	ob2->set("no_sell", "掌柜的瞟了一眼道：这东西一看就是劣等品，不要！不要！\n");
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",
                HIM + name() +
"说道：本神奉法主召唤，现在已经完成护法任务，就此告辞！\n\n"
                + name() +"的身形越来越淡，化做一股清烟漂散了．\n" NOR,
environment(),
                this_object() );
        destruct(this_object());
}

void invocation(object who)
{
        int i;
        object *enemy;

        message("vision",
                HIM
"一声天籁之音从天上传了下来，随着音乐，一个婀娜多姿的女子走了出来。\n\n"
                + name() + "说道：本神奉法主召唤，特来护法！\n" NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) )
enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
}

