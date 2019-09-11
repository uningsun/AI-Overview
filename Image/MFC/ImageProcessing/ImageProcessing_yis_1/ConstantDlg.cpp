// ConstantDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageProcessing_yis_1.h"
#include "ConstantDlg.h"
#include "afxdialogex.h"


// CConstantDlg 대화 상자

IMPLEMENT_DYNAMIC(CConstantDlg, CDialog)

CConstantDlg::CConstantDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG4, pParent)
	, m_Constant(0)
{

}

CConstantDlg::~CConstantDlg()
{
}

void CConstantDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Constant);
	DDV_MinMaxDouble(pDX, m_Constant, 0, 255);
}


BEGIN_MESSAGE_MAP(CConstantDlg, CDialog)
END_MESSAGE_MAP()


// CConstantDlg 메시지 처리기
