// ehomeclient.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CehomeclientApp:
// �йش����ʵ�֣������ ehomeclient.cpp
//

class CehomeclientApp : public CWinApp
{
public:
	CehomeclientApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CehomeclientApp theApp;