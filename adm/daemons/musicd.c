// Daemon:/adm/daemons/musicd.c
// 音乐歌曲演奏程序


#include <ansi.h>

inherit F_SAVE;
#define MUSIC_FILE "/data/music.o"

/*************************************
 * 格式为：
 * string歌曲名称:([   "name":string中文名称,
 * "song":string*歌曲内容,
 * "author":string歌曲作者
 *  "color":string*歌曲颜色,]),
 *
 ************************************/

mapping songs=([
"yumeiren":([
"name":"虞美人",
"song":"
春花秋月何时了，
往事知多少？
小楼昨夜又东风，
故国不堪回首月明中。

雕阑玉砌应犹在，
只是朱颜改。
问君能有几多愁，
恰似一江春水向东流。",
"author":"李煜",
"color":({HIC,HIY}),
]),
"xiangjianhuan_i":([
"name":"相见欢 I",
"song":"
林花谢了春红，太匆匆。
哪及它朝来寒重晚来风！

胭脂泪，留人醉，几时重？
自是人生长恨水长东！",
"author":"李煜",
"color":({HIG,HIM}),
]),
"xiangjianhuan_ii":([
"name":"相见欢 II",
"song":"
无言独上西楼，月如钩。
寂寞梧桐深院锁清秋。

剪不断，理还乱，是离愁。
别是一番滋味在心头。",
"author":"李煜",
"color":({HIB,HIR}),
]),

]);

void create()
{
seteuid(getuid());

if (file_size(MUSIC_FILE)<=0){
save();
}
restore();
}

string query_save_file()
{
return MUSIC_FILE;
}

// 下面是一些查询的函数
mapping query_songs()
{
return songs;
}

mapping query_song(string id)
{
return songs[id];
}

string query_song_name(string id)
{
return songs[id]["name"];
}

string *query_song_color(string id)
{
return songs[id]["color"];
}

string query_song_context(string id)
{
return songs[id]["song"];
}

string query_song_author(string id)
{
return songs[id]["author"];
}

// 下面是一些修改的函数
void set_song(string id,mapping song)
{
songs[id]=song;
log_file("music",sprintf("%s 被加入到乐曲库中。\n",id));
save();
}

void delete_song(string id)
{
map_delete(songs,id);
log_file("music",sprintf("%s 被从乐曲库中删除。\n",id));
save();
}
