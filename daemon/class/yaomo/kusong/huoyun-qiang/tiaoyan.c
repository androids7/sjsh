// tiaoyan.c 夺命三枪之「挑眼式」
// Modified by stey 2001

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target
    ||      !target->is_character()
    ||      !me->is_fighting(target) )
      return notify_fail("「挑眼式」只能在战斗中使用。\n");

    if( target->is_busy() )
   return notify_fail(target->name() + "正象只无头苍蝇，快放胆攻击吧。\n");
    msg = HIG "$N使出夺命三枪之「挑眼式」，枪尖疾挑$n双眼。\n";

    me->start_busy(random(1));
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4
 ) {
    msg += "结果$p只觉得眼前一黑，双眼一阵剧痛，接着什么也看不见了。\n" NOR;
 target->start_busy( (int)me->query_skill("huoyun-qiang") / 20 + 3);
 target->add("eff_kee",-((int)me->query_skill("huoyun-qiang")/5));
 target->add("max_kee",-((int)me->query_skill("huoyun-qiang")/5));
 target->add("kee",-((int)me->query_skill("huoyun-qiang")/5));
    } else {
   msg += "可是$p看破了$P的企图，并急忙躲开了。\n" NOR;
    }
    message_vision(msg, me, target);

    return 1;
}

