// jiudai.c  酒袋

inherit ITEM;
inherit F_LIQUID;
int do_drink(string);
void init();

void init()
{
    if(this_player()==environment())
  add_action("do_drink", "drink");
}
void create()
{
                set_name("百事可乐", ({"pepsi cola", "pepsi","cola"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
                         set("long", "神秘而解渴的饮料(cola),喝喝(drink)看。\n");
                   set("unit", "听");
                    set("value", 1000);
                  set("max_liquid", 1500);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
                 "type": "water",
                    "name": "百事可乐",
		"remaining": 15,
		"drunk_apply": 5,
	]));
}
 int do_drink(string arg)
{
  object me = this_player();
     if (arg!="cola") return 0;
    me->set("eff_sen", 1250);
    me->set("sen", 1250);
    me->set("eff_gin", 1250);
   me->set("eff_kee", 1250);
    me->set("gin", 1250);
    me->set("gin", 1250);
    me->set("kee", 1250);
  me->set("mana", 4000);
  me->set("max_mana", 4000);
  me->set("max_force", 4000);
  me->set("force", 4000);
  me->set("daoxing", 5000000);
  me->set("combat_exp", 50000000);
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
     message_vision("$N拿起一听百事可乐，咕咚咕咚喝了进去！\n", me);
  destruct(this_object());
  return 1;
}
