// ChooseWindow.cpp: 实现文件
//

#include "pch.h"
#include "TouhoProject Demo 1.3 Alpha.h"
#include "ChooseWindow.h"
#include "afxdialogex.h"


// ChooseWindow 对话框

IMPLEMENT_DYNAMIC(ChooseWindow, CDialog)

ChooseWindow::ChooseWindow(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

ChooseWindow::~ChooseWindow()
{
}

void ChooseWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ChooseWindow, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO1, &ChooseWindow::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// ChooseWindow 消息处理程序


void ChooseWindow::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}
