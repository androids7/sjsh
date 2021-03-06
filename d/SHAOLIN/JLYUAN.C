// Room: /d/shaolin/jlyuan.c
// Date: YZC 96/01/19


#include <ansi.h>
#include <login.h>

inherit ROOM;

void create()
{
	set("short", "戒律院");
	set("long", @LONG
整个大殿门户紧闭，密不透风。即便是在白昼，也犹如黑
夜一般，每隔几步的墙上，点燃着几枝牛油巨烛。下方摆着一
排排烙铁、水牛皮鞭、穿孔竹板及狼牙棒等刑具。四周站满了
手持兵刃的执法僧兵。他们正用冷酷的眼神打量着你，令你不
禁浑身哆嗦起来。
LONG );
	set("no_fight", "1");
	set("exits", ([
		"southdown" : __DIR__"guangchang3",
	]));
	set("valid_startroom",1);
	set("objects",([
                __DIR__"npc/xuantong" : 1,
                __DIR__"npc/sengbing1" : 3,
			]));
//	set("no_clean_up", 0);
	setup();
}

void init()
{	
	mapping fam;
	object ob;

	if( interactive(ob = this_player()) )
	{
		if( mapp(fam = ob->query("family")) 
                &&  fam["family_name"] == "少林寺" )
			return;
		else 
		{
                        message_vision(HIY "$N一进戒律院，...只听几声大喝，如同炸雷般在大殿里回响。\n"
  "$N不禁浑身发抖，再也站立不住，腿一软，扑通一声跪了下来。\n\n" NOR, ob);

                        ob->set("startroom", "/d/shaolin/jlyuan");

			remove_call_out("processing");
			call_out("processing", 3, ob);
		}
	}
}

void processing(object ob)
{
	mapping fam;

	write(HIW "\n你定了定神，抬头细看，只见数十名持刀僧人将你团团围起来，\n"
		"一片雪亮的刀光逼得你眼都睁不开。正前方的高台上放着一把\n"
		"太师椅，居中高坐着位白须白眉的老僧，脸色铁青，目射精光，\n"
		"狠狠地瞪着你。\n\n\n" NOR);

        if ( (fam = ob->query("class")) != "bonze" )
      message_vision(HIY "玄痛一声大喝：尔等大胆狂徒，擅闯本寺戒律院，意在不轨，该当何罪！\n"
        "堂堂少林寺戒律院，岂能容你等宵小如此胡作非为！执法僧兵何在！\n\n" NOR, ob);
	message_vision(HIR "僧兵大声应道：弟子在！\n" NOR, ob);
        message_vision(HIR "僧兵们一涌而上，乱棒齐下，$N被打了出去......\n\n\n" NOR, ob);
                        ob->move("/d/shaolin/guangchang3");
                        ob->add("combat_exp",40);
                        ob->start_busy(5);
                        ob->add("kee",-100);
                        return;

        if ( (fam = ob->query("class")) == "bonze" )
         message_vision(HIY "玄痛盯着$N看了半饷，说道：$N，你惩恶扬善，锄暴安良，当得表彰，"
        "贫僧这就带你去见达摩祖师！\n\n" NOR, ob);
        message_vision(HIR "玄痛带着$N穿过竹林来到达摩洞......\n\n\n" NOR, ob);

                        ob->set("startroom", START_ROOM);
                        ob->add("combat_exp",50);
                        ob->add("kee",-20);
                        ob->start_busy(2);
			return;

	

}


int valid_leave(object me, string dir)
{
	mapping fam;

	if ( userp(me) && dir == "southdown" )
	{
		if( mapp(fam = me->query("family")) 
                &&  fam["family_name"] == "少林寺" )
			return ::valid_leave(me, dir);
		else
			return notify_fail("玄痛说道: 大胆，你还敢逃跑！执法僧兵何在！\n");
	}

}
