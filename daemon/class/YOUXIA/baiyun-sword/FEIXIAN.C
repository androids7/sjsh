// feixian.c Ҷ�ųǵľ��� ����Ʈ(piao)
// ������� by piao 2001-9-11
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void feixian_ok(object); 
int perform(object me, object target)
{
        string msg;
              string str;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("��"HIW"�������"NOR"��ֻ����ս����ʹ�ã�\n");

	weapon = me->query_temp("weapon");
	if (!weapon) return notify_fail("�������ʹ�ñ���ʱ����ʹ��"HIW"�������"NOR"����\n");
        if(me->query("family/family_name") != "��������" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á�"HIW"�������"NOR"��?\n");
	 if((int)me->query("force") < 1000 )
		  return notify_fail("����������㣡\n");
        if((int)me->query("max_force") < 1500 )
                return notify_fail("�������������\n");
        if((int)me->query("sen") < 850 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if( me->query_skill("piaoxiang",1) < 100 )
                return notify_fail("���Ѫ��Ʈ�㼶�𲻹�ʹ�á�"HIW"�������"NOR"��\n");
        if( me->query_skill("dodge",1) < 100 )
                return notify_fail("��Ļ����Ṧ���𲻹�ʹ�á�"HIW"�������"NOR"��\n");
          if( me->query_skill("baiyun-sword",1) < 100 )
                return notify_fail("��İ��ƽ������𲻹�ʹ�á�"HIW"�������"NOR"��\n");
        if( me->query_skill("sword",1) < 100 )
                return notify_fail("��Ļ����������𲻹�ʹ�á�"HIW"�������"NOR"��\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("��"HIW"�������"NOR"����Ҫ�л�����������ͣ�\n");
	if ( (string) me->query_skill_mapped("sword") != "baiyun-sword")
        return notify_fail("��"HIW"�������"NOR"����Ҫ�а��ƽ�������ͣ�\n");
        if(me->query_temp("no_feixian"))  //�ڴ˴����ñ�־λ ;
        return notify_fail("���ʹ�ù���"HIW"�������"NOR"��������ЪһЪ�ɣ�"); ;

        extra = me->query_skill("baiyun-sword",1) / 35;
        extra += me->query_skill("sword",1) / 35;
        me->add_temp("apply/attack", extra*2);    
        me->add_temp("apply/damage", extra*2);
	weapon = me->query_temp("weapon");
message_vision(HIC"\n$N��̤"HIW"��"HIR"Ѫ��Ʈ��"HIW"��"HIC"������ͬʱʹ��"HIW"��"HIG"���ƽ���"HIW"��"HIC"�еľ��裭��"HIW"��"HIB"�������"HIW"��!\n
"HIC"            $N���е�"NOR""+ weapon->name() +""HIC"����һ�����磬�����Ļ���$n��\n" NOR,me,target);
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg = HIY "\nֻ��$N���е�"NOR""+ weapon->name() +""HIY"����һ����˲����ʧ��������\n" NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/3;i++)
	{
	msg = HIY "$N����ͻת�������طɣ�\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       }
        if( (int)me->query_skill("baiyun-sword", 1) > 149 )
        {
         message_vision(HIY"\n$N����ͻת�������طɣ�\n"NOR,me,target);
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 if (target->query("eff_kee")<0 || !living(target))  
{str=""+target->name()+""HIM""+"��"+""HIW""+me->name()+""HIM""+"��Ҷ�³ǵľ�ѧ��"HIW"�������"HIM"��ɱ���ˣ���˵��ʬ�嶼û��ʣ�¡�"NOR"";
        message("channel:rumor",HIM"��"HIW"��Ѩ����"HIM"��ĳ�ˣ�"+str+"\n"NOR,users());
       }
}
//-----------------------------------------------------------------------------------
        if( (int)me->query_skill("baiyun-sword", 1) > 179 )
        {
message_vision(HIC"                            ������������\n"NOR,me,target);
message_vision(HIY"$N������ת�������طɣ�    "HIC"�� "HIY"��  ��"HIC" ��\n"NOR,me,target);
message_vision(HIC"                            ������������\n"NOR,me,target);
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       }
//-----------------------------------------------------------------------------------
        if( (int)me->query_skill("baiyun-sword", 1) > 199 )
        {
message_vision(HIC"                            ������������\n"NOR,me,target);
message_vision(HIY"$N������ת�������طɣ�    "HIC"�� "HIY"��  ��"HIC" ��\n"NOR,me,target);
message_vision(HIC"                            ������������\n"NOR,me,target);
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       }
//-----------------------------------------------------------------------------------
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
        me->set_temp("no_feixian",1); ;
        call_out("feixian_ok",20+random(10),me); ;
        me->start_busy(3+random(1));;
	return 1;
}
void feixian_ok(object me) 
{ if (!me) return; 
      me->delete_temp("no_feixian"); 
}
