
// YUVPlayerDlg.h : ͷ�ļ�
//

#pragma once

#include "SettingDlg.h"
#include "afxcmn.h"

#define APP_NAM _T("YUV Player")



#define MAX_URL_LENGTH 256
/*
typedef struct yuv_pic_tag
{
    char* yuv_data[4];
    int   yuv_linesize[4]; //number of bytes per line
} yuv_pic;
*/
// CYUVPlayerDlg �Ի���
class CYUVPlayerDlg : public CDialogEx
{
// ����
public:
	CYUVPlayerDlg(CWnd* pParent = NULL);	// ��׼���캯��
    ~CYUVPlayerDlg();
// �Ի�������
	enum { IDD = IDD_YUVPLAYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
    BOOL m_fInit;
    BOOL m_fShowBlack;

    CSettingDlg* m_pSettingDlg;
    int m_nWidth;
    int m_nHeight;
    int m_nFps;
	int m_nBitdepth;
    int m_nYuvFormat;
    BOOL m_fLoop;

    int m_nStartX[2][11];   // �����϶�����λ��

    CString m_strPathName;  // �ļ�����(����·��)
    char*   m_pbYuvData;    // YUV����
	unsigned char*   m_tempYUV;		//����10bit YUV
    char*   m_pbBmpData;    // RGB����
    UINT    m_nYuvSize; // һ��ͼ���С
    UINT    m_nBmpSize; // BMPͼ�Ĵ�С

    BITMAPFILEHEADER m_bmHeader;
    BITMAPINFO       m_bmInfo;

    CFile m_cFile;
    CWinThread* m_pWinThread;

    INT m_nTotalFrame;   // ��֡�������ļ���С��YUV��С�������
    INT m_nCurrentFrame; // ��ǰ֡����1��ʼ���㣬��seek�ļ�ʱ���Զ���1
    static BOOL m_fPause;
    static BOOL m_fEnd;
    static BOOL m_fPlay;

    // �����ڲ�����
    void Open();
    BOOL IsOpen();
    void Malloc();
    void Read(INT nCurrentFrame);
    void Show();
    void ShowFrameCount(INT nCurrentFrame);

    void ShowOpenedFrame();
    void ShowPicture(BYTE* pbData, int iSize);

    void SetParentParameters(int width, int height, int fps, int fmt, BOOL loop,int bitdepth);

    void ShowSettingWindow();
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
    afx_msg void OnBnClickedButtonSet();
    afx_msg void OnBnClickedButtonOpen();
    afx_msg void OnBnClickedButtonSave();
    afx_msg void OnBnClickedButtonPlay();
    afx_msg LRESULT OnNcHitTest(CPoint point);
    afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);

    afx_msg void OnFileOpen();
    afx_msg void OnFileSave();
    afx_msg void OnFileExit();
    afx_msg void OnPlayingPlay();
    afx_msg void OnPlayingSetting();
    afx_msg void OnPlayingStop();
    afx_msg void OnHelpHelp();
    afx_msg void OnHelpAbout();
    afx_msg void OnROpen();
    afx_msg void OnRSetting();
    afx_msg void OnRExit();
    afx_msg void OnBnClickedButtonStop();
    afx_msg void OnBnClickedButtonPrev();
    afx_msg void OnBnClickedButtonNext();
    afx_msg void OnBnClickedButtonFirst();
    afx_msg void OnBnClickedButtonLast();
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
    afx_msg void OnStnClickedSTest();
    CButton m_bFirstFrame;
    CButton m_bLastFrame;
    CButton m_bNextFrame;
    CButton m_bOpenFile;
    CButton m_bPlay;
    CButton m_bPrevFrame;
    CButton m_bSaveFrame;
    CButton m_bSetting;
    CButton m_bStop;
    afx_msg void OnDropFiles(HDROP hDropInfo);
    afx_msg void OnHelpTransform();
    CSliderCtrl m_slProgress;
    afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
};
