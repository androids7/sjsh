// 神话世界·西游记·版本(世纪)
 

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("大酒罐", ({"jiuguan", "pot","guan"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
     set("long", "一个用来装酒的大酒罐子，一看就知道是农家最常用的。\n");
     set("unit", "个");
     set("value", 100);
     set("max_liquid", 15);
  }

  set("liquid", ([
        "type": "alcohol",
        "name": "黄酒",
        "remaining": 35,
        "drunk_supply": 35,
      ]));
}

