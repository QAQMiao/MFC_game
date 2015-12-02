// mmDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mm.h"
#include "mmDlg.h"
#include "algorithm"
#include "vector"

using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int num;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CmmDlg �Ի���




CmmDlg::CmmDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CmmDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	now = 0;
}
CmmDlg::~CmmDlg() {
	DeleteDC(hDCBitmap);
	DeleteDC(hDCperson);
	DeleteDC(hDCScene);
	DeleteObject(hBitmap);
	DeleteObject(hPerson);
	DeleteObject(hScene);
	for (int i = 0; i < 800; i++)
		DeleteObject(hPerson[i]);
	for (int i = 0; i < 10; ++i)
		DeleteObject(hScene[i]);
}
void CmmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmmDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CmmDlg::OnBnClickedButton1)
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDC_BUTTON2, &CmmDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CmmDlg ��Ϣ�������

BOOL CmmDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CmmDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CmmDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CmmDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CmmDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	SelectObject(hDCBitmap, hBitmap);
	DIBSECTION ds;
	BITMAPINFOHEADER &bm = ds.dsBmih;
	DIBSECTION ds1;
	BITMAPINFOHEADER &bm1 = ds1.dsBmih;
	GetObject(hBitmap, sizeof(ds), &ds);
	int iWidth = bm.biWidth;
	int iHeight = bm.biHeight;
	BitBlt(dc.m_hDC, 0, 0, iWidth, iHeight, hDCBitmap, 0, 0, SRCCOPY);
	int iWidth1, iHeight1;

	if (mm.getState() == 0)
	{
		if (mm.getPreState() && mm.cc)
		{
			now = (mm.getPreState() - 1) * 5;
			mm.cc = false;
		}
		else
		{
			now = (now + 1) % 5;
			now += (mm.getPreState() - 1) * 5;
		}
	}
	else if (mm.getPreState() == mm.getState())
	{
		mm.cc = true;
		now = (now + 1) % 10;
		now += mm.getState() * 10 + 30;
	}
	else
	{
		mm.cc = true;
		now = mm.getState() * 10 + 30;
		mm.setPreState(mm.getState());
	}
	for (int i = 0; i < num; ++i)
	{
		if (ani[i].getState() == 0)
		{
			if (ani[i].getPreState() && ani[i].cc)
			{
				now1 = (ani[i].getPreState() - 1) * 5;
				ani[i].cc = false;
			}
			else
			{
				now1 = (now1 + 1) % 5;
				now1 += (ani[i].getPreState() - 1) * 5;
			}
		}
		else if (ani[i].getPreState() == ani[i].getState())
		{
			ani[i].cc = true;
			now1 = (now1 + 1) % 10;
			now1 += ani[i].getState() * 10 + 30;
		}
		else
		{
			ani[i].cc = true;
			now1 = ani[i].getState() * 10 + 30;
			ani[i].setPreState(ani[i].getState());
		}
		ani[i].move();
	}
	GetObject(hPerson[now], sizeof(ds), &ds);
	int iWidth1 = bm.biWidth;
	int iHeight1 = bm.biHeight;
	mm.setSize(iWidth1, iHeight1);

	vector<Object> vec;
	vec.push_back(mm);
	mm.move();
	mm.setIndex(now);
	for (int i = 0; i < 8; ++i)
		vec.push_back(sc[i]);
	for (int i = 0; i < num; ++i)
		vec.push_back(ani[i]);
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i].getType() == 1)
		{
			SelectObject(hDCperson, hPerson[now]);
			GetObject(hPerson[now], sizeof(ds1), &ds1);
		}
		else if (vec[i].getType() == 2)
		{
			SelectObject(hDCScene, hScene[vec[i].getIndex()]);
			GetObject(hScene[vec[i].getIndex()], sizeof(ds1), &ds1);
		}
		else
		{
			SelectObject(hDCAnimal, hAnimal[vec[i].getIndex()]);
			GetObject(hAnimal[vec[i].getIndex()], sizeof(ds1), &ds1);
		}
		iWidth1 = bm1.biWidth;
		iHeight1 = bm1.biHeight;
		TransparentBlt(dc.m_hDC, vec[i].getX(), vec[i].getY(), min(640 - vec[i].getX(), iWidth1), iHeight1, hDCScene, 0, 0, min(640 - vec[i].getX(), iWidth1), iHeight1, RGB(255, 255, 255));
	}
	
	CDialog::OnTimer(nIDEvent);
}

void CmmDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CClientDC dc(this);
	hBitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(), "ͼƬ/����A.BMP", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hDCBitmap = CreateCompatibleDC(dc);
	hDCperson = CreateCompatibleDC(dc);
	for (int i = 0; i < 800; ++i)
	{
		CString name = "ͼƬ/��/c";
		char num[10];
		sprintf(num, "%05d", i);
		name += num;
		name += ".bmp";
		hPerson[i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(), name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		sc[i].setIndex(i);
	}
	SetTimer(0, 50, NULL);
}

void CmmDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	mm.setDes(point.x, point.y);
	/*char sOut[128] = {0};
	sprintf(sOut,"%d %d",point.x,point.y);
	MessageBox(sOut,"",MB_OK);*/
	CDialog::OnLButtonDblClk(nFlags, point);
}


void CmmDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CClientDC dc(this);
	hBitmap = (HBITMAP)LoadImage(AfxGetInstanceHandle(), "ͼƬ/����A.BMP", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	hDCBitmap = CreateCompatibleDC(dc);
	hDCperson = CreateCompatibleDC(dc);
	hDCScene = CreateCompatibleDC(dc);

	srand(time(NULL));

	for (int i = 0; i < 200; ++i)
	{
		CString name = "ͼƬ/��/c";
		char num[10];
		sprintf(num, "%05d", i);
		name += num;
		name += ".bmp";
		hPerson[i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(), name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	}
	int cnt;
	for (int i = 0; i < 8; ++i)
	{
		CString name = "ͼƬ/��/c";
		char num[10];
		cnt = rand() % 96;
		sprintf(num, "%05d", cnt);
		name += num;
		name += ".bmp";
		hScene[i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(), name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
		sc[i].changePo();
	}
	for (int i = 0; i < 2800; ++i)
	{
		CString name = "ͼƬ/��/c";
		char num[10];
		sprintf(num, "%05d", i);
		name += num;
		name += ".bmp";
		hAnimal[i] = (HBITMAP)LoadImage(AfxGetInstanceHandle(), name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	}
	num = rand() % 20;
	for (int i = 0; i < num; ++i)
	{
		ani[i].setIndex(rand() % 7);
	}
	SetTimer(0, 50, NULL);
}
