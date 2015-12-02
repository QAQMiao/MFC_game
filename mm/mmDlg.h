// mmDlg.h : 头文件
//

#pragma once
#include "Animal.h"
#include "Scene.h"

// CmmDlg 对话框
class CmmDlg : public CDialog
{
// 构造
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
	CmmDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CmmDlg();

// 对话框数据
	enum { IDD = IDD_MM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
