#include "CPPFinal_5120379091_gaoce.h"
const int WIDTH=100;
const int HEIGHT=30; 
const double r=30;

MoonGUI::MoonGUI(Point xy,int w,int h,const string& title)
	:Window (xy , w , h , title),
	next_button(Point(0,0),WIDTH,HEIGHT,"next",cb_next_button),
	pre_button(Point(WIDTH,0),WIDTH,HEIGHT,"previous",cb_pre_button),
	inbox(Point(WIDTH,2*HEIGHT),WIDTH,HEIGHT,"Date:"),
	sure_button(Point(2*WIDTH,2*HEIGHT),WIDTH,HEIGHT,"Sure",cb_sure_button),
	outbox(Point(WIDTH,3*HEIGHT),2*WIDTH,HEIGHT,"The date:")
{
	moon=new Moon(1,Point(400,400));
	earth=new Earth(0,Point(400,400));
	attach(inbox);
	attach(next_button);
	attach(pre_button);
	attach(sure_button);
	attach(*moon);
	attach(*earth);
	attach(outbox);
	outbox.put("the new moon");
}

void MoonGUI::cb_next_button(Address,Address w)
{
	reference_to<MoonGUI>(w).next_func();
}

void MoonGUI::cb_pre_button(Address,Address w)
{
	reference_to<MoonGUI>(w).pre_func();
}

void MoonGUI::cb_sure_button(Address,Address w)
{
	reference_to<MoonGUI>(w).sure_func();
}

void MoonGUI::next_func()//实现next的函数
{
	earth->date=earth->date+1;
	stringstream is;
	string result;
	if (earth->date<0){
		is<<-earth->date;
		result=is.str()+" days before new moon";
	}
	else if (earth->date>0)
	{
		is<<earth->date;
		result=is.str()+" days after new moon";
	}
	else if (earth->date==0)
		result="the new moon";
	outbox.put(result);
	redraw();
}

void MoonGUI::pre_func()
{
	earth->date=earth->date-1;
	stringstream is;
	string result;
	if (earth->date<0){
		is<<-earth->date;
		result=is.str()+" days before new moon";
	}
	else if (earth->date>0)
	{
		is<<earth->date;
		result=is.str()+" days after new moon";
	}
	else if (earth->date==0)
		result="the new moon";
	outbox.put(result);
	redraw();
}

void MoonGUI::sure_func()
{
	string a=inbox.get_string();
	earth->date=stoi(a);
	stringstream is;
	string result;
	if (earth->date<0){
		is<<-earth->date;
		result=is.str()+" days before new moon";
	}
	else if (earth->date>0)
	{
		is<<earth->date;
		result=is.str()+" days after new moon";
	}
	else if (earth->date==0)
		result="the new moon";
	outbox.put(result);
	redraw();
}
//next func
//p
//sure

Moon::Moon()
	:date(1),middle(Point(100,100))
{

}

Earth::Earth()
	:date(1),middle(Point(100,100))
{

}

Moon::Moon(int d,Point m)
	:date(d),middle(m)
{
}

Earth::Earth(int d,Point m)
	:date(d),middle(m){}

void Moon::draw_lines() const
{
	fl_circle(middle.x,middle.y,r);
	
}

void Earth::draw_lines() const
{
	if (date%30<15)
	{
		double midx=middle.x-date%30*2*r/15.0;//小于15时的计算
		double midy=middle.y;
		fl_pie(midx-r,midy-r,2*r,2*r,0,360);
	}
	if (date%30>=15)
	{
		double midx=middle.x+4*r-date%30*2*r/15.0;//大于15时做的计算
		double midy=middle.y;
		fl_pie(midx-r,midy-r,2*r,2*r,0,360);
	}
}