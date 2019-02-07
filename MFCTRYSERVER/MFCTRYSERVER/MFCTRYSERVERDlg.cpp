
// MFCTRYSERVERDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTRYSERVER.h"
#include "MFCTRYSERVERDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCTRYSERVERDlg dialog



CMFCTRYSERVERDlg::CMFCTRYSERVERDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCTRYSERVER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTRYSERVERDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCTRYSERVERDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Server, &CMFCTRYSERVERDlg::OnBnClickedServer)
	ON_BN_CLICKED(IDOK, &CMFCTRYSERVERDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCTRYSERVERDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMFCTRYSERVERDlg message handlers

BOOL CMFCTRYSERVERDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCTRYSERVERDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCTRYSERVERDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCTRYSERVERDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCTRYSERVERDlg::socketprog()
{
	SOCKET Socket, Sub;
	WSADATA Winsock;
	sockaddr_in Addr;
	int Addrlen = sizeof(sockaddr_in);
	char Buffer[256];
	char *Str;
	sockaddr_in IncomingAddress;
	int AddressLen = sizeof(IncomingAddress);

	WSAStartup(MAKEWORD(2, 2), &Winsock);    // Start Winsock

	if (LOBYTE(Winsock.wVersion) != 2 || HIBYTE(Winsock.wVersion) != 2)    // Check version
	{
		WSACleanup();
		CDialogEx::OnCancel();
	}

	Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	ZeroMemory(&Addr, sizeof(Addr));
	Addr.sin_family = AF_INET;
	Addr.sin_port = htons(6091);
	bind(Socket, (sockaddr*)&Addr, sizeof(Addr));

	if (listen(Socket, 1) == SOCKET_ERROR)
	{
		MessageBox("listening error");
		return;
	}
	else
	{
		MessageBox("listening ok");

	}
	
	if (Sub = accept(Socket, (sockaddr*)&IncomingAddress, &AddressLen))
	{
		FILE *File;
		char *Buffer;	
		MessageBox("Receiving file .. ");

		unsigned long Size;
		char *Filesize = new char[1024];
		char *FileNameRead = new char[1024];
		CString FileName, FilePath = "C:\\Users\\gsc-30285\\Desktop\\";
		int len = strlen(FilePath);

		int readr = 0;
		if (readr = recv(Sub, FileNameRead, 1024, 0)) // File size
		{
			FileName = FileNameRead;
			FilePath += FileName;
			FilePath.SetAt((readr + len), '\0');

			/*FILE *fpp = fopen("C:\\Users\\gsc-30285\\Desktop\\log.txt", "w");
			fwrite((const char*)FilePath, readr+len, 1, fpp);
			fclose(fpp);*/
		}


		if (recv(Sub, Filesize, 1024, 0)) // File size
		{
			Size = strtoul(Filesize, NULL, 0);
			//Size = atoi((const char*)Filesize);
			MessageBox("Size Received");
		}


		Buffer = new char[Size];

		
		File = fopen(FilePath, "wb");
		int reader = 0, rea = 0;
		while (rea < Size)
		{
			reader = recv(Sub, Buffer, Size, 0);
			rea = rea + reader;
			if (reader == -1) // File Binary
			{
				MessageBox("Perror Recv");
			}
			else if (reader == 0)
			{
				MessageBox("Connection is Closed");
			}
			else
			{
				fwrite((const char*)Buffer, 1, reader, File);
				memset(Buffer, 0, sizeof(Buffer));
			}

		}
		MessageBox("DATA Received");
		fclose(File);



	End:
		closesocket(Socket);
		
		WSACleanup();
		
	}
}



void CMFCTRYSERVERDlg::OnBnClickedServer()
{
	// TODO: Add your control notification handler code here
	socketprog();
}


void CMFCTRYSERVERDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CMFCTRYSERVERDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
