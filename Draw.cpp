#include "pch.h"
#include "Draw.h"
#include "Data.hpp"
#include "Configure.hpp"

//���� ��� ���� �� ֱ�� Բ ����
//�����ӵ�����

//TODO �Ż������б� (û�����һ��������һ�ٸ�ʵ�εĺ�����)

//��Ҫ����ά��������
//MouseP �� afs_msg MouseMove() //����������Ӧ����ʱ ���򼫶ȿ��� //����ʹ��Hook
//���̷ֲ߳��Ƿ�����Ƿ������ֶ��߳�Э������ //�ο����ӵ��̳߳���� //���߳�Э���� (�ӵ�һЩ��һЩ����)
//�����ӵ��Ŀ��� ͳһЭ���ӵ����� ����ͨ��ͳһ����(�� ������ ˽�� ��while(true)�����ж�) �����ھ��� ը�� �������ڳ��ú����⣩��
//����������

//��Ҫʵ�ֵ�
//MousePʵʱ����
//���� CRect��ȡ

//Ӧ��Ҫ���õ�����
//��̬����
//���ſ��ը��Ч��

//���ǿ�ƽ̨ ������ ���ڷ�չ

//�����ļ���ȡ�ȶ���

//1.�������� ��ɻ�ͼ���� �ǵö���ȫ�ֱ���
//2.���պ����� ׫д������
//3.���������� (#include�߼�����)
//4.���� ���ܺ���Ҫ

//δ�겿��
//��ͼ�� �ļ���ȡ ������

#define SHOW //������չʾ
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
	std::uniform_int_distribution<int> dist1(0,speed);//�Ƿ�Խ��

	//�������+�������
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
		min_unit= 1000;//�������Ż�ʱ�� ����Ϊ���Ż�
		while (true)
		{//�����β0 2 4 6 8 5 ��λ��
			//����ȷ����λʱ��
		}
	}
	int tmp = 0;
	while (tmp < livetime)
	{
		tmp += min_unit;
		CPoint new_p = GetOffSet(p, offset0, min_unit);
		Point(Window, new_p,size,&brush,Shape);
		if (new_p == MouseP)Data::live--;//׷�ӱ������
	}
}

void Draw::AutomaticSnipingBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, unsigned int correttime, CRect ControlSize, unsigned int size, CBrush brush, Byte Shape)
{
	//ʵʱ
	//�ƶ���̳��� ���¶�λMouse ���ķ���
}

void Draw::SinBullet(CWnd* Window, CPoint p, int offset0, int offset1, unsigned speed, unsigned livetime, CRect ControlSize, unsigned int size, CBrush brush, Byte Shape)
{
	//��ɢ sin(offset + ��ɢֵ)
	//����ɡ Proint(GetPoint(offset))

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
