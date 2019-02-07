// UploadDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MFCClient.h"
#include "UploadDialog.h"
#include "afxdialogex.h"


// CUploadDialog dialog

IMPLEMENT_DYNAMIC(CUploadDialog, CDialogEx)

CUploadDialog::CUploadDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_UPLOAD, pParent)
	, m_status(_T(""))
{
	
}

CUploadDialog::~CUploadDialog()
{
}

void CUploadDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_progBarCtrl);
	
}


BEGIN_MESSAGE_MAP(CUploadDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CUploadDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CUploadDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// CUploadDialog message handlers


void CUploadDialog::OnNMCustomdrawProgress1(NMHDR * pNMHDR, LRESULT * pResult)
{
	
}

BOOL CUploadDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	m_progBarCtrl.SetScrollRange(0, 100, TRUE);
	m_progBarCtrl.SetState(0);
	m_progBarCtrl.SetStep(100);
	m_progBarCtrl.StepIt();
	
	
	
	// TODO:  Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void CUploadDialog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CUploadDialog::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
