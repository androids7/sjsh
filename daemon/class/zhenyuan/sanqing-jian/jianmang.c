#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
    int  myexp, yourexp,i,num,damage;
        object weapon;
     
 if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("灵幻剑芒只能在战斗中使用.\n");
   if((int)me->query_skill("sanqing-jian",1) < 100)
    return notify_fail("你的三清剑法等级还不够!!\n");
   if(me->query_skill_mapped("force")!="zhenyuan-force")
   return notify_fail("剑芒需要镇元神功的支持。\n");
   if(me->query("family/family_name")!="五庄观")
   return notify_fail("“灵幻剑芒”只有五庄观的人才可以用！\n");
   if( (int)me->query("max_force") < 800)
   return notify_fail("你的内力太弱,不能吐出剑芒!!\n");
   if( (int)me->query("force") < 400)
   return notify_fail("你的内力不够了!!\n");
   if(me->query_temp("jianmang_busy"))
     return notify_fail("糟了，剑芒没有发出!\n");
    myexp = (int)me->query("combat_exp");
    yourexp = (int)target->query("combat_exp");
   msg = HIC
"\n$N一声朗笑,手中长剑斜指向天,剑尖吐出一团尺余的银芒,似有灵性般吞缩不定!\n"
"$n正诧异间,那团剑芒却猛得暴涨,朝着$n的面门直射而来!!\n\n" NOR;
message_vision(msg, me ,target);
damage=me->query_temp("apply/damage")+me->query("force_factor");
num=0;
 for (i=1;i<=6;i++) 
 {
    if( random(myexp)>random(yourexp))
        num++;
 }   
if(num>0)         
{
        damage=damage*num;
   msg = HIR
"\n只听$n一声惨嚎,剑芒从$n的额头掠过,带出一缕血光!!\n" NOR;
message_vision(msg, me ,target);
   msg = HIW
"\n剑芒长虹经天般自天际处转得一转,又飞回$N的身边.\n" NOR;
message_vision(msg, me ,target);
 target->receive_damage("kee",damage,me);
 if (random(damage)>target->query_temp("apply/armor"))
       target->receive_wound("kee",damage-target->query_temp("apply/armor"),me);
      COMBAT_D->report_status(target,1);
   if(!target->is_busy()) target->start_busy(4+random(3));
  target->kill_ob(me);
  
//COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);


}
else {
  msg = HIY
"\n$n却识得那团剑芒的厉害,早已远远避在一边.\n" NOR;
message_vision(msg, me ,target);
   
me->start_busy(2);
}
me->add("force",-120);
me->set_temp("jianmang_busy",1);
call_out("jianmang_ok",1+random(2),me);
        return 1;
}
void jianmang_ok(object me) {
  if (!me) return;
  me->delete_temp("jianmang_busy");
}
