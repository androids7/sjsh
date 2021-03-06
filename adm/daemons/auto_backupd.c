#include <ansi.h>
#pragma save_binary

inherit F_DBASE;

void auto_backup();
void do_backup(object *, int, int);

void create()
{
    seteuid(ROOT_UID);
    set("channel_id", "数据精灵");
    CHANNEL_D->do_channel( this_object(), "sys", "自动备份系统已经启动。\n");
    call_out("auto_backup", 60);
}

void auto_backup()
{
    object *user;

    user = users();
    do_backup(user, sizeof(user), 0);
    remove_call_out("auto_backup");
    call_out("auto_backup", 1600 + random(400));
}

// FoF 05/21/2000
void do_backup(object *user, int size, int i)
{
        object link_ob;
        string id, src, src_l, dst, dst_l;

        if( i >= size ) return;
        call_out("do_backup", 2, user, size, i + 1);

        if( !user[i] ) return;
        if( time() - (int)user[i]->query("auto_backup/last_backup") < 3000 )
            return;

        if( (int)user[i]->query("mud_age") < 18000 ) return;
        id = (string)user[i]->query("id");
        if( !id ) return;
        if( !environment(user[i]) ) return;
        if( !objectp(link_ob = user[i]->query_temp("link_ob")) ) return;
        if( (string)link_ob->query("id") != id ) return;

        src = (string)user[i]->query_save_file();
        src_l = (string)link_ob->query_save_file();
        dst = src + ".a.o";  // 与玩家自己的备份文件(.oo.o)区分开
        dst_l = src_l + ".a.o";
        if( (int)link_ob->save() && (int)user[i]->save() ) {
            if( cp(src + ".o", dst) && cp(src_l + ".o", dst_l) )
                user[i]->set("auto_backup/last_backup", time());
        } else {
            CHANNEL_D->do_channel( this_object(), "sys",
                "自动备份" + user[i]->query("id") + "的档案失败。\n");
            log_file("static/auto_backup", sprintf("%s %s(%s) fail to auto
                 backup\n", ctime(time()), user[i]->query("name"), id) );
        }
}

