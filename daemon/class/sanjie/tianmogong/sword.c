// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

// arrow.c
#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
        int success_adj, damage_adj;
        success_adj = 100;
        damage_adj = 100;

        if((int)me->query_skill("spells") < 20 )
                return notify_fail("��ķ��������ߣ�\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
         return notify_fail("��Ҫ��˭ʩչ��ħ�ǻꣿ\n");

        if((int)me->query("mana") < 100+(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 20 )
                return notify_fail("����ħ������ʩ�����ⷴ�ɣ�\n");

        me->add("mana", -25-(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 40 ) {
        write("�����񲻼ᣬħ���޷����Σ�\n");
                return 1;
        }

        SPELL_D->attacking_cast(
        me,
        //attacker
        target,
        //target
        success_adj,
        //success adjustment
        damage_adj,
        //damage adjustment
        "both",
        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
        HIB "$N�����૵��������ģ�����һ���Ϲ⽥�������鶯�ޱȣ�\nֻ��$N���һ������ħ�ǻ꣡�����Ϲ⻯Ϊһ���⽣��һ���伲����$n��\n" NOR,
        //initial message
        HIR "������͡���һ�����Ϲ��$n����͸��������ϳ��������߲ʹ������������˻�����ɢ��$N�����ڣ�\n" NOR,
        //success message
        HIB "$n������ħ��������͡���һ�����Ϲ��$n����͸�������������Ϣ��������£�\n" NOR,
        //fail message
        HIB "����$n���ļᶨ��������ǿ���Ϲ�һ�٣����͡���һ������$N��\n" NOR,
        //backfire initial message
        HIR "����Ϲ⻯Ϊ��ǧϸ��������$nȫ������ʱѪ���ɽ���\n" NOR
        //backfire hit message. note here $N and $n!!!
        );
        me->start_busy(1+random(2));
        return 3+random(5);
}
