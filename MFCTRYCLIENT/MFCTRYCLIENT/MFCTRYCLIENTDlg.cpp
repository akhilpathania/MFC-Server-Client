
// MFCTRYCLIENTDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCTRYCLIENT.h"
#include "MFCTRYCLIENTDlg.h"
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


// CMFCTRYCLIENTDlg dialog



CMFCTRYCLIENTDlg::CMFCTRYCLIENTDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCTRYCLIENT_DIALOG, pParent)

	
	, m_ip(_T(""))
	, m_port(0)
	, m_downFileName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTRYCLIENTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);



	DDX_Text(pDX, IDC_IP, m_ip);
	DDX_Text(pDX, IDC_PORT, m_port);
	DDX_Control(pDX, IDC_Connect, m_connControl);
	DDX_Text(pDX, IDC_filedown, m_downFileName);
}

BEGIN_MESSAGE_MAP(CMFCTRYCLIENTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Connect, &CMFCTRYCLIENTDlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_Upload, &CMFCTRYCLIENTDlg::OnBnClickedUpload)
	ON_BN_CLICKED(IDC_Send, &CMFCTRYCLIENTDlg::OnBnClickedSend)
	ON_EN_CHANGE(IDC_IP, &CMFCTRYCLIENTDlg::OnEnChangeIp)
	ON_BN_CLICKED(IDC_DwnBtn, &CMFCTRYCLIENTDlg::OnBnClickedDwnbtn)
END_MESSAGE_MAP()


// CMFCTRYCLIENTDlg message handlers

BOOL CMFCTRYCLIENTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//socketprog();


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

void CMFCTRYCLIENTDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCTRYCLIENTDlg::OnPaint()
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
HCURSOR CMFCTRYCLIENTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*void CMFCTRYCLIENTDlg::socketprog()
{

	int Size;
	char *Filesize = new char[1024];

	if (recv(Socket, Filesize, 1024, 0)) // File size
	{
		Size = atoi((const char*)Filesize);
		
	}

	//char *Buffer = new char[Size];

	if (recv(Socket, Buffer, Size, 0)) // File Binary
	{
		FILE *File;
		File = fopen("C:\\Users\\gsc-30285\\Desktop\\proxy.zip", "wb");
		fwrite((const char*)Buffer, 1, Size, File);
		fclose(File);
	}

	getchar();
	closesocket(Socket);
	WSACleanup();
}

*/

void CMFCTRYCLIENTDlg::OnBnClickedConnect()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	const char* ip = m_ip;

	WSAStartup(MAKEWORD(2, 2), &Winsock);    // Start Winsock

	if (LOBYTE(Winsock.wVersion) != 2 || HIBYTE(Winsock.wVersion) != 2)    // Check version
	{
		WSACleanup();
	}

	Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	ZeroMemory(&Addr, sizeof(Addr));    // clear the struct
	Addr.sin_family = AF_INET;    // set the address family
	Addr.sin_addr.s_addr = inet_addr(ip);
	Addr.sin_port = htons(m_port);// htons(6091);    // set the port

	
	if (connect(Socket, (sockaddr*)&Addr, sizeof(Addr)) < 0)
	{
		MessageBox("Connection failed !");
		conn_stat = 0;
	}
	else
	{
		MessageBox("Connection Succesful");
		conn_stat = 1;
	}
	

}


void CMFCTRYCLIENTDlg::OnBnClickedUpload()
{
	// TODO: Add your control notification handler code here
	TCHAR file[] = _T("Zip file (*.zip)|*.zip|Application files (*.exe)|*.exe|Text file (*.txt)|*.txt|Rar file (*.rar)|*.rar|All Files (*.*)|*.*||");
	CFileDialog openfile(TRUE, _T("zip"), _T("*.zip"), OFN_HIDEREADONLY | OFN_FILEMUSTEXIST, file);
	if (openfile.DoModal() == IDOK)
	{
		filefull = openfile.GetPathName();
		counter = 1;
	}
	
}


void CMFCTRYCLIENTDlg::OnBnClickedSend()
{
	if (counter == 1 && conn_stat == 1)
	{
		FILE *File;

		if (counter == 1)
		{
			counter = 0;
			filefull.Replace((CString)"\\", (CString)"\\\\");
		}

		MessageBox((LPCTSTR)filefull);

		//const char* fPath = (char*)(LPWSTR)(filefull.GetBuffer(filefull.GetLength()));


		// TODO: Add your control notification handler code here
		File = fopen(filefull, "rb");
		if (!File)
		{
			MessageBox("Error while readaing the file");
			goto End;
		}


		char *FileName = (char*)(LPCSTR)filefull;
		char *fptr = FileName;
		while (*FileName != '\0')
			FileName++;

		while (*FileName != '\\' && FileName != fptr)
			FileName--;
		if (*FileName == '\\')
			FileName++;

		MessageBox(FileName);

		fseek(File, 0, SEEK_END);
		Size = ftell(File);
		fseek(File, 0, SEEK_SET);

		char* Buffer = new char[Size];

		fread(Buffer, Size, 1, File);

		send(Socket, FileName, strlen(FileName), 0);   //FileName

		char cSize[MAX_PATH];
		sprintf(cSize, "%lu", Size);

		send(Socket, cSize, MAX_PATH, 0); // File size

		int sendreader = 0;

		sendreader = send(Socket, Buffer, Size, 0); // File Binary



													/*FILE *File1;

													File1 = fopen("C:\\Users\\gsc-30285\\Desktop\\tes.jpg", "wb");
													fwrite((const char*)Buffer, 1, Size, File1);
													fclose(File1);
													*/
		free(Buffer);
		fclose(File);

	End:
		closesocket(Socket);
		WSACleanup();
	}
	else
	{
		MessageBox("Please Browse some file To send");
	}
	

	

}




void CMFCTRYCLIENTDlg::OnEnChangeIp()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

}


void CMFCTRYCLIENTDlg::OnBnClickedDwnbtn()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString dwnfile = m_downFileName;
	dwnfile = "http://10.80.41.145/" + dwnfile;
	CString downloadPath = "C:\\Users\\gsc-30285\\Desktop\\" + dwnfile;
	MessageBox(dwnfile);

	//ShellExecute(0, 0, dwnfile, 0, 0, SW_SHOW);
	
	URLDownloadToFile(NULL, dwnfile, downloadPath, 0, NULL);
	
}
