// yan.c 毒烟
#include <ansi.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
	string msg;
	int success, ap, dp, ap2, ap3, dp2, dp3, damage;
	
	if( !target ) target = offensive_target(me);

	if((int)me->query_skill("spells") < 100 || (int)me->query_skill("pingtian-dafa",1) < 60)
		return notify_fail("你还没学会毒烟。。。\n");

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你想对谁喷毒烟？\n");  

	if( target->is_busy() )
		return notify_fail(target->name()+"已经够忙了。\n");

	if(target->query_temp("no_move"))
		return notify_fail(target->query("name")+"已经动弹不得了！\n");
	if((int)me->query("mana") < 200 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("你无法集中精力！\n");

	me->add("mana", -80);
	me->receive_damage("sen", 20);

	msg = RED
"$N一捏鼻子，咬破舌尖，张口一喷，一团暗红色的磷磷毒烟直朝$n喷去！\n\n" 
NOR;

	success = 1;
	ap = me->query_skill("spells");
	ap = (ap/12) * ap * ap;
	ap += (int)me->query("daoxing");
	dp = target->query("daoxing");
	ap2 = (int)me->query_cor();
	dp2 = (int)target->query_cor();
	ap3 = (int)me->query("mana");
	dp3 = (int)target->query("mana");
	if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2500*dp2+200*dp3) ) success = 0;
	if(success == 1){
		msg +=  WHT "$n正想抢攻，不料一股毒烟袭来，顿时手忙脚乱。\n" NOR;
		
		if( living(target) ) target->kill_ob(me);
		target->start_busy(2+random(2));
		
	}
	
		
	message_vision(msg, me, target);

	return 1;
}



