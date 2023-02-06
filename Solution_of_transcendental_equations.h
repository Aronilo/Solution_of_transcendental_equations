
// Solution_of_transcendental_equations.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CSolutionoftranscendentalequationsApp:
// Сведения о реализации этого класса: Solution_of_transcendental_equations.cpp
//

class CSolutionoftranscendentalequationsApp : public CWinApp
{
public:
	CSolutionoftranscendentalequationsApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CSolutionoftranscendentalequationsApp theApp;
