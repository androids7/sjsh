// dan.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"��ϼ��"NOR, ({ "dan" }) );
        set("long",
HIM"��˿�������������ϳ˵��鵤��ҩ��\n"NOR);
        set("unit", "��");
        set("weight", 5);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");

          if( living( this_player())==0) return 0;

          if( living( this_player())==0) return 0;

        ob=this_player(); 
        ob->set_skill("force",80);
        ob->set_skill("parry",80);
        ob->set_skill("dodge",80);
        ob->set_skill("sword",80);
        ob->set_skill("unarmed",80);
        ob->set_skill("literate",80);
        ob->set_skill("jiuyin-xinjing",50);
        ob->set_skill("spells",50);
        ob->set_skill("lanhua-shou",50);
        ob->set_skill("chixin-jian",50);
        ob->set_skill("pansi-dafa",50);
        ob->set_skill("yueying-wubu",50);
write(HIM+"����һ����ϼ����ֻ����һ�����������������!��ʱ�����˿�����书��������\n"NOR);

        message("vision", HIM + ob->name() + 
"����һ����ϼ����ֻ����һ������������������!��ʱ������˿�����书��������\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}