/********************************************************************
 File: knxcomm.h
 Function: ���� knx ����ͨ�ŵĽӿ� 
 Author: Luobihe
 Date: 2015-7-15
*********************************************************************/

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
int parseGroupAddr(const char* szAddr, char* p_chFirst, char* p_chSecond);

/*-------------------------------------------------------------------
 Function: generateGroupAddr(chFirst, chSecond, szAddr)
 Purpose: ��knx�ֽڵ�ַ���� knx ���ַ����2�ֽڵ�����
          �������� 10/1/31 �����ַ
          ��һ�ֽ�: 3-6λ�������� 10��0-2λ��������1
          �ڶ��ֽ�: �������� 31
 Parameters: chFirst -- [IN], ��һ�ֽ�
             chSecond -- [IN], �ڶ��ֽ�
             szAddr -- [OUT], ת��������ַ
 return: 0 --  �ɹ�
         -1 -- ʧ��
-------------------------------------------------------------------*/
int generateGroupAddr(unsigned char chFirst, unsigned char chSecond, char* szAddr);