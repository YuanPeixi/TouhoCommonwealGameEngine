#include "pch.h"
#include "Draw.h"
#include "Data.hpp"
#include "Configure.hpp"

//放置 随机 三角 弧 直线 圆 正弦
//传入子弹参数

//TODO 优化参数列表 (没错就这一个，见过一百个实参的函数吗？)

//需要高速维护的数据
//MouseP 由 afs_msg MouseMove() //可能问题响应不及时 程序极度卡顿 //可能使用Hook
//多线程分布是否合理，是否能体现多线程协作特性 //参考多子弹线程池溢出 //多线程协调性 (子弹一些动一些不动)
//对于子弹的控制 统一协调子弹进程 可能通过统一数据(于 数据类 私有 在while(true)主题判断) （用于决死 炸弹 函数（于常用函数库））
//解释器性能

//需要实现的
//MouseP实时更新
//画布 CRect获取

//应需要更好的体验
//动态背景
//更炫酷的炸弹效果

//考虑跨平台 易用性 便于发展

//考虑文件读取稳定性

//1.考虑上述 完成绘图部分 记得定义全局变量
//2.依照函数表 撰写解释器
//3.检查编译问题 (#include逻辑问题)
//4.调试 性能很重要

//未完部分
//绘图类 文件读取 解释器

#define SHOW //仅用于展示
#ifdef SHOW
void API(void* par)
{
	//Process par 
	//Mulit 
	Bul(par);
}

void Bul(void* par)
{
	//Data Init
	while (true)
	{
		//If overall control var change 
		//do something (Exit or stop,change color)
		//Cover old point
		//point new point
		//Is hit another's obj?
	}
}
#endif

void Draw::RandomBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, CRect ControlSize, unsigned int size, CBrush brush, Byte Shape)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist0(0, 360);
	std::uniform_int_distribution<int> dist1(0,speed);//是否越界

	//随机方向+随机距离
}

void Draw::NormalBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, CRect ControlSize, unsigned int size, CBrush brush, Byte Shape)
{
	int min_unit;
	int total_length = speed * livetime;
	if (LockFPS)
	{
		min_unit = FPS;
	}
	else
	{
		min_unit= 1000;//尽可能优化时间 否则为反优化
		while (true)
		{//检查字尾0 2 4 6 8 5 各位和
			//二分确定单位时间
		}
	}
	int tmp = 0;
	while (tmp < livetime)
	{
		tmp += min_unit;
		CPoint new_p = GetOffSet(p, offset0, min_unit);
		Point(Window, new_p,size,&brush,Shape);
		if (new_p == MouseP)Data::live--;//追加变量随后
	}
}

void Draw::AutomaticSnipingBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, unsigned int correttime, CRect ControlSize, unsigned int size, CBrush brush, Byte Shape)
{
	//实时
	//移动最短长度 重新定位Mouse 更改方向
}

void Draw::SinBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, CRect ControlSize, unsigned int size, CBrush brush, Byte Shape)
{
	//发散 sin(offset + 发散值)
	//不发伞 Proint(GetPoint(offset))

}

void Draw::CosBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, CRect ControlSize, unsigned int size, CBrush brush, Byte Shape)
{
}

void Draw::TanBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, CRect ControlSize, unsigned int size, CBrush brush, Byte Shape)
{
}

void Draw::CotxBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, CRect ControlSize, unsigned int size, CBrush brush, Byte Shape)
{
}
