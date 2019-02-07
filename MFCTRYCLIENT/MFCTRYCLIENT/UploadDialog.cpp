// UploadDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTRYCLIENT.h"
#include "UploadDialog.h"
#include "afxdialogex.h"



// CUploadDialog dialog

IMPLEMENT_DYNAMIC(CUploadDialog, CDialogEx)

CUploadDialog::CUploadDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CUploadDialog::~CUploadDialog()
{
}

void CUploadDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_progressCtrl);
}


BEGIN_MESSAGE_MAP(CUploadDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CUploadDialog::OnBnClickedButton1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CUploadDialog::OnNMCustomdrawProgress1)
END_MESSAGE_MAP()


// CUploadDialog message handlers


BOOL CUploadDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	
	m_progressCtrl.SetScrollRange(0, 15, TRUE);
	m_progressCtrl.SetStep(50);
	m_progressCtrl.StepIt();
	m_progressCtrl.SetStep(50);
	m_progressCtrl.StepIt();
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CUploadDialog::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CUploadDialog::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{

}
