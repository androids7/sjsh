// dieda.c ������ by piao

inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("������", ({"dieda wan", "dieda", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("base_unit","��");
        set("unit","Щ");
                set("long", "����һ�����˵ĵ���ҩ��\n");
                set("value", 2000);
				set("drug_type", "��ҩ");
        }
   set_amount(1);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
//        if ((int)this_player()->query("eff_kee") == 
//            (int)this_player()->query("max_kee"))
//                return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n")
        else {
                this_player()->receive_curing("kee", 50);
                message_vision("$N����һ�ŵ����裬��ɫ�������ö��ˡ�\n",
this_player());
         add_amount(-1);
                return 1;
        }
}
