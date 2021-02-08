#pragma once
#include <random>
#include <afxwin.h>
#include "colorful.h"
#include "FunctionLib.hpp"

#ifndef _TOUHO_DRAWING_LIB_
#define _TOUHO_DRAWING_LIB_

#ifndef TOUHOU_DEFINE
//FLAG DEFINE
#define TOUHOU_DEFINE
//BASE DEFINE
#define MAX_VALUE 0XFFFFFFFE
//SHAPE DEFINE
#define CIRCLE 0
#define ELLIPSE 1
#define TRIANGLE 2
//COLOR DEFINE
//Defined in colorful.h
//SPEED DEFINE
#define NormalSpeed 500
//TYPE DEFINE
typedef unsigned char byte;
typedef unsigned char Byte;
#endif // !TOUHOU_DEFINE


class Draw
{
protected:
	inline bool Check(CPoint p,CPoint Max)
	{
		return p.x >= 0 && p.y >= 0 && p.x < Max.x && p.y < Max.y;
	}

	inline void Point(CWnd* Window, CPoint p, unsigned int size, CBrush *brush, Byte Shape)
	{
		//盖住原点
		CClientDC dc(Window);
		//CPen pen(PS_SOLID,penwidth,color);
		CPoint StartPoint, EndPoint;
		StartPoint.x = p.x - (size / 2);
		StartPoint.y = p.y - (size / 2);
		EndPoint.x = p.x + (size / 2);
		EndPoint.y = p.y + (size / 2);

		CBrush* pbr = dc.SelectObject(brush);

		dc.SelectObject(brush);
		switch ((int)Shape)
		{
		case 0:   dc.Ellipse(StartPoint.x, StartPoint.y, EndPoint.x, EndPoint.y); break;
		case 1:   dc.Ellipse(StartPoint.x, StartPoint.y, EndPoint.x, EndPoint.y); break;
		case 2:   dc.Rectangle(StartPoint.x, StartPoint.y, EndPoint.x, EndPoint.y); break;
		default:  throw - 1;
			break;
		}
	}

	inline void Move(CWnd* Window, CPoint Before, CPoint After, unsigned int size, CBrush *brush, Byte Shape)
	{
		//盖住原点
		CClientDC dc(Window);
		//CPen pen(PS_SOLID,penwidth,color);
		CPoint StartPoint, EndPoint;
		StartPoint.x = After.x - (size / 2);
		StartPoint.y = After.y - (size / 2);
		EndPoint.x = After.x + (size / 2);
		EndPoint.y = After.y + (size / 2);

		CBrush* pbr = dc.SelectObject(brush);

		dc.SelectObject(brush);
		switch ((int)Shape)
		{
		case 0:   dc.Ellipse(StartPoint.x, StartPoint.y, EndPoint.x, EndPoint.y); break;
		case 1:   dc.Ellipse(StartPoint.x, StartPoint.y, EndPoint.x, EndPoint.y); break;
		case 2:   dc.Rectangle(StartPoint.x, StartPoint.y, EndPoint.x, EndPoint.y); break;
		default:  throw - 1;
			break;
		}
	}

	inline CPoint GetOffSet(CPoint p, int offset, unsigned int length)
	{
		if (offset < 0)return GetOffSet(p, 360 + offset, length);
		if (offset > 360)return GetOffSet(p, offset % 360, length);
		if (offset < 90)
		{
			int tmp0 = qsin(offset) * length;
			int tmp1 = qcos(offset) * length;
			return CPoint(p.x + tmp1, p.y - tmp0);
		}
		if (offset > 90 && offset < 180)
		{
			int tmp0 = qsin(offset) * length;
			int tmp1 = qcos(offset) * length;
			return CPoint(p.x - tmp1, p.y - tmp0);
		}
		if (offset > 180 && offset < 270)
		{
			int tmp0 = qsin(offset) * length;
			int tmp1 = qcos(offset) * length;
			return CPoint(p.x + tmp1, p.y - tmp0);
		}
		if (offset > 270 && offset < 360)
		{
			int tmp0 = qsin(offset) * length;
			int tmp1 = qcos(offset) * length;
			return CPoint(p.x + tmp1, p.y + tmp0);
		}
		if (offset == 0)
		{
			return CPoint(p.x, p.y + length);
		}
		if (offset == 90)
		{
			return CPoint(p.x - length, p.y);
		}
		if (offset == 180)
		{
			return CPoint(p.x, p.y - length);
		}
		if (offset == 270)
		{
			return CPoint(p.x + length, p.y);
		}
		if (offset == 360)
		{
			return CPoint(p.x, p.y + length);
		}
		return CPoint(0, 0);
	}

	//外部Put接口
	//内部多线程移动
public:
	//Move
	void RandomBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, CRect ControlSize, unsigned int size = 15, CBrush brush = RGB(255, 0, 0), Byte Shape = CIRCLE);
	void NormalBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, CRect ControlSize, unsigned int size = 15, CBrush brush = RGB(255, 0, 0), Byte Shape = CIRCLE);
	void AutomaticSnipingBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, unsigned int correttime, CRect ControlSize, unsigned int size = 15, CBrush brush = RGB(255, 0, 0), Byte Shape = CIRCLE);
	void SinBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, CRect ControlSize, unsigned int size = 15, CBrush brush = RGB(255, 0, 0), Byte Shape = CIRCLE);//Window StartPoint 360Row UpDown Speed Livetime BumbSize BumbBrush
	void CosBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, CRect ControlSize, unsigned int size = 15, CBrush brush = RGB(255, 0, 0), Byte Shape = CIRCLE);//Window StartPoint 360Row UpDown Speed Livetime BumbSize BumbBrush
	void TanBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, CRect ControlSize, unsigned int size = 15, CBrush brush = RGB(255, 0, 0), Byte Shape = CIRCLE);//Window StartPoint 360Row UpDown Speed Livetime BumbSize BumbBrush
	void CotxBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, CRect ControlSize, unsigned int size = 15, CBrush brush = RGB(255, 0, 0), Byte Shape = CIRCLE);//Window StartPoint 360Row UpDown Speed Livetime BumbSize BumbBrush
		//Put

};

#endif