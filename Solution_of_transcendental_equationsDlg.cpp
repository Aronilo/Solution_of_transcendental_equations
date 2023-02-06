
// Solution_of_transcendental_equationsDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Solution_of_transcendental_equations.h"
#include "Solution_of_transcendental_equationsDlg.h"
#include "afxdialogex.h"
#include "Method.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// Диалоговое окно CSolutionoftranscendentalequationsDlg



CSolutionoftranscendentalequationsDlg::CSolutionoftranscendentalequationsDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SOLUTION_OF_TRANSCENDENTAL_EQUATIONS_DIALOG, pParent)
	, Valuel(_T(""))
	, Value1(_T(""))
	, Value2(_T(""))
	, ValueError(_T(""))
	, ValueX0(_T(""))
	, FunctionEntry(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSolutionoftranscendentalequationsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Valuel);
	DDX_Text(pDX, IDC_EDIT2, Value1);
	DDX_Text(pDX, IDC_EDIT3, Value2);
	DDX_Text(pDX, IDC_EDIT5, ValueError);
	DDX_Text(pDX, IDC_EDIT4, ValueX0);
	DDX_Text(pDX, IDC_EDIT_FUNCTION, FunctionEntry);
}

BEGIN_MESSAGE_MAP(CSolutionoftranscendentalequationsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE, &CSolutionoftranscendentalequationsDlg::OnBnClickedButtonCalculate)
	ON_BN_CLICKED(IDC_RADIO_HALF, &CSolutionoftranscendentalequationsDlg::OnBnClickedRadioHalf)
	ON_BN_CLICKED(IDC_RADIO_CHORD, &CSolutionoftranscendentalequationsDlg::OnBnClickedRadioChord)
	ON_BN_CLICKED(IDC_RADIO_NEWTON, &CSolutionoftranscendentalequationsDlg::OnBnClickedRadioNewton)
END_MESSAGE_MAP()


// Обработчики сообщений CSolutionoftranscendentalequationsDlg

BOOL CSolutionoftranscendentalequationsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	FunctionEntry = L"exp(-x) - 2 * sqrt(x)";
	UpdateData(FALSE);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CSolutionoftranscendentalequationsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CSolutionoftranscendentalequationsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CSolutionoftranscendentalequationsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSolutionoftranscendentalequationsDlg::OnBnClickedButtonCalculate()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
	double one = atof(_bstr_t(Value1.GetString())),
		two = atof(_bstr_t(Value2.GetString())),
		error = atof(_bstr_t(ValueError.GetString())),
		half = atof(_bstr_t(ValueX0.GetString()));

	double result;
	if (RdBnMethod == 0) {
		result = Method::method_half(Method::f, one, two, error);
	}
	else if (RdBnMethod == 1) {
		result = Method::chord_method(Method::f, one, two, error);
	} else if (RdBnMethod == 2) {
		result = Method::method_newton(Method::f,one,two, error);
	}

	Valuel.Format(L"%lf", result);



	UpdateData(FALSE);
}


void CSolutionoftranscendentalequationsDlg::OnBnClickedRadioHalf()
{
	// TODO: добавьте свой код обработчика уведомлений
	RdBnMethod = 0;
}


void CSolutionoftranscendentalequationsDlg::OnBnClickedRadioChord()
{
	// TODO: добавьте свой код обработчика уведомлений
	RdBnMethod = 1;
}


void CSolutionoftranscendentalequationsDlg::OnBnClickedRadioNewton()
{
	// TODO: добавьте свой код обработчика уведомлений
	RdBnMethod = 2;
}
