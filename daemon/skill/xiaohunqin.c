#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N微微弹奏起手中的$w，一曲"+BLINK""+HIW"「伫倚危楼风细细」"NOR"，漫天琴声夹着内力如一风一般卷向$n，
$n"+HIR"被琴声中的内力一震，顿时气血翻涌，感到天旋地转，显然受了很重的内伤"NOR"",
                "dodge":                20,
      		  "force" :		180,
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N黯然一笑，$w将"+BLINK""+HIW"「草色烟光残照里」"NOR"弹奏的出神入圣，琴声向残照般洒向$n，
$n"+HIR"被琴声中的内力一震，顿时气血翻涌，感到天旋地转，显然受了很重的内伤"NOR"",
                "dodge":                20,
                "force":               120,
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N一曲"+BLINK""+HIW"「无言谁会凭栏意」"NOR"，手中$w默默的弹奏着，琴声中的杀气削向$n，
$n"+HIR"被琴声中的内力一震，顿时气血翻涌，感到天旋地转，显然受了很重的内伤"NOR"",
                "dodge":                30,
                "force":               150,
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N运起轻功后退几步，手中$w弹出一曲"+BLINK""+HIW"「拟把疏狂图一醉」"NOR"，琴声加内力对准$n一连刺出七式，
$n"+HIR"被琴声中的内力一震，顿时气血翻涌，感到天旋地转，显然受了很重的内伤"NOR"",
                "force":                100,
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，$w飞上天空但琴声不断,一曲"+BLINK""+HIW"「衣带渐宽终不悔」"NOR"突然间琴以在手全然攻向$n，
$n"+HIR"被琴声中的内力一震，顿时气血翻涌，感到天旋地转，显然受了很重的内伤"NOR"",
                "dodge":                20,
                "force":               80,
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N盘膝而坐,以达到人琴合一的境界,$w自行弹除一曲"+BLINK""+HIW"「为伊消得人憔悴」"NOR"$n$l一阵刺痛，
$n"+HIR"被琴声中的内力一震，顿时气血翻涌，感到天旋地转，显然受了很重的内伤"NOR"",
                "dodge":                20,
                "force":               300,
                "damage_type":  "内伤"
        ]),
              ([      "action":               
"$N弹出一曲"+BLINK""+HIW"「一叶浮萍归大海」"NOR"，手中$w一摆，身形急进如飞，人琴合一，射向$n，
$n"+HIR"被琴声中的内力一震，顿时气血翻涌，感到天旋地转，显然受了很重的内伤"NOR"",
               "dodge":                20,
		  "force":		       100,
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N$w划出道道弧光，一断"+BLINK""+HIW"「人生何处不相逢」"NOR"夹杂着内力，声声不离$n！，
$n"+HIR"被琴声中的内力一震，顿时气血翻涌，感到天旋地转，显然受了很重的内伤"NOR"",
                "dodge":                20,
                "force":               150,
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N手中$w宛如流水，"+BLINK""+HIW"「衰草斜阳流曲浦」"NOR"流露处无限惆怅，琴声斜斜削向$n，
$n"+HIR"被琴声中的内力一震，顿时气血翻涌，感到天旋地转，显然受了很重的内伤"NOR"",
                "dodge":                30,
                "force":               100,
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N手中$w激荡，一曲"+BLINK""+HIW"「黄云影日暗长堤」"NOR"后，起身斩向$n！，
$n"+HIR"被琴声中的内力一震，顿时气血翻涌，感到天旋地转，显然受了很重的内伤"NOR"",
                "dodge":                30,
                "force":                100,
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N手中$w狂舞，琴声团团簇簇，一曲"+BLINK""+HIW"「红萝花繁知景色」"NOR"，飘飘荡荡向$n落去，
$n"+HIR"被琴声中的内力一震，顿时气血翻涌，感到天旋地转，显然受了很重的内伤"NOR"",
                "dodge":                20,
                "force":               100,
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N手中$w琴气森然，一曲"+BLINK""+HIW"「白萍香远任依依」"NOR"暗藏杀机直逼$n，
$n"+HIR"被琴声中的内力一震，顿时气血翻涌，感到天旋地转，显然受了很重的内伤"NOR"",
                "dodge":                20,
                "force":               200,
                "damage_type":  "内伤"
        ]),
([      "action":               
"$N再次进入琴声境界中一曲"+BLINK""+HIW"「缤纷天雨落花红」"NOR"，手中$w摆动，人琴一起霍霍攻向$n，
$n"+HIR"被琴声中的内力一震，顿时气血翻涌，感到天旋地转，显然受了很重的内伤"NOR"",

                "dodge":                20,
                "force":               300,
                "damage_type":  "内伤"
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练习销魂琴。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "qin" )
                return notify_fail("你必须先找一把琴才能练琴艺。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="qin" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习销魂琴。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍销魂琴。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("youxia") + "/xiaohunqin/" + action;
}
 
int effective_level() { return 23;}

string *parry_msg = ({
        "$n使出一招"+HIW"「望极春愁」"NOR"，手中的$v荡开了$N的$w。\n",
        "$n使出"+HIW"「黯黯生天际」"NOR"，将$N的$w封于丈外。\n",
        "$n使出一招"+HIW"「强乐还无味」"NOR"，手中的$v化做漫天残照，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招"+HIW"「对酒当歌」"NOR"，向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，一招"+HIW"「拟对强衣为」"NOR"封住了$N的攻势。\n",
        "$n反手一招"+HIW"「伫望黯草无」"NOR"，整个人消失在一团剑光之中。\n",
        "$n使出一招"+HIW"「倚极黯色言」"NOR"，$v直刺$N的双手。\n",
        "$n将手中的$v一抖，一招"+HIW"「把酒乐带伊」"NOR"，迫得$N连连后退。\n",
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
	return -100;
}
int practice_bonus()
{
	return -50;
}
int black_white_ness()
{
	return 20;
}

