#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
string msg;
int extra;
object weapon;
if (extra = me->query_skill("xuanhu-blade",1)<100) return notify_fail("你的你的玄狐刀法还不够纯熟！\n");
if( !target ) target = offensive_target(me);
if( !target
||      !target->is_character()
||      !me->is_fighting(target) )
return notify_fail("［短歌长梦］只能对战斗中的对手使用。\n");
weapon = me->query_temp("weapon");
message_vision(HIY  "\n$N使出玄狐刀法，第一招----灵狐出洞，手中的"+ weapon->name()+  "闪电般向$n攻出第一刀！" NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
message_vision(HIC"\n$N第二招——灵狐觅食！"NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
message_vision(HIC"\n$N第三招——灵狐翻身！"NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
me->start_busy(3);
return 1;
}
