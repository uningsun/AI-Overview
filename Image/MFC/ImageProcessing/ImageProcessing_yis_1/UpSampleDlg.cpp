﻿// UpSampleDlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "ImageProcessing_yis_1.h"
#include "UpSampleDlg.h"
#include "afxdialogex.h"


// CUpSampleDlg 대화 상자

IMPLEMENT_DYNAMIC(CUpSampleDlg, CDialog)

CUpSampleDlg::CUpSampleDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, m_UpSampleRate(0)
{

}

CUpSampleDlg::~CUpSampleDlg()
{
}

void CUpSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_UpSampleRate);
}


BEGIN_MESSAGE_MAP(CUpSampleDlg, CDialog)
END_MESSAGE_MAP()


// CUpSampleDlg 메시지 처리기
