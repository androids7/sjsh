// shaolin-shenfa.c
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
	"$n身子如行云流水般,前后脚脚尖脚跟相靠，一式「一苇渡江」滑出丈余。\n",
"但是$n身形飘忽，轻轻一纵，早已避开。\n",
	"$n双臂前伸，全身贴地平飞,一式「雨燕掠波」顿时闪过了$N的凌厉攻势。\n",
"$n身随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
	"$n一声：好！一式「移步换形」，足不动，手不抬，一转眼间便绕到了$N的身后。\n",
"可是$n侧身一让，$N这一招扑了个空。\n",
	"$n左足一点，一式「分身化影」，一转身间，四面八方飘动着无数个$n的身影,$N手无足措。\n",
"却见$n足不点地，往旁窜开数尺，躲了开去。\n",
           "但是$n一式「孤骛落日」，全身笔直，拔地而起，在半空中一转，已落到几丈远的地方。\n",
"$n身形微晃，有惊无险地避开了$N这一招。\n"
	"可是$n胸腹往后一缩,两臂鹏举如翼，在剌剌风声中一式「鸿雁双飞」，从$N头顶横跃而过。\n",
"可是$n恰巧往右走了一步，躲过了$N这一招。\n",
	"$n连退几步,一式「苍龙出水」，双脚点地，全身化为一道白影，急速绕着$N打了几转。\n",
 "$n漫不经心的向左迈出一步，刚好避过$N的凌厉攻势。\n",
       "只见$n身体如陀螺般急转，气流形成一个个漩涡,一式「稚凤归巢令」令$N陷身其间，动弹不得。\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("你的内力不够，没有办法练少林身法。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练少林身法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

