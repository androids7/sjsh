//����npc
inherit F_VENDOR_SALE;

#include <ansi.h>
int give_wx();
int give_wx2();
int answer_me();

void create()
{
         set_name(HIC"�񱦱�"NOR, ({"baobao"}));
   set ("long", @LONG
���������︺�����ҷ���ѧ�����Ŀɰ����񱦱�����ask baobao about ������
LONG);
           set("gender", "����");
        set("title",HIY"���ÿɰ���"NOR);
        set("age", 28);
        set("per", 40);
        set("attitude", "peaceful");
        set("vendor_goods", ([ 
                "ling":    "/u/stey/liwu/liwu/obj/ling.c",
                "whip":    "/u/stey/yaowhip1.c",
                "hammer":    "/u/stey/tianhammer.c",
                "sword":    "/u/stey/sttt.c",
                "fork":    "/u/stey/shenfork.c",
                "spear":    "/u/stey/shenspear.c",
                "stick":    "/u/stey/tianbang.c",
                "mace":    "/u/stey/goldjian.c",
                "qin":    "/u/stey/moqin.c",
                "blade":    "/u/stey/guiblade.c",
                "staff":    "/u/stey/shenstaff.c", 
                "spellsbook":    "/d/obj/book/mihou-book.c",   
                "parrybook":    "/d/obj/book/parrybook2",
                "forcebook":    "/d/obj/book/forcebook2",
        ]) );
        set("inquiry", ([
            "����"    :(:give_wx:),
            "��ѧ����"    :(:give_wx:),
            "jiangli"    :(:give_wx:),
            "150��"    :(:give_wx2:),
   ]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
}
int answer_me()
{
        command("say С���ұ��㣡�ٺ� ��\n");
        return 1;
}
int give_wx()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say ʲôСèС��Ҳ��Ҫ����?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 500000 ){
                command("hammer "+who->query("id") );
                command("say ����Ŭ��Ŭ�����ܿ�����ý����ġ�");
                command("addoil "+who->query("id") );
                return 1;
         }
         if (this_player()->query("jjj") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        who->add("potential",50000);
        who->add("balance",5000000);
        who->add("daoxing",50000);
        who->set("jjj",1);
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
               ��ĵ�����������ʮ��!\n 
               �����ڴ��������500gold��\n");
          command("chat ��ϲ��ϲ��"+who->query("name")+"��ѧ����50�򣬸��轱����\n");
        return 1;
}
int give_wx2()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say ʲôСèС��Ҳ��Ҫ����?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 1500000 ){
                command("hammer "+who->query("id") );
                command("say ����Ŭ��Ŭ�����ܿ�����ý����ġ�");
                command("addoil "+who->query("id") );
                return 1;
         }
         if (who->query("combat_exp") > 1900000 ){
                command("hammer "+who->query("id") );
                command("say �㶼��ô����������Ҫ��̰�ģ���");
                command("kick "+who->query("id") );
                return 1;
         }
         if (this_player()->query("jjjj") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        who->add("potential",80000);
        who->add("balance",5000000);
        who->add("daoxing",100000);
        who->set("jjjj",1);
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
               ��ĵ���������һ����!\n 
               �����ڴ��������500gold��\n");
          command("chat ��ϲ��ϲ��"+who->query("name")+"��ѧ����150�򣬸��轱����\n");
        return 1;
}
void init()
{
     call_out("greeting", 1, this_player());
      ::init();
   add_action("do_vendor_list", "list");
}
void die()
{
 return;
}
