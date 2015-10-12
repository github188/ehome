// ehomeclientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ehomeclient.h"
#include "ehomeclientDlg.h"

#include "platcomm.h"
#include "logsys.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif

UIResInfo s_arrUiResInfo[] = {
    {1, IDC_STATIC_1},
    {2, IDC_STATIC_2},
    {3, IDC_STATIC_3},
    {4, IDC_STATIC_4},
    {5, IDC_STATIC_5},

    {6, IDC_STATIC_6},
    {7, IDC_STATIC_7},
    {8, IDC_STATIC_8},
    {9, IDC_STATIC_9},
    {10, IDC_STATIC_10},

    {11, IDC_STATIC_11},
    {12, IDC_STATIC_12},
    {13, IDC_STATIC_13},
    {14, IDC_STATIC_14},
    {15, IDC_STATIC_15},

    {16, IDC_STATIC_16},
    {17, IDC_STATIC_17},
    {18, IDC_STATIC_18},
    {19, IDC_STATIC_19},
    {20, IDC_STATIC_20},
};

// CehomeclientDlg �Ի���




CehomeclientDlg::CehomeclientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CehomeclientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CehomeclientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CehomeclientDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
    ON_BN_CLICKED(IDC_BTN_CONNECT, &CehomeclientDlg::OnBnClickedBtnConnect)
    ON_BN_CLICKED(IDC_BTN_OPEN_1, &CehomeclientDlg::OnBnClickedBtnOpen1)
    ON_BN_CLICKED(IDC_BTN_CLOSE_1, &CehomeclientDlg::OnBnClickedBtnClose1)
    ON_BN_CLICKED(IDC_BTN_OPEN_2, &CehomeclientDlg::OnBnClickedBtnOpen2)
    ON_BN_CLICKED(IDC_BTN_CLOSE_2, &CehomeclientDlg::OnBnClickedBtnClose2)
    ON_BN_CLICKED(IDC_BTN_OPEN_3, &CehomeclientDlg::OnBnClickedBtnOpen3)
    ON_BN_CLICKED(IDC_BTN_CLOSE_3, &CehomeclientDlg::OnBnClickedBtnClose3)
    ON_BN_CLICKED(IDC_BTN_OPEN_4, &CehomeclientDlg::OnBnClickedBtnOpen4)
    ON_BN_CLICKED(IDC_BTN_CLOSE_4, &CehomeclientDlg::OnBnClickedBtnClose4)
    ON_BN_CLICKED(IDC_BTN_OPEN_5, &CehomeclientDlg::OnBnClickedBtnOpen5)
    ON_BN_CLICKED(IDC_BTN_CLOSE_5, &CehomeclientDlg::OnBnClickedBtnClose5)
    ON_BN_CLICKED(IDC_BTN_OPEN_6, &CehomeclientDlg::OnBnClickedBtnOpen6)
    ON_BN_CLICKED(IDC_BTN_CLOSE_6, &CehomeclientDlg::OnBnClickedBtnClose6)
    ON_BN_CLICKED(IDC_BTN_OPEN_7, &CehomeclientDlg::OnBnClickedBtnOpen7)
    ON_BN_CLICKED(IDC_BTN_CLOSE_7, &CehomeclientDlg::OnBnClickedBtnClose7)
    ON_BN_CLICKED(IDC_BTN_OPEN_8, &CehomeclientDlg::OnBnClickedBtnOpen8)
    ON_BN_CLICKED(IDC_BTN_CLOSE_8, &CehomeclientDlg::OnBnClickedBtnClose8)
    ON_BN_CLICKED(IDC_BTN_OPEN_9, &CehomeclientDlg::OnBnClickedBtnOpen9)
    ON_BN_CLICKED(IDC_BTN_CLOSE_9, &CehomeclientDlg::OnBnClickedBtnClose9)
    ON_BN_CLICKED(IDC_BTN_OPEN_10, &CehomeclientDlg::OnBnClickedBtnOpen10)
    ON_BN_CLICKED(IDC_BTN_CLOSE_10, &CehomeclientDlg::OnBnClickedBtnClose10)
    ON_BN_CLICKED(IDC_BTN_OPEN_11, &CehomeclientDlg::OnBnClickedBtnOpen11)
    ON_BN_CLICKED(IDC_BTN_CLOSE_11, &CehomeclientDlg::OnBnClickedBtnClose11)
    ON_BN_CLICKED(IDC_BTN_OPEN_12, &CehomeclientDlg::OnBnClickedBtnOpen12)
    ON_BN_CLICKED(IDC_BTN_OPEN_13, &CehomeclientDlg::OnBnClickedBtnOpen13)
    ON_BN_CLICKED(IDC_BTN_CLOSE_13, &CehomeclientDlg::OnBnClickedBtnClose13)
    ON_BN_CLICKED(IDC_BTN_OPEN_14, &CehomeclientDlg::OnBnClickedBtnOpen14)
    ON_BN_CLICKED(IDC_BTN_CLOSE_14, &CehomeclientDlg::OnBnClickedBtnClose14)
    ON_BN_CLICKED(IDC_BTN_OPEN_15, &CehomeclientDlg::OnBnClickedBtnOpen15)
    ON_BN_CLICKED(IDC_BTN_CLOSE_15, &CehomeclientDlg::OnBnClickedBtnClose15)
    ON_BN_CLICKED(IDC_BTN_OPEN_16, &CehomeclientDlg::OnBnClickedBtnOpen16)
    ON_BN_CLICKED(IDC_BTN_CLOSE_16, &CehomeclientDlg::OnBnClickedBtnClose16)
    ON_BN_CLICKED(IDC_BTN_OPEN_17, &CehomeclientDlg::OnBnClickedBtnOpen17)
    ON_BN_CLICKED(IDC_BTN_CLOSE_17, &CehomeclientDlg::OnBnClickedBtnClose17)
    ON_BN_CLICKED(IDC_BTN_OPEN_18, &CehomeclientDlg::OnBnClickedBtnOpen18)
    ON_BN_CLICKED(IDC_BTN_CLOSE_18, &CehomeclientDlg::OnBnClickedBtnClose18)
    ON_BN_CLICKED(IDC_BTN_OPEN_19, &CehomeclientDlg::OnBnClickedBtnOpen19)
    ON_BN_CLICKED(IDC_BTN_CLOSE_19, &CehomeclientDlg::OnBnClickedBtnClose19)
    ON_BN_CLICKED(IDC_BTN_OPEN_20, &CehomeclientDlg::OnBnClickedBtnOpen20)
    ON_BN_CLICKED(IDC_BTN_CLOSE_20, &CehomeclientDlg::OnBnClickedBtnClose20)
    ON_BN_CLICKED(IDC_BTN_BATOPEN, &CehomeclientDlg::OnBnClickedBtnBatopen)
    ON_BN_CLICKED(IDC_BTN_BATCLOSE, &CehomeclientDlg::OnBnClickedBtnBatclose)
    ON_WM_TIMER()
    ON_MESSAGE(WM_CLIETN_READBACK, OnReadMessage) 
    ON_BN_CLICKED(IDC_BTN_GETJSON, &CehomeclientDlg::OnBnClickedBtnGetjson)
