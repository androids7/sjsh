 // skill talk ,by boy

inherit SKILL;

mapping *action = ({
	([	"action":
"$N张开血盆大嘴，一式「血口喷人」，叽里呱啦的骂开$n",
		"force":		150,
                "damage_type":          "骂伤",
      "weapon" :              "双嘴",
        "parry_msg":    "只见$N闭目凝神,置之不理",
	]),
	([	"action":
  "$N张开血盆大嘴，一式「狗血淋头」，叽里呱啦的骂开$n",
		"force":		100,
                "damage_type":          "骂伤",
      "weapon" :              "双嘴",
        "parry_msg":    "只见$N闭目凝神,置之不理",
	]),
	([	"action":
       "$N脸不红心不跳，一式「衰神附体」，噼里啪啦的骂开$n",
		"force":		120,
                "damage_type":          "骂伤",
      "weapon" :              "唇音",
                   "parry_msg":    "只见$N闭目凝神,置之不理",
	]),
	([	"action":
             "$N脸皮抽动，一式「大话无边」，噼里啪啦的骂开$n",
		"force":		100,
                "damage_type":          "震伤",
      "weapon" :              "唇音",
        "parry_msg":    "只见$N闭目凝神,置之不理",
	]),
            ([	"action":
             "只见$N昂首挺胸，一式「我行我素」，唏哩哗啦的骂开$n",
		"force":		150,
                "damage_type":          "衰伤",
      "weapon" :              "口气",
        "parry_msg":    "只见$N闭目凝神,置之不理",
	]),
            ([	"action":
             "只见$N立定乾坤，一式「聊侃无敌」，唏哩哗啦的骂开$n",
		"force":		180,
                "damage_type":          "气伤",
      "weapon" :              "口音",
        "parry_msg":    "只见$N闭目凝神,置之不理",
	]),
});

int valid_learn(object me)
{


   if(me->query("id")!="boy" )
     return notify_fail("这项功夫不可以练。\n");
	return 1;
}

int valid_enable(string usage)
{
       return usage=="literate";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}


string perform_action_file(string func)
{
	return CLASS_D("dragon") + "/dragonfight/" + func;
}
