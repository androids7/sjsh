
// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{

	if ((!target)||target->query("id")==me->query("id"))
		return notify_fail("你要用真气为谁疗伤？\n");
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

        if( (int)me->query_skill("emeiforce",1) < 20 )
		return notify_fail("你的内力修为不够。\n");

        if( (int)me->query("max_force") < 500 )
		return notify_fail("你的内力修为不够。\n");

        if( (int)me->query("force") < 50)
		return notify_fail("你的真气不够。\n");

        if( (int)target->query("kee") < (int)target->query("max_kee") / 5 )
		return notify_fail( target->name() +
                        "已经受伤过重，经受不起你的真气震荡！\n");

	message_vision(
		HIY "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"
		"过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
		me, target );

        target->receive_curing("kee", 10 + (int)me->query_skill("force")/2 );
        target->add("kee", 10 + (int)me->query_skill("force")/3 );
        target->receive_curing("sen", 10 + (int)me->query_skill("force")/2 );
        target->add("sen", 10 + (int)me->query_skill("force")/3 );
        if( (int)target->query("kee") > (int)target->query("eff_kee") ) target->set("kee", (int)target->query("eff_kee"));
        if( (int)target->query("sen") > (int)target->query("eff_sen") ) target->set("sen", (int)target->query("eff_sen"));

        me->add("force", -50);
	return 1;
}

