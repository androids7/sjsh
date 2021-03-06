#include <ansi.h>
inherit SKILL;
mapping *action = ({
        ([      "name":                 "群魔乱舞",
                "action":               "$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里，剑势击向$n的$l!",
                "dodge":                -40,
                "parry" :               -40,
                "damage":               60,
               "force" :               50,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "厉鬼缠身",
                "action":               "$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可思议",
                "dodge":                -80,
                "parry" :               -80,
                "damage":               100,
                "force" :               20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "百鬼夜行",
                "action":               "$N舞动$w，一招「虹日」挟著闪闪剑光刺向$n的$l",
                "dodge":                -30,
                "parry" :               -30,
                "damage":               80,
                "force" :               50,
                "damage_type":  "刺伤"
        ]),


        ([      "name":                 "饿鬼拦路",
                "action":               "$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n！",
                "dodge":                -40,
                "parry" :               -40,
                "damage":               50,
                "force" :               80,
                "damage_type":  "刺伤"
        ]),


      ([     "action":         "$N目若朗星，身如秋月，长剑斜斜刺向$n的$l！",
             "dodge":          -20,
            "parry" :          -20,
            "damage":          100,
             "force":           40,
           "damage_type":      "刺伤"

       ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够，没有办法练杀人剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}



int valid_effect(object me, object weapon, string name, int skill)
{
}

int effective_level() { return 27;}

string *parry_msg = ({
        "却见$n踏前一步，剑式斜指$N的右臂，想要使$N闪身而退。\n",
        "$n剑挟刀势，大开大阖地乱砍一通，但招招皆击在$N攻势的破绽，迫得$N不得不守！\n",
});


string *unarmed_parry_msg = ({
        "却见$n踏前一步，剑式斜指$N的右臂，想要使$N闪身而退。\n",
        "$n剑挟刀势，大开大阖地乱砍一通，但招招皆击在$N攻势的破绽，迫得$N不得不守！\n",
});

string query_parry_msg(object weapon)
{
       if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return 0;
}


int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return -10;
}

string perform_action_file(string func)
{
return CLASS_D("swordman") + "/doom-sword/" + func;
}

