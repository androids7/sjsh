
// leihuo.c 雷火必杀
// by stey
 
#include <ansi.h>
 
inherit SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
        int skill, ap, dp;
        int force_wound, kee_wound ;

	me->clean_up_enemy();
	target = me->select_opponent();

        skill = me->query_skill("zileidao",1);

	if( !(me->is_fighting() ))
                return notify_fail("「雷火必杀」只能对战斗中的对手使用。\n");
 
  if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
   return notify_fail(RED"开什么玩笑，没装备刀怎么使「雷火必杀」？\n"NOR);

	if( skill < 60)
                return notify_fail("你的「紫雷刀法」等级不够, 不能使出「雷火必杀」！\n");

	if( me->query("force") < 150 )
                return notify_fail("你的内力不够，无法运功！\n");
 
        msg = HIC "$N聚气于掌，使出一招「雷火必杀」，向$n的胸口击去。\n"NOR;

	message_vision(msg, me, target);

	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;

	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("force",-100);

                msg = HIG "$n只觉得眼前一黑，“哇”的一声喷出一口鲜血！\n"NOR;

		force_wound = 100 + random(skill)*2;
		if(force_wound > target->query("force"))
			force_wound = target->query("force");


		kee_wound = force_wound / 2;
//                if(kee_wound > target->query("kee"))
//                        kee_wound = target->query("kee");

		target->add("force", -force_wound);
		target->add("kee", -kee_wound);
	target->add("eff_kee",-kee_wound);
		target->start_busy(2+random(2));
		me->start_busy(random(3));
	}
	else
	{
		msg = HIG "只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
		if(userp(me))
			me->add("force",-100);
		me->start_busy(1+random(2));
	}
	message_vision(msg, me, target);

	return 1;
}
