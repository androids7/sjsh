// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return
notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        write( HIY "你全身放松，坐下来开始运用易筋经疗伤。\n" NOR);
        message("vision",
                HIY + me->name() +
"坐下来运用易筋经疗伤，脸上一阵红一阵白，不久，吐出一口瘀血，脸色看起来好多了。\n"
NOR,
                environment(me), me);

        me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
        me->add("force", -50);

        return 1;
}