END_MESSAGE_MAP()


// CehomeclientDlg ��Ϣ�������

BOOL CehomeclientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
    //((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1))->SetAddress(127, 0, 0, 1);
    ((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1))->SetAddress(192, 168, 1, 111);

    SetDlgItemText(IDC_EDIT2, "2222");

    initSocket();

    m_ehclt.setWinHandle(this->m_hWnd);

    m_udpListener.setWinHandle(this->m_hWnd);
    m_udpListener.startListenThread();

    //SetTimer(TIMER_READ_STATE, 2000, NULL);

    loginit("cltlog.dat", LOG_DEBUG);

    logout(LOG_DEBUG, "start client", __FILE__, __LINE__);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CehomeclientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CehomeclientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CehomeclientDlg::OnBnClickedBtnConnect()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CString strTemp;
    GetDlgItemText(IDC_BTN_CONNECT, strTemp);
    if (strTemp == "����") {
    //if (m_ehclt.isClosed()) {
        BYTE btAddr[4] = {0};
        ((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1))->GetAddress(btAddr[0], 
            btAddr[1], btAddr[2], btAddr[3]);

        CString strAddr;
        strAddr.Format("%d.%d.%d.%d", btAddr[0], 
            btAddr[1], btAddr[2], btAddr[3]);

        //m_ehclt.init("192.168.1.111", 2222);
        if (m_ehclt.init(strAddr.GetBuffer(), 2222) == 0)
            SetDlgItemText(IDC_BTN_CONNECT, "�Ͽ�");

        SendReadAllDevCmd();
    }
    else {
        m_ehclt.disConnect();        
        SetDlgItemText(IDC_BTN_CONNECT, "����");
    }
}

