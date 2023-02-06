
// Solution_of_transcendental_equationsDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CSolutionoftranscendentalequationsDlg
class CSolutionoftranscendentalequationsDlg : public CDialogEx
{
// Создание
public:
	CSolutionoftranscendentalequationsDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SOLUTION_OF_TRANSCENDENTAL_EQUATIONS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString Valuel;
	CString Value1;
	CString Value2;
	CString ValueError;
	CString ValueX0;
	afx_msg void OnBnClickedButtonCalculate();
	int RdBnMethod;
	afx_msg void OnBnClickedRadioHalf();
	afx_msg void OnBnClickedRadioChord();
	afx_msg void OnBnClickedRadioNewton();
	CString FunctionEntry;
};
