// huoyizhen  lost 2002

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("火翼阵只能对战斗中的对手使用。\n");
        if((int)me->query("force") < 2000 )
                return notify_fail("你的内力不够。\n");
        if((int)me->query("mana") < 2000 )
                return notify_fail("你的法力不够。\n");
        if((int) me->query_skill("wuyue-spear",1) <= 220)
                return notify_fail("你的五岳神枪还不够精纯，不能施展出火翼阵。\n");
        if((int) me->query_skill("huomoforce",1) <= 220)
                return notify_fail("你的火魔心法还不够精纯，不能施展出火翼阵。\n");
        if((int) me->query_skill("moshenbu",1) <= 220)
                return notify_fail("你的魔神步法还不够精纯，不能施展出火翼阵。\n");
        if((int) me->query_skill("pingtian-dafa",1) <= 220)
                return notify_fail("你的平天大法还不够精纯，不能施展出火翼阵。\n");

        message_vision(HIR"$N念动真言缓缓从地面升起，两条火龙向两侧游走包向$n。\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(2)+2);
        me->start_busy(3+random(1));
                me->add("force", -1000);
                me->add("mana", -1000);
        return 1;
}
void kill_him(object me, object target)
{
        string msg;
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
msg = HIR "火龙在$n身后合拢，顿时$n被笼罩在一片火海中。
火焰犹如暴风雪般从$N身上飞射出来射向$n，
$N在暴风雪般的火焰中，轻轻射出了一根"HIY"金色的火龙。" ;
msg +=  "\n金色的火龙"HIR"直射向$n的心口，全部没入。$n也倒在了地上。。。\n" NOR;

        message_vision(msg, me, target);
                target->die();
        }
        me->start_busy(5);
        return ;
}

