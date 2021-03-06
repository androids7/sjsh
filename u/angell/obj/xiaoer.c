//xiaoer.c

inherit F_VENDOR_SALE;

void clear_room();

void create()
{
       reload("xiaoer");
       set_name("店小二", ({"xiao er","xiaoer","xiao","waiter","er"}));
       set("shop_id",({"waiter","xiaoer","xiao","er"}));
       set("shop_title","店小二");
       set("gender", "男性");
       set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("max_price",20);
       set("vendor_goods", ([
                "jiudai": "/d/moon/obj/jiudai",
                "pillow": "/d/obj/misc/pillow",
                "yaoqin": "/u/angell/obj/yaoqin",
                "candle": "/u/angell/obj/candle",
                "wan": "/d/city/obj/newwan.c",
                "gourou": "/d/ourhome/obj/gourou",
                 "jinpai" : "/d/obj/misc/tiaozhanpai",
                "tu": "/d/city/obj/tu",
                "jitui": "/d/ourhome/obj/jitui",
                 "mao": "/d/lingtai/obj/shengmao",
                "huasheng": "/d/ourhome/obj/huasheng",
                "zhinan": "/d/obj/misc/xiaqi-zhinan",                     
        ]) );

  //      if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
       setup();

       carry_object("/d/obj/cloth/linen")->wear();
       add_money("silver", 1);
        remove_call_out("clear_room");
        call_out("clear_room",300);
}

void init()
{
        object me,ob;
        me=this_object();
        ob=this_player();
       
        ::init();
       
        if(ob->query_condition("no_pk_time"))
          {
                message_vision("“杀人在逃期间不要来影响我做生意!”，$N一把把$n推了出去。\n",me,ob);
                ob->move("/d/city/zhuque-s1");
                message_vision("$N被人一把推了过来，差点摔倒在地。\n",ob);
                ob->start_busy(5);
          }
      
                        
       else if( interactive(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
              
        
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say( name()+"笑咪咪地说道：这位" +
RANK_D->query_respect(ob)
                                + "，进来歇歇脚，喝两盅吧。\n");
                        break;
        }
}

void clear_room()
{
        string *place1 = 
        ({"/d/city/zhuque-s1","/d/city/center","/d/city/xuanwu-n1",
        "/d/city/baihu-w1","/d/city/qinglong-e1",});
        string room;
        int race, obj,i;
        object *inv;    
        race = 0;
        obj = 0;        
        if(environment(this_object())){
        inv = all_inventory(environment(this_object()));
        say(name()+"抱歉地说道：“小店清扫，各位客官原谅则个。”\n");
        for (i = 0;i <sizeof(inv);i++)
        {
                if(inv[i]->query("race")=="野兽") 
                {
                        room = place1[random(5)];
                        say(inv[i]->query("name")+"被"+name()+"用扫帚赶了出去。\n");
                        inv[i]->set_temp("no_return",0);
                        inv[i]->set_temp("rider",0);
                        inv[i]->move(room);
                        tell_room(environment(inv[i]), inv[i]->query("name")+"被"+name()+"从客栈赶了出来。\n");
                        race++;
                }
                else if(!inv[i]->is_character()&&!inv[i]->query("board_id"))
                 {obj++; 
                 destruct(inv[i]);}
                else if(inv[i]->query_temp("ridee"))
                {
                        inv[i]->set_temp("ridee",0);
                        inv[i]->add_temp("apply/dodge",-inv[i]->query_temp("ride/dodge"));
                        inv[i]->set_temp("ride/dodge",0);
                
                 }
        }
     }
      remove_call_out("clear_room");
      call_out("clear_room",600);
}
int accept_object(object who, object ob)
{
    int value;

        if (ob->query("money_id") && (value=ob->value()) >= 300) 
        {
                tell_object(who, name()+
                        "一哈腰，说道：多谢您老，客官请上房歇息。\n");
                who->set_temp("rent_paid",1);
                take_money(value, 300);
                return 1;
        }
        return 0;
}