void CehomeclientDlg::WriteDev(int iDevNo, int iVal)
{
    if (m_ehclt.isClosed()) 
        MessageBox("Not connect to server!");
    else
        m_ehclt.writeDev(iDevNo, iVal);
}

void CehomeclientDlg::GetChecks(void)
{
    m_arrChecks[0] = ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
    m_arrChecks[1] = ((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck();
    m_arrChecks[2] = ((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck();
    m_arrChecks[3] = ((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck();
    m_arrChecks[4] = ((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck();

    m_arrChecks[5] = ((CButton*)GetDlgItem(IDC_CHECK6))->GetCheck();
    m_arrChecks[6] = ((CButton*)GetDlgItem(IDC_CHECK7))->GetCheck();
    m_arrChecks[7] = ((CButton*)GetDlgItem(IDC_CHECK8))->GetCheck();
    m_arrChecks[8] = ((CButton*)GetDlgItem(IDC_CHECK9))->GetCheck();
    m_arrChecks[9] = ((CButton*)GetDlgItem(IDC_CHECK10))->GetCheck();

    m_arrChecks[10] = ((CButton*)GetDlgItem(IDC_CHECK11))->GetCheck();
    m_arrChecks[11] = ((CButton*)GetDlgItem(IDC_CHECK12))->GetCheck();
    m_arrChecks[12] = ((CButton*)GetDlgItem(IDC_CHECK13))->GetCheck();
    m_arrChecks[13] = ((CButton*)GetDlgItem(IDC_CHECK14))->GetCheck();
    m_arrChecks[14] = ((CButton*)GetDlgItem(IDC_CHECK15))->GetCheck();

    m_arrChecks[15] = ((CButton*)GetDlgItem(IDC_CHECK16))->GetCheck();
    m_arrChecks[16] = ((CButton*)GetDlgItem(IDC_CHECK17))->GetCheck();
    m_arrChecks[17] = ((CButton*)GetDlgItem(IDC_CHECK18))->GetCheck();
    m_arrChecks[18] = ((CButton*)GetDlgItem(IDC_CHECK19))->GetCheck();
    m_arrChecks[19] = ((CButton*)GetDlgItem(IDC_CHECK20))->GetCheck();
}

void CehomeclientDlg::OnBnClickedBtnOpen1()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(OFFICE_LAMP1, 1);
}

void CehomeclientDlg::OnBnClickedBtnClose1()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(OFFICE_LAMP1, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen2()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(OFFICE_LAMP2, 1);
}

void CehomeclientDlg::OnBnClickedBtnClose2()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(OFFICE_LAMP2, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen3()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(OFFICE_LAMP3, 1);
}

void CehomeclientDlg::OnBnClickedBtnClose3()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(OFFICE_LAMP3, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen4()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(OFFICE_LAMP4, 1);
}

void CehomeclientDlg::OnBnClickedBtnClose4()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(OFFICE_LAMP4, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen5()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(OFFICE_LAMP5, 1);
}

void CehomeclientDlg::OnBnClickedBtnClose5()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(OFFICE_LAMP5, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen6()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(OFFICE_LAMP6, 1);
}

void CehomeclientDlg::OnBnClickedBtnClose6()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(OFFICE_LAMP6, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen7()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP1, 1);    
}

void CehomeclientDlg::OnBnClickedBtnClose7()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP1, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen8()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP2, 1);
}

void CehomeclientDlg::OnBnClickedBtnClose8()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP2, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen9()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP3, 1);
}

void CehomeclientDlg::OnBnClickedBtnClose9()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP3, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen10()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP4, 1);
}

void CehomeclientDlg::OnBnClickedBtnClose10()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP4, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen11()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP5_1, 1);
}

void CehomeclientDlg::OnBnClickedBtnClose11()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP5_1, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen12()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CString strTemp;
    GetDlgItemText(IDC_EDIT1, strTemp);
    int iVal = atoi(strTemp.GetBuffer());
    WriteDev(EXAMPLE_LAMP5_2, iVal);
}

