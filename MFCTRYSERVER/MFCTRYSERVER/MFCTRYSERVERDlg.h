
// MFCTRYSERVERDlg.h : header file
//

#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>
#include <string.h>

// CMFCTRYSERVERDlg dialog
class CMFCTRYSERVERDlg : public CDialogEx
{
// Construction
public:
	CMFCTRYSERVERDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTRYSERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void socketprog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedServer();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
