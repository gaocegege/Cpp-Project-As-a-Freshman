//5120379091 �߲�
//���㹫ʽ��x=x-2*r/15.��ÿ��һ�죬�����ƶ�2*r/15�����򱣳ֲ�����
/*ʵ�ֹ��ܣ�
1.next
2.previous
3.ͨ���������ѯ�󲿷�����
4.���"XX days after/before the new moon"
5.����Ϊ��ֵʱʵ����30��ѭ��
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
