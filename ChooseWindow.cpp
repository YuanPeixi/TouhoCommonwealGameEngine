// ChooseWindow.cpp: 实现文件
//

#include "pch.h"
#include "resource.h"
#include "Configure.hpp"
#include "TouhoProject Demo 1.3 Alpha.h"
#include "ChooseWindow.h"
#include "afxdialogex.h"
#include "FunctionLib.hpp"


// ChooseWindow 对话框

IMPLEMENT_DYNAMIC(ChooseWindow, CDialog)

ChooseWindow::ChooseWindow(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{
	LoadConfig();

}

ChooseWindow::~ChooseWindow()
{
}

void ChooseWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BACKGROUND, BackgroundPicCtl);
	DDX_Control(pDX, IDC_BACKGROUND2, ChooseWndBackground);
	DDX_Control(pDX, IDC_FORGROUND, ChooseWndForground);
	DDX_Control(pDX, IDC_TITLE2, GameTitle);
}


BEGIN_MESSAGE_MAP(ChooseWindow, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// ChooseWindow 消息处理程序

//Localization Whole Window


void ChooseWindow::OnPaint()
{
	//LoadBackground
	if (background == "")
	{
		return;//BaseBackground RGB(255,255,255)
	}
	if (!Existed(background.c_str()))
	{
		MessageBox(L"丢失背景图片", L"错误", MB_YESNO);//Localization
	}
	else
	{
		CRect rc;
		ChooseWndBackground.GetClientRect(&rc);
		CDC* pdcpic = ChooseWndBackground.GetDC();  //ChooseWndBackground是Picture控件的变量  

		CBitmap bitmap1;
		HBITMAP hbmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			(LPCWSTR)background.c_str(), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE);  
		bitmap1.Attach(hbmp);//IDB_BITMAP_PROTOCOL_3是要加载的位图的ID  
		BITMAP bmp1;
		bitmap1.GetBitmap(&bmp1);
		CDC memdc;
		memdc.CreateCompatibleDC(pdcpic);
		memdc.SelectObject(&bitmap1);

		CDC ppdc;
		ppdc.CreateCompatibleDC(pdcpic);
		CBitmap bmpbuf;                    //bmpbuf是要放入控件中的位图  
		bmpbuf.CreateCompatibleBitmap(pdcpic, rc.right, rc.bottom);
		ppdc.SelectObject(&bmpbuf);

		ppdc.StretchBlt(rc.left, rc.top, rc.Width(), rc.Height(), &memdc, 0, 0, bmp1.bmWidth, bmp1.bmHeight, SRCCOPY);  //将IDB_BITMAP_PROTOCOL_3复制到bmpbuf位图中，并按指定的大小转换  

		ChooseWndBackground.SetBitmap((HBITMAP)bmpbuf.Detach());
		ChooseWndBackground.ReleaseDC(pdcpic);
		memdc.DeleteDC();

	}
	//End LoadBackground
	//Forground
	if (forgeground != "")
	{
		CRect rc;
		ChooseWndBackground.GetClientRect(&rc);
		CDC* pdcpic = ChooseWndBackground.GetDC();  //ChooseWndBackground是Picture控件的变量  

		CBitmap bitmap1;
		HBITMAP hbmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
			(LPCWSTR)forgeground.c_str(), IMAGE_BITMAP,
			0, 0, LR_LOADFROMFILE);
		bitmap1.Attach(hbmp);//IDB_BITMAP_PROTOCOL_3是要加载的位图的ID  
		BITMAP bmp1;
		bitmap1.GetBitmap(&bmp1);
		CDC memdc;
		memdc.CreateCompatibleDC(pdcpic);
		memdc.SelectObject(&bitmap1);

		CDC ppdc;
		ppdc.CreateCompatibleDC(pdcpic);
		CBitmap bmpbuf;                    //bmpbuf是要放入控件中的位图  
		bmpbuf.CreateCompatibleBitmap(pdcpic, rc.right, rc.bottom);
		ppdc.SelectObject(&bmpbuf);

		ppdc.StretchBlt(rc.left, rc.top, rc.Width(), rc.Height(), &memdc, 0, 0, bmp1.bmWidth, bmp1.bmHeight, SRCCOPY);  //将IDB_BITMAP_PROTOCOL_3复制到bmpbuf位图中，并按指定的大小转换  

		ChooseWndBackground.SetBitmap((HBITMAP)bmpbuf.Detach());
		ChooseWndBackground.ReleaseDC(pdcpic);
		memdc.DeleteDC();
	}
	else
	{
		GetDlgItem(IDC_FORGROUND)->ShowWindow(FALSE);
	}
	//End Forground
	//GameTitle
	if (font != "")
	{
		CFont m_editFont;
		m_editFont.CreatePointFont(180, (LPCTSTR)font.c_str());
		GameTitle.SetFont(&m_editFont);
	}
	else
	{
		CFont m_editFont;
		m_editFont.CreatePointFont(180, _T("等线"));
		GameTitle.SetFont(&m_editFont);
	}
	//End GameTitle
}



HBRUSH ChooseWindow::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
