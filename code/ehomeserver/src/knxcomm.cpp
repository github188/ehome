/********************************************************************
 File: knxcomm.cpp
 Function: ���� knx ����ͨ�ŵĽӿ� 
 Author: Luobihe
 Date: 2015-7-15
*********************************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "knxcomm.h"
#include "platcomm.h"

/*-------------------------------------------------------------------
 Function: parseGroupAddr(szAddr, p_chFirst, p_chSecond)
 Purpose: ���� knx ���ַ�������� 10/1/31 �����ַ������2�ֽڵ����ݣ�
          ��һ�ֽڱ��� 10/1 ��Ϣ��
             ���淽ʽΪ�� 0-2λ����1�� 3-6λ����10��
          �ڶ��ֽڱ��� 31 ��Ϣ��
 Parameters: szAddr -- [IN], �ַ���ʽ�����ַ
             p_chFirst -- [OUT], ת����ĵ�һ�ֽ�
             p_chSecond -- [OUT], ת����ĵڶ��ֽ�
 return: 0 --  �ɹ�
         -1 -- ʧ��
-------------------------------------------------------------------*/
int parseGroupAddr(const char* szAddr, char* p_chFirst, char* p_chSecond)
{
    char szTemp[16] = {0};
    char* pStart = NULL;
    char* pEnd = NULL;
    int num1 = 0, num2 = 0, num3 = 0;

    if (!szAddr)
        return -1;

    strcpy(szTemp, szAddr);

    //find num1
    pStart = szTemp;
    pEnd = strchr(pStart, '/');
    if (!pEnd)
        return -1;

    *pEnd = 0;
    pEnd++;

    if (!checkStrIsInteger(pStart))
        return -1;
    num1 = atoi(pStart);
    if (num1 >= 16)
        return -1;

    //find num2
    pStart = pEnd;
    pEnd = strchr(pStart, '/');
    if (!pEnd)
        return -1;

    *pEnd = 0;
    pEnd++;

    if (!checkStrIsInteger(pStart))
        return -1;
    num2 = atoi(pStart);
    if (num2 >= 8)
        return -1;

    //find num3
    pStart = pEnd;    
    if (!checkStrIsInteger(pStart))
        return -1;
    num3 = atoi(pStart);
    if (num3 > 255)
        return -1;

    //transfer to output
    *p_chFirst = (char)num2 + (num1 << 3);
    *p_chSecond = (char)num3;    

    return 0;
}

/*-------------------------------------------------------------------
 Function: generateGroupAddr(chFirst, chSecond, szAddr)
 Purpose: ��knx�ֽڵ�ַ���� knx ���ַ����2�ֽڵ�����
          �������� 10/1/31 �����ַ
          ��һ�ֽ�: 3-6 λ�������� 10��0-2 λ�������� 1
          �ڶ��ֽ�: �������� 31
 Parameters: chFirst -- [IN], ��һ�ֽ�
             chSecond -- [IN], �ڶ��ֽ�
             szAddr -- [OUT], ת��������ַ
 return: 0 --  �ɹ�
         -1 -- ʧ��
-------------------------------------------------------------------*/
int generateGroupAddr(unsigned char chFirst, 
                      unsigned char chSecond, 
                      char* szAddr)
{
    if (chFirst & (1 << 7))
        return -1;
    
    sprintf(szAddr, "%d/%d/%d", chFirst >> 3, chFirst & 7, chSecond);

    return 0;
}