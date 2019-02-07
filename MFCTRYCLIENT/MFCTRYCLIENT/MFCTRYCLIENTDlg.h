
// MFCTRYCLIENTDlg.h : header file
//

#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>
#include "UploadDialog.h"
#include "afxwin.h"
#include <fstream>

// CMFCTRYCLIENTDlg dialog
class CMFCTRYCLIENTDlg : public CDialogEx
{
// Construction
public:
	CMFCTRYCLIENTDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTRYCLIENT_DIALOG };
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
	DECLARE_MESSAGE_MAP()
	//void socketprog();
public:
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedUpload();
	SOCKET Socket, Sub;
	WSADATA Winsock;
	sockaddr_in Addr;
	int Addrlen = sizeof(sockaddr_in);
	char Buffer[256];
	char *Str;
	sockaddr_in IncomingAddress;
	int AddressLen = sizeof(IncomingAddress);
	afx_msg void OnBnClickedSend();
	CString filefull;
	int counter = 0;
	unsigned long Size;
	CString m_ip;
	UINT m_port;

	CButton m_connControl;
	afx_msg void OnEnChangeIp();
	int conn_stat = 0;
	CString m_downFileName;
	afx_msg void OnBnClickedDwnbtn();
};
