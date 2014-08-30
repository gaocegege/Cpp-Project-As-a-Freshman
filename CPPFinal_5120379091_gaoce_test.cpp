//5120379091 高策
//计算公式：x=x-2*r/15.即每过一天，地球移动2*r/15，月球保持不动。
/*实现功能：
1.next
2.previous
3.通过输入框咨询大部分月历
4.输出"XX days after/before the new moon"
5.天数为正值时实现了30天循环
*/
#include "CPPFinal_5120379091_gaoce.h"
#include <GUI/Window.h>
#include <GUI/GUI.h>
#include <GUI/Graph.h>

int main()
{
	MoonGUI MoMo(Point(100,100),500,500,"cece");
	MoMo.color(Color::yellow);
	return Graph_lib::gui_main();
}
