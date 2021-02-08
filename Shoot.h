#pragma once
#include <cmath>
#include <afxwin.h>
#include <afxext.h>

#include "colorful.h"

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

//Base Function

//!Base Function

class Shoot
{
protected:
	struct ShootParamter
	{
		CWnd* Window;
		CPoint p;
		int offset0;
		unsigned speed;
		unsigned livetime;
		unsigned int size = 15;
		CBrush brush = RGB(255, 0, 0);
		Byte Shape = CIRCLE;
	};

	DWORD WINAPI Point(LPVOID lpParamter)
	{
	}
public:
	void NormalBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, unsigned int size = 15, CBrush brush = RGB(255, 0, 0), Byte Shape = CIRCLE);
	void AutomaticSnipingBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime,unsigned int correttime, unsigned int size = 15, CBrush brush = RGB(255, 0, 0),Byte Shape=CIRCLE);
	void SinBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, unsigned int size = 15, CBrush brush = RGB(255, 0, 0), Byte Shape = CIRCLE);//Window StartPoint 360Row UpDown Speed Livetime BumbSize BumbBrush
	void CosBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, unsigned int size = 15, CBrush brush = RGB(255, 0, 0), Byte Shape = CIRCLE);//Window StartPoint 360Row UpDown Speed Livetime BumbSize BumbBrush
	void TanBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, unsigned int size = 15, CBrush brush = RGB(255, 0, 0), Byte Shape = CIRCLE);//Window StartPoint 360Row UpDown Speed Livetime BumbSize BumbBrush
	void CotxBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, unsigned int size = 15, CBrush brush = RGB(255, 0, 0), Byte Shape = CIRCLE);//Window StartPoint 360Row UpDown Speed Livetime BumbSize BumbBrush
};

