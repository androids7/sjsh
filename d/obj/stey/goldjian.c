// silverjian.c
// created 5-30-97 pickle

#include <weapon.h>
#include <ansi.h>

inherit MACE;

void create()
{
  set_name(HIW "金装锏" NOR, ({"gold mace", "mace", "goldmace", "jinjian", "jian"}));
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 100000);
    set("material", "silver");
    set("long", "一柄闪闪发光的金银锏，显然是被人擦了又擦。\n");
    set("wield_msg", "只见一道金光闪过，$N手里已经多了一柄$n！\n");
    set("unwield_msg", "$N收起了$n，四周光芒为之一暗！\n");
  }
  
  init_mace(115);
  setup();
}

