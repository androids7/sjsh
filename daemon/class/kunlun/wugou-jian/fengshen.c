#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「天霸封神」？\n");

        if(!me->is_fighting())
                return notify_fail("「天霸封神」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

	i=(int)me->query_skill("wugou-jian",1)+(int)me->query_kar();

        if( i < 200)
                return notify_fail("你的吴钩剑法级别还不够，使用这一招会有困难！\n");

      message_vision(HIW"$N手中," + weapon->query("name") +
"划破混元无极之界限隐出「"HIR"天霸封神"NOR""HIW"」攻向$n \n "NOR,me);

	me->delete("env/brief_message");
	target->delete("env/brief_message");

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->report_status(target, 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->report_status(target, 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->report_status(target, 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->report_status(target, 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->report_status(target, 0);
        me->receive_damage("sen", 100+random(100));
        me->add("force", -500);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3+random(2));
        return 1;
}

