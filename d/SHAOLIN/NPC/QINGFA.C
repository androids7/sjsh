// qingfa.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_for_join();

void create()
{
        set_name("清法比丘", ({
		"qingfa biqiu",
		"qingfa",
		"biqiu",
	}));

        set("gender", "男性");
        set("title", HIB"少林寺剃度僧"NOR);
        set("long",
		"他是一位体格强健的壮年僧人，他生得虎背熊腰，全身似乎蕴含\n"
		"着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺。\n"
	);
	create_family("少林寺", 4, "弟子");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "bonze");

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);
	set("cps", 30);
	set("cor", 20);

        set("atman", 2000);
        set("max_atman", 2000);

        set("force", 1200);
        set("max_force", 1200);
        set("force_factor", 50);

        set("mana", 1200);
        set("max_mana", 1200);

        set("combat_exp", 800000);
        set("daoxing", 850000);

	set("inquiry", ([
		"剃度" : (: ask_for_join :),
		"出家" : (: ask_for_join :),
		]) );

        set_skill("sword", 80);
        set_skill("unarmed", 80);
        set_skill("force", 100);
        set_skill("dodge", 80);
        set_skill("literate", 180);
        set_skill("parry", 80);
        set_skill("spells", 100);
        set_skill("zui-gun", 80);
        set_skill("shaolin-shenfa", 80);
        set_skill("banruo-zhang", 80);
        set_skill("jingang-leg", 80);
        set_skill("stick", 80);
        set_skill("yijinjing", 100);
        set_skill("chanzong", 100);

        set_skill("shaolin-sword", 80);
        map_skill("force", "yijinjing");
        map_skill("sword", "shaolin-sword");
        map_skill("spells", "chanzong");
        map_skill("unarmed", "banruo-zhang");
        map_skill("stick", "zui-gun");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "jingang-leg");

	setup();

        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}

void init()
{
	add_action("do_kneel", "kneel");
}


string ask_for_join()
{
	object me;

	me = this_player();

	if (me->query("married"))
		return "阿弥陀佛！施主有了家庭拖累，想必难以潜心向佛。\n";
	if( (string)me->query("bonze/class")=="bonze" )
                return "阿弥陀佛！你我同是出家人，何故跟老衲开这等玩笑？\n";
	if( (string)me->query("gender") != "男性" )
                return "阿弥陀佛！善哉！善哉！女施主若真心皈依我佛，可去南海普陀山受戒。\n";
	if( me->query("bonze/justonetime"))
		return "施主既已还俗，又何苦再次出家？\n";
	me->set_temp("pending/join_bonze", 1);
	return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n";
}

int do_kneel()
{
        string *prename =
	 ({ "虚", "空", "明", "圆", "净", "悟", "法" });
	string name, new_name;

	if( !this_player()->query_temp("pending/join_bonze") ) return 0;
	message_vision(	HIC "$N双手合十，恭恭敬敬地跪了下来。\n\n" + 
			"$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n" NOR,
		this_player(), this_object() );
        name = this_player()->query("name");
	new_name = prename[random(sizeof(prename))] + name[0..1];
	command("say 从今以後你的法名叫做" + new_name + "。");
	command("smile");
	this_player()->delete_temp("pending/join_bonze");
	this_player()->set("name", new_name);
	this_player()->set("bonze/class", "bonze");
	this_player()->set("bonze/justonetime", 1);
	this_player()->set("bonze/old_name", name);
        this_player()->set("class", "bonze");
	this_player()->save();
	return 1;
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "男性" )
	{
		command ("say 阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。");
		return;
	}

	if( (string)ob->query("class")!="bonze" )
	{
		command ("say 阿弥陀佛！贫僧就收下你做『俗家弟子』了。");
	}
	command("say 阿弥陀佛，善哉！善哉！");
	command("recruit " + ob->query("id"));
        ob->set("title", HIB"嵩山少林寺入门弟子"NOR);
         ob->set("class", "bonze");
}