void CehomeclientDlg::OnBnClickedBtnOpen13()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP6, 1);    
}

void CehomeclientDlg::OnBnClickedBtnClose13()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP6, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen14()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP7, 1);
}

void CehomeclientDlg::OnBnClickedBtnClose14()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP7, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen15()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP8, 1);
}

void CehomeclientDlg::OnBnClickedBtnClose15()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP8, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen16()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP9, 1);
}

void CehomeclientDlg::OnBnClickedBtnClose16()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_LAMP9, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen17()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_CURETAIN1_1, 1);    
}

void CehomeclientDlg::OnBnClickedBtnClose17()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_CURETAIN1_1, 0);
}

void CehomeclientDlg::OnBnClickedBtnOpen18()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_CURETAIN1_2, 1);   
}

void CehomeclientDlg::OnBnClickedBtnClose18()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_CURETAIN1_2, 0);   
}

void CehomeclientDlg::OnBnClickedBtnOpen19()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_CURETAIN2_1, 1);   
}

void CehomeclientDlg::OnBnClickedBtnClose19()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_CURETAIN2_1, 0);   
}

void CehomeclientDlg::OnBnClickedBtnOpen20()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_CURETAIN2_2, 1);   
}

void CehomeclientDlg::OnBnClickedBtnClose20()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    WriteDev(EXAMPLE_CURETAIN2_2, 0);   
}

void CehomeclientDlg::OnBnClickedBtnBatopen()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    GetChecks();

    for (int i = 0; i < 20; i++) {
        if (m_arrChecks[i] && i != EXAMPLE_LAMP5_2) {
            WriteDev(i + 1, 1);
            Sleep(10);            
        }
    }

    Sleep(50);

    for (int i = 0; i < 20; i++) {
        if (m_arrChecks[i] && i != EXAMPLE_LAMP5_2) {
            m_ehclt.readDev(i + 1);
            Sleep(10);
        }
    }    
}

void CehomeclientDlg::OnBnClickedBtnBatclose()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    GetChecks();

    for (int i = 0; i < 20; i++) {
        if (m_arrChecks[i] && i != EXAMPLE_LAMP5_2) {
            WriteDev(i + 1, 0);
            Sleep(1);
        }
    }
    
    Sleep(50);

    for (int i = 0; i < 20; i++) {
        if (m_arrChecks[i] && i != EXAMPLE_LAMP5_2) {
            m_ehclt.readDev(i + 1);
            Sleep(1);
        }
    }    
}

void CehomeclientDlg::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
    switch (nIDEvent) {
        case TIMER_READ_STATE:
            if (!m_ehclt.isClosed()) 
                SendReadAllDevCmd();

            break;

        default:
            break;
    }

    CDialog::OnTimer(nIDEvent);
}

void CehomeclientDlg::SendReadAllDevCmd(void)
{
    for (int i = 0; i < 20; i++) {
        //m_ehclt.sendReadDevCmd(i + 1);
        m_ehclt.readDev(i + 1);
        
        Sleep(1);
    }
}

LRESULT CehomeclientDlg::OnReadMessage(WPARAM wParam, LPARAM lParam)
{
    int iAddr = wParam;
    int iVal = lParam;

    PUIResInfo pUiInfo = GetResInfoFromID(iAddr);
    if (!pUiInfo)
        return -1;

    if (iAddr == EXAMPLE_LAMP5_2) {
        CString strTemp;
        strTemp.Format("%d", iVal);
        SetDlgItemText(pUiInfo->iIdcStateId, strTemp);
        return 0;
    }

    if (iVal) 
        SetDlgItemText(pUiInfo->iIdcStateId, "ON");
    else
        SetDlgItemText(pUiInfo->iIdcStateId, "OFF");

    return 0;
}

PUIResInfo CehomeclientDlg::GetResInfoFromID(int iID)
{
    for (int i = 0; i < sizeof(s_arrUiResInfo) / sizeof(UIResInfo); i++)
        if (s_arrUiResInfo[i].iDevId == iID)
            return &s_arrUiResInfo[i];

    return NULL;
}

void CehomeclientDlg::OnBnClickedBtnGetjson()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    if (m_ehclt.isClosed()) 
        MessageBox("Not connect to server!");
    else {
        char szRBuf[10240] = {0};
        m_ehclt.getJsonFile(szRBuf, 10240);

        MessageBox(szRBuf);
    }
}
