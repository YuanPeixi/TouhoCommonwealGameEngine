#pragma once
//���ڿ��ļ����ݲ���
//ȷ���ڵ�һ��#include
//ȷ�������߼�
//ȷ��������Ϣ��Ԥ��ʼ������������ִ��ʱ��ʼ��

#ifndef _DATA_
#include <cstddef>//����CXX����
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

