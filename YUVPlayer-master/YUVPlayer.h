
// YUVPlayer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CYUVPlayerApp:
// �йش����ʵ�֣������ YUVPlayer.cpp
//

class CYUVPlayerApp : public CWinApp
{
public:
	CYUVPlayerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
    afx_msg void OnHelpAbout();

    ULONG_PTR m_gdiplusToken;
    virtual int ExitInstance();
};

extern CYUVPlayerApp theApp;