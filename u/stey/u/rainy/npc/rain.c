#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIM"�۶�"NOR,({"rain"}));
set("long","һ��ʮ�˾���Ĺ��������������Ц�ݣ��о�������֮�ݡ�\n");
set("title",HIY"����ĹԹ�����"NOR);
set("gender","Ů��");
set("per",40);
set("age",19);
set("str",35);
set("con",30);
set("int",30);
set("max_kee", 1000);
set("eff_kee", 1000);
set("kee", 1000);
set("max_force",2000);
set("force",400);
set("combat_exp", 1000000);
set("inquiry",([
"rainy": "�Ǹ����������֣���޾Ϳޣ���Ц��Ц��Ѿͷ�����ң���������Ϲ�����Ȼ�Һ�Ƥ���ܰ�˽����׽Ū������������������ǣ������......\n",
"�۶�": "�Ǹ����������֣���޾Ϳޣ���Ц��Ц��Ѿͷ�����ң���������Ϲ�����Ȼ�Һ�Ƥ���ܰ�˽����׽Ū������������������ǣ������......\n",
"yiq": "û�п����칫���ϵ����š�ȫ�Ҹ�������Ƭ�Ů�������ң������ǵ�Ȼ�����������������������˰ɣ�����\n",
"����": "û�п����칫���ϵ����š�ȫ�Ҹ�������Ƭ�Ů�������ң������ǵ�Ȼ�����������������������˰ɣ�����\n",
"love": "�����Ұ�����ʲô�����������֪���𰸣�ȥ����ڣ���������ˡ���������ȥ�����Ѿ����ˣ�����վ������ǰ����һֻ�մӼ���ɳ����ĺ�����\n",
 ]));
set("chat_chance",9);
set("chat_msg", ({
HIM"�۶�΢Ц�Ŷ���˵:��û�з����������ڵ��Ϲ���������˵���·�Ҫ���ҽ����£����ǰ������\n"NOR,
HIM"�۶�΢Ц�Ŷ���˵:����һҶ��Ƽ����Ư��������Ҳ�޸����������ڣ����ҵ��˸���\n"NOR,
}));
setup();
carry_object("/u/rainy/hunsha")->wear();
carry_object("/u/rainy/obj/rose")->wear();
carry_object("/u/rainy/obj/xue")->wear();
carry_object("/u/rainy/obj/star")->wield();
}