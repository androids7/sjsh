
inherit SKILL;
#include <ansi.h>;


mapping *action = ({
        ([      "name":                 "����Ȱ��������",
                "action":
"$N�������ˣ�һ��"+BLINK""HIB"������Ȱ�������ʡ�"NOR"��$N����$w���ᣬ��������$n��$l",  
                "dodge":                5,
     "parry":   -10,
                "damage":               45,
                "damage_type":  "����"
        ]),
        ([      "name":                 "�����������ɲ�",
                "action":
"$N���쳤Ц����Ҳ������һ��"+BLINK""HIB"�������������ɲ���"NOR"�����ƻ��أ��ұ�Ю���͵�ɨ��$n������",


                "dodge":                0,
     "parry":     0,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "ǧ������������",
                "action":
"$Nһ������������$w��ָ���أ�һʽ"+BLINK""HIB"��ǧ�����������ѡ�"NOR"��$n��$l��ȥ",
                "dodge":                10,
     "parry":   -20,
                "damage":               45,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��������������",
                "action":
"$Nһ���޺ȣ���һ��"+BLINK""HIB"������������������"NOR"��$N����$w�����˻��˸���Ȧ������$n��$l",
                "dodge":               10,
     "parry":   -15,
                "damage":               35,
                "damage_type":  "����"
        ]),
        ([      "name":                 "��������������",
                "action":
"$Nʹ��"+BLINK""HIB"������������������"NOR"�����й������ţ�����������$n,���$n��æ���ң��мܲ���",
                "dodge":                -5,
     "parry":     -5,
                "damage":               40,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "�ߵ���ɽ�����",
                "action":
"$N����$wת����糵һ�㣬һ��"+BLINK""HIB"���ߵ���ɽ����ء�"NOR"������֧�أ�һ��һ���������$n��$l",
                "dodge":                5,
     "parry":   -10,
                "damage":               50,
                "damage_type":  "����"
        ]),   
        ([      "name":                 "�����ױ�����¿",
                "action":
"$NŤ��������$w�ӿ�����,һ��"+BLINK""HIB"�������ױ�����¿��"NOR"�ѳ��֣�$w����$n���ؿ�",
                "dodge":                0,
                 "parry":   -20,
                "damage":               55,
                "damage_type":  "����"
        ]),
   ([   "name":        "���������ǧ��",
     "action":   "$N������$wӭ��һ�ӣ�"+BLINK""HIB"�����������ǧ����"NOR"���ڿն�����ɽ��Ӱ������ѹ��$n",
     "parry":   -40,
     "dodge":   -70,
     "damage":   200,
     "damage_type":  "����"
   ]),
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취������������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("���������һ�����Ӳ���������������\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ����������\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ������������\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string func)
{
return CLASS_D("shaolin") + "/zui-gun/" + func;
}

