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
	enum { IDD = IDD_UPLOAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult);
	CProgressCtrl m_progBarCtrl;
	virtual BOOL OnInitDialog();
	CString m_status;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
