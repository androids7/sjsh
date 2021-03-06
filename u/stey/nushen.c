#include <ansi.h>

int pk();
int nopk();

inherit NPC;

void create()
{
  set_name(HIW"自由女神"NOR, ({ "ziyou nushen", "nushen"}));
  set("title", HIC"宝鸡站"NOR);   
  set("long", HIW"\n一位娇柔万分的女子，伶俐地扭动着腰肢。\n手举自由火把，有关于自由的事，可以问问她。\n"NOR+HIC"\n ask nushen about pk \n ask nushen about no pk \n\n"NOR);
  set("gender", "女性");
  set("age", 16);
  set("attitude", "heroism");
  set("per", 32);
  set("max_kee", 5000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 6000);
  set("max_force", 12000);
  set("force_factor", 300);
  set("max_mana", 7000);
  set("mana", 16000);
  set("mana_factor", 350);
  set("combat_exp", 2400000);
  set("daoxing", 6800000);  
  set("chat_msg", ({
        "女神轻声告诉你：pk是一件很严肃的决定，你考虑清楚，一次定终身的。\n",
        "女神轻声告诉你：选择了pk,就没办法反悔的，人生奈何几沉浮。\n",             
        }));
  set("inquiry", ([
  "name" : "我就是宝鸡站的自由女神，你可以选择“pk”或者“nopk”来决定你以后的人生。\n",
  "here" : "你可以选择“pk”或者“nopk”来决定你以后的人生。\n",
  "PK"   : (:pk:),
  "pk"   : (:pk:),
  "NOPK" : (:nopk:),
  "nopk" : (:nopk:),
  "no pk" : (:nopk:),
  ]));
  setup();
}

int pk()
{
string str;
object who = this_player();
object ob = this_object();

void init()
{
	::init();  
  add_action("do_yao","yao");
}
if (this_player()->query("ziyou")=="got")
{
message_vision("自由女神对着$N说：“你的人生已经决定了，你还想变改？”\n",who);
return 1;
}
else
{
message_vision("自由女神对着$N说：“你考虑清楚了吗？决定了就说pkpk。\n",who);	
  int do_pkpk(string arg)
   {
 	string type;
	object ob;
	object who=this_player();
	object me=this_object();
	str=who->name();
message("channel:chat",HIW"【仙侣情缘】自由女神："+str+"已经选择了PK这条道路，望大家知照。\n"NOR,users());
message("channel:rumor",HIW"【谣言】自由女神："+str+"已经选择了PK这条道路，望大家知照。\n"NOR,users());
message_vision("自由女神在举起火把，往$N头上轻轻一挨，对$N说：“你现在已经选择了PK这条道路，以后好自为之啦。”\n",who);
who->set("ziyouchoose","pk");
who->set("pk","pk");
who->set("ziyou","got");
     }
return 1;
}        
         
int nopk()
{        
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("ziyou")=="got")
{        
message_vision("自由女神对着$N说：“你的人生已经决定了，你还想变改？”\n",who);
return 1;
}        
else     
{        
str=who->name();
message("channel:chat",HIW"【仙侣情缘】自由女神："+str+"已经选择了NOPK这条道路，大家以后不要再为难他了。\n"NOR,users());
message("channel:rumor",HIW"【谣言】自由女神："+str+"已经选择了NOPK这条道路，大家以后不要再为难他了。\n"NOR,users());
message_vision("自由女神在举起火把，往$N头上轻轻一挨，对$N说：“你现在已经选择了NOPK这条道路，以后请多帮别人的忙。”\n",who);
who->set("ziyouchoose","nopk");
who->set("nopk","nopk");
who->set("ziyou","got");
return 1;
}        
}        
         
      
