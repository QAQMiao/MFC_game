// mmDlg.h : ͷ�ļ�
//

#pragma once
#include "Animal.h"
#include "Scene.h"

// CmmDlg �Ի���
class CmmDlg : public CDialog
{
// ����
public:
	int now1,now;
	HBITMAP hBitmap;
	HBITMAP hPerson[800],hAnimal[2800];
	HBITMAP hScene[10];
	HDC hDCBitmap,hDCperson,hDCScene,hDCAnimal;
	miao mm;
	Animal ani[20];
	bool cmp(Scene a, Scene b);
	Scene sc[10];
	CmmDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CmmDlg();

// �Ի�������
	enum { IDD = IDD_MM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton2();
};
