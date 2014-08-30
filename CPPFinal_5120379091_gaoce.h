#include <GUI/Simple_window.h>
#include <GUI/GUI.h>
#include <GUI/Graph.h>
class Moon;
class Earth;

class MoonGUI : public Graph_lib::Window//图形类
{
public:
	Moon* moon;
	Earth* earth;
	MoonGUI(Point xy,int w,int h,const string& title);
private:

	Button next_button;
	Button pre_button;
	Button sure_button;
	Graph_lib::In_box inbox; 
	Graph_lib::Out_box outbox;

	static void cb_next_button(Address,Address);
	static void cb_pre_button(Address,Address);
	static void cb_sure_button(Address,Address);

	void next_func();
	void pre_func();
	void sure_func();
};

class Moon :public Shape//月球
{
public:
	Moon(int,Point);
	Moon();
	void draw_lines() const;
	int date;
	Point middle;
};

class Earth : public Shape//地球
{
public:
	Earth(int,Point);
	Earth();
	void draw_lines() const;
	int date;
	Point middle;
};