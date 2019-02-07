#pragma once
#include "afxcmn.h"


// CUploadDialog dialog

class CUploadDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CUploadDialog)

public:
	CUploadDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CUploadDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CProgressCtrl m_progressCtrl;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
};
