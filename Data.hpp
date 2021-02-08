#pragma once
//用于跨文件传递参数
//确保于第一个#include
//确保编译逻辑
//确保所有信息除预初始化变量必须于执行时初始化

#ifndef _DATA_
#include <cstddef>//所有CXX定义
#include <afxwin.h>

CPoint MouseP;

namespace Data
{
#ifdef FLOAT_LIFE
	long double live;
#else
	BYTE live;
#endif // FLOAT_LIFE

}
#endif // !_DATA_

