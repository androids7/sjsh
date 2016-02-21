// ȡ���������0.0001

#include <ansi.h>
#include <command.h>
#include <origin.h>

inherit NPC;


int to_sleep();			//˯��
int to_walk();			//���,���������
int to_rest();			//��Ϣ,��ֹͣ�������
int to_huayuan();		//��Ե,���Ͻ𲧸����,����һ�Ե
int to_eat();			//�Է�,�ָ�food��water
				//�޸�/feature/team,���food<20�����ƶ�

   
void me_init();			//�и��������Լ��ĳ�ʼ��,�����������ĳ����
				//�����Ҫ��Ϳ�����me_init�ж���
int accept_object1(object who, object ob);//�����¶����accept_obj

void create()
{
  set_name("ȡ����",({"qujing ren", "qujingren", "shengseng"}));
  
  set("long", "���ƶ���ǰ������ȡ����ʥɮ,����ׯ��\n");
  set("title", "����");
  set("attitude", "friendly");
  set("shen_type", 1);  
  set("gender", "����");
  set("age", 23);
  set("per", 30);
  set("int", 30);
  set("str", 20);
  set("food",300);
  set("water",300);
  set("combat_exp", 1000);

  set("max_gin",800);
  set("max_kee",800);
  set("max_sen",800);
  set("can_sleep",1);		//Ӧ��ֹ���˯����ȡ��������
 
  set("obstacle/qujing","ren"); //ȡ���˵������־ 
  set("no_kill",1);             //����ɱ��Ҫ��kill��ָ����н�ֹ
  set("no_magic",1);		//�����÷���,��Ҫ��cast��ָ��������

  set("inquiry", ([		//һ��ͨ��ask qujingren about xx����Ҫ��
    "sleep" : (: to_sleep :),
    "walk"  : (: to_walk :),
    "rest"  : (: to_rest :),
    "huayuan": (: to_huayuan :),
    "eat"   : (: to_eat   :),
    "˯��"  : (: to_sleep :),
    "��·"  : (: to_walk :),
    "��Ϣ"  : (: to_rest :),
    "��Ե"  : (: to_huayuan :),
    "�Է�"  : (: to_eat   :),

  ]));

  this_object()->me_init();     //�����ؿ����Լ�����ĳ�ʼ����
				//������ļ�����update,Ҫȡ�����
				// 01/18�޸�Ϊthis_object()->��ʽ
				//����update����Ķ�.
  setup();
}



int to_sleep()
  {
  object me=this_object()			;
  object where= environment(me)		 	;
  object who=this_player()			;

  if (who->query("obstacle/qujing")!="ren")return 0;

  if( !where->query("sleep_room"))
    {
    message_vision("$N˵��:������²���˯���ɡ�\n",me,who);
    return 1;
    }
  if (me->is_busy())
    {
    message_vision("$N̾��:�Һ�æҮ��\n",me);
    return 1;
    }
  if ((time()-me->query("last_sleep"))<90)
    {
    message_vision("$Nҡ��ҡͷ˵��:�����ڻ����ۣ�\n",me);
    return 1;
    }

  message_vision("$N���˵�ͷ˵��:����Ϣ��ʱ����,����СЪƬ�̣�\n",me);
  if (where->query("if_bed"))
    {
    message_vision(HIY "$N������һ�꣬��һ����������������������硣\n" NOR,me);
     }
  else 
    { 
    message_vision(HIY "$N�͵�һ�ɣ���һ����������������������硣\n" NOR,me);
    }

    me->set("last_sleep",time());
    me->set_temp("block_msg/all",1);
    if (me->query_temp("ridee"))
	me->query_temp("ridee")->set_temp("rider",0);
    me->set_temp("ridee",0);
    me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
    me->set_temp("ride/dodge",0);
    me->disable_player("<˯����>");
    if (me->query("redef_wake"))   //���ڼ�����me_init������redef_wake
      { 			   //������ȡ����˯������б仯.	
      call_out("wakeup1",random(2)+10, me, where);
      }
    else
      {
      call_out("wakeup",random(2)+10, me, where);
      }
    return 1;   
  }

void wakeup(object me,object where)
  {
  me->enable_player();
  while( environment(me)->is_character() )
	me->move(environment(environment(me)));
  message_vision(HIY "$Nһ����������������ػ��һ�½�ǡ�\n" NOR,me);
  me->set_temp("block_msg/all", 0);
}


int to_walk()
  {
  object me=this_object();
  object who=this_player();

  if (who->query("obstacle/qujing")!="ren")return 0;
  if (me->query("has_followed"))
    return 1;
  message_vision("$N��ȡ����˵��:ʦ��������ˡ�\n",who);
  me->set("has_followed",1);
  me->command_function("follow "+who->query("id"));
  me->set_leader(who);
  return 1; 
  }

int to_rest()
  {
  object me=this_object();
  object who=this_player();

  if (who->query("obstacle/qujing")!="ren")return 0;
  if (!(me->query("has_followed")))
    return 1;
  message_vision("$N��ȡ����˵��:ʦ��ЪϢһ����ˡ�\n",who);
  me->set("has_followed",0);
  me->set_leader(0);
  return 1; 

  }

int to_huayuan()
  {
  object me,who,ob;
  me=this_object();
  who=this_player();
  
  if (who->query("obstacle/qujing")!="ren")return 0;

  if (me->query("food")<=20)
    {
      me->command_function("say ����Щ����,��ȥ��Щի����!");
      if (ob=present("zijin bo",who)) return 1;
      ob=new("/d/qujing/qujingren/changan/obj/zijinbo");
      ob->move(who);
      return 1;
    }
  }

int to_eat()
  {
  object me,who,ob;
  me=this_object();
  who=this_player();
 
  if (who->query("obstacle/qujing")!="ren")return 0;

  if (me->query("food")>20)
    {
	me->command_function("say �һ�����");
	return 1;
    }

  if (ob=present("zijin bo",who))
    {
      if (!(ob->query("have_food")))
        {
        me->command_function("say ��ʲô���Գ���?");
        return 1;
        }
      message_vision("$N�ӹ��Ͻ�,���ĳ�������,��һ��ͳ�����\n",me);
      destruct(ob);
      me->set("food",300);
      me->set("water",300);
      return 1;
    }
  else
    {
      me->command_function("say ��ʲô���Գ���?");
      return 1;
    }
  }

int accept_object (object who, object ob)
{
  object me = this_object();

  if (me->query("redef_accept_obj")!=1) return 0;
   
  return accept_object1(who,ob);
 
}


int follow_path(string dir)
{
	int backval;
        if( (origin()==ORIGIN_LOCAL) || (origin()==ORIGIN_CALL_OUT) ) {
                this_object()->remove_all_enemy();
                reset_eval_cost();
                // because "go" command is very time consuming,
                // so here reset_eval_cost to prevent over cost.
                // mon 4/24/98
                if (this_object()->query("id")=="qujing ren")
                        //blacksh 01/19 qujingren move need time
                  {  
                      if (this_object()->query("food")<20) return 1;
                      backval= GO_CMD->main(this_object(), dir,2);
                      OBSTACLE_D->set("where_qujingren",
                                base_name(environment(this_object())) );
                      this_object()->start_busy(2);
                      return backval;

                   }
                else
                   {
                   return GO_CMD->main(this_object(), dir,2);
                   }

        }
}
