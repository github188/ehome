/********************************************************************
 File: ip_knxapp.h
 Function: communicate with ip_knx device
 Author: Luobihe
 Date: 2015-7-8
********************************************************************/

#ifndef __IP_KNXAPP_H__
#define __IP_KNXAPP_H__

#include <list>
using namespace std;

#include "platcomm.h"


#define RETRY_TIMES 3    //read times

#define CMD_ACK_LEN   8         //device ack length
#define CMD_RES_LEN   14        //length of command response
#define DATA_RES_LEN  14        //length of data response

#define CMD_MODE_WRITE   0     //write device command
#define CMD_MODE_READ    1     //read device command

//block mode
#define CMD_RESPONSE_MODE_NONBLOCK  0
#define CMD_RESPONSE_MODE_BLOCK     1

//for ip_knx device should have a delay between two command
#define IPKNX_CMD_DELAY        200    //ms, 

typedef struct {
    int mode;   //0 -- write, 1 -- read
    char chAddrFirst;
    char chAddrSecond;
    int value;
    int len;
} KNXCMD;

class CIpKnxApp : public CTcpCltAppInterface {
private:
    CEasyTcpClt m_tcpClt;

    int m_iCmdState;
    int m_iBlockMode;
    EasyMutex m_hIpKnxLock;
    EasyMutex m_hIpKnxCltCmdLock;
    EasyMutex m_hIpKnxMonCmdLock;

    list <KNXCMD> m_listClientCmd;   //client cmd list
    list <KNXCMD> m_listMonitorCmd;  //monitor cmd list

    enum {
        CMD_STATE_SENDTO_DEV,
        CMD_STATE_RES_CORRECT,
        CMD_STATE_RES_ERROR
    };


private:
    int getListCltCmd(KNXCMD* p_cmd);
    void addListCltCmd(KNXCMD cmd);

    int getListMonCmd(KNXCMD* p_cmd);
    void addListMonCmd(KNXCMD cmd);

    //check response from knx bus
    int checkCmdRes(const char* szBuf, int iLen);

    //check data from knx bus
    int checkDataRes(const char* szBuf, int iLen, char* szAddr, char* szVal);

    //check data from knx bus
    int checkDataResNew(const char* szBuf, int iLen, char* szAddr, 
        char* szVal, int* p_iHandleSize);

    //set cmd state
    void setCmdState(int iState);
    int getCmdState(void);

    //send write group address to knx device
    int sendWriteCmd(char* szAddr, int value, int len); 

    //send read group address to knx device
    int sendReadCmd(char* szAddr, int len); 

    //send command to knx bus
    int sendCmd(char* szAddr, int value, int len, int mode); 

    //send command to knx bus
    int sendCmd(KNXCMD cmd); 

    //�� knx �豸��ַ��ֵ,���ȴ��豸��Ӧ
    int readGroupAddrNoBlock(char* szAddr, int* p_value, int len); 

    //thread to write cmd to ipknx device
    static void* writeIpKnxFun(void* arg);

public:
    CIpKnxApp(void);
    ~CIpKnxApp(void);

    //��ʼ��������socket, �����豸
    int init(const char* szDevAddr, int port, int iBlockMode = 0);

    //�� knx �豸��ַдֵ,����鷵��
    int writeGroupAddr(char* szAddr, int value, int len);

    //�� knx �豸��ַ��ֵ
    int readGroupAddr(char* szAddr, int* p_value, int len);   

    //monitor group addr by sending read addr cmd
    int monitorGroupAddr(char* szAddr, int len);

    //������ص���������sock��⵽�пɶ�������ʱ�����ص��ú���
    int readHandle(void);
};

#endif


