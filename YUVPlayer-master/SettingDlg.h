#pragma once

extern void find_resolution(char* filename, int& fmt_idx, int& width, int& height);

class CYUVPlayerDlg;

// CSettingDlg �Ի���

class CSettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingDlg)

public:
	CSettingDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSettingDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_SETTING };

public:
    void SetParentWnd(CYUVPlayerDlg* pWnd) {m_pParentWnd = pWnd;}
    void SetParametersToParentWnd(int& width, int& height, int& fps, int& fmt, BOOL& loop,int &bitdepth)
    {
        width = m_nWidth;
        height = m_nHeight;
        fps = m_nFps;
        fmt = m_nYuvFormat;
        loop = m_fLoop;
		bitdepth = m_nBitdepth;
    }

    void SetRegistration(CString& strSize, int width, int height, int fpsidx, int fmt, int loop);
    void GetRegistration(CString& strSize, int& width, int& height, int& fpsidx, int& fmt, int& loop);
    BOOL ExistRegistration();

    void ParseFilename(const char* pFilename);

    void UpdateRes();

private:
    CYUVPlayerDlg *m_pParentWnd; // ���ڲ�������
    CString m_strAddedSize;   // �û��Զ���ķֱ���(��ϵͳ���е�)
    int m_nFpsIndex;
    CStringArray m_strArrAddedSize;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedApply();
    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedOk();
    virtual BOOL OnInitDialog();
    CComboBox m_cbFps;
    CComboBox m_cbYuvFormat;
    CComboBox m_cbResolution;
	CComboBox m_cbBitdepth;
    int m_nHeight;
    int m_nWidth;
    int m_nFps;
    int m_nYuvFormat;
    BOOL m_fLoop;
	int m_nBitdepth;
    afx_msg void OnSelchangeCbSize();
    afx_msg void OnSelchangeCbYuvFmt();
    afx_msg void OnSelchangeCbFps();
    afx_msg void OnClickedCkLoop();
    afx_msg void OnChangeEWidth();
    afx_msg void OnChangeEHeight();
    afx_msg void OnBnClickedBtAdd();
    afx_msg void OnBnClickedBtDel();
	afx_msg void OnCbnSelchangeCombo1();
};
