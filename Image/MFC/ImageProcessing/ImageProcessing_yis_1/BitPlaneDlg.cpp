// BitPlaneDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageProcessing_yis_1.h"
#include "BitPlaneDlg.h"
#include "afxdialogex.h"


// CBitPlaneDlg 대화 상자

IMPLEMENT_DYNAMIC(CBitPlaneDlg, CDialogEx)

CBitPlaneDlg::CBitPlaneDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
	, m_BitNum(0)
{

}

CBitPlaneDlg::~CBitPlaneDlg()
{
}

void CBitPlaneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_BitNum);
	DDX_Text(pDX, IDC_EDIT1, m_BitNum);
}


BEGIN_MESSAGE_MAP(CBitPlaneDlg, CDialogEx)
END_MESSAGE_MAP()


// CBitPlaneDlg 메시지 처리기
