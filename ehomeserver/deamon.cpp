/*

#include <stdio.h>   
#include <unistd.h>   
#include <sys/types.h>   
#include <sys/stat.h>   
#include <fcntl.h>  


//��������   
#define NAME "AlarmInterface -qws"   

//���ҽ����г�������   
#define NAME_FIND "AlarmInterface"   

//���Ŀ¼   
#define DIR_OUT_FILE "/rf/out"   

//Ҫ���еĳ���   
#define RUN_NAME "DuiJiang &"   


//#define DIR_OUT_FILE "/rf/out"   
//#define NAME "gnome-keyring"   
//#define NAME_FIND "gnome"   
//#define DIR_OUT_FILE "/root/test/out"   

int daemon(int nochdir,int noclose)  
{ 
    pid_t pid; 
    
    //��init���̳�Ϊ�²������̵ĸ�����
    pid = fork();
    
    //�����������ʧ��
    if (pid < 0) {
        perror("fork");
        return -1;
    }
    
    //�������˳����� 
    if (pid != 0) {
        exit(0);
    }
    
    //�����µĻỰ
    pid = setsid();
    if (pid < -1) { 
        perror("set sid");
        return -1;
    }
    
    //���ĵ�ǰ����Ŀ¼,������Ŀ¼�޸ĳɸ�Ŀ¼
    if (!nochdir)
    {
        chdir("/"); 
    }
    
    //�ر��ļ������������ض����׼���룬����ϴ������
    //����׼��������ض��򵽿��豸
    if (!noclose)
    {
        int fd;
        fd = open("/dev/null",O_RDWR,0);
        if (fd != -1)
        { 
            dup2(fd,STDIN_FILENO);
            dup2(fd,STDOUT_FILENO);
            dup2(fd,STDERR_FILENO);
            if (fd > 2)
            {
                close(fd);
            }
        }
    }
    
    //�����ػ����̵��ļ�Ȩ�޴�������
    umask(0027);
    
    return 0; 
}  

//�Ƿ���ƥ����ַ������򷵻�1��û�з���0   
//src:Դ�ַ���   
//dst��Ŀ���ַ���   
//len:Դ�ַ������Ƚϵĳ���   
int match(char *src,char *dst,int len)  
{  
    int i = 0;  
    int j = 0;  
    int size_dst = 0;  
  
    //���Ŀ���ַ����ĳ���   
    size_dst = strlen(dst);  
    //���Ŀ���ַ����ĳ��ȴ���len������ʧ��   
    if (size_dst > len)  
    {  
        return 0;  
    }     
    //��ʼ�Ƚ�   
96.    for (i = 0;i < len;i++)  
97.    {  
98.        for (j = 0;j < size_dst;j++)  
99.        {  
100.            if (src[i + j] != dst[j])  
101.            {  
102.                break;  
103.            }  
104.        }  
105.        if (j == size_dst)  
106.        {  
107.            return 1;  
108.        }  
109.    }  
110.  
111.    return 0;  
112.}  
113.  
114.int main(int argc,char *argv[])  
115.{  
116.    int fd = 0;  
117.    char buf[100];  
118.  
119.    //�����ػ�����   
120.    daemon(0,0);  
121.  
122.    while (1)  
123.    {  
124.        //����־   
125.        openlog(argv[0],LOG_CONS|LOG_PID,LOG_USER);  
126.          
127.        //�鿴�����Ƿ�����   
128.        //�½�����ļ�   
129.        system("touch "DIR_OUT_FILE);  
130.        //��ó���ID   
131.        system("ps -w|grep "NAME_FIND" >> "DIR_OUT_FILE);  
132.        //������ļ�   
133.        fd = open(DIR_OUT_FILE,O_CREAT|O_RDONLY,0777);  
134.        //��ջ���   
135.        memset(buf,0,100);  
136.        //��ȡȫ��   
137.        read(fd,buf,100);  
138.        //�ж��Ƿ��г����ļ�����   
139.        if (match(buf,NAME,90))  
140.        {  
141.            syslog(LOG_INFO,"jdh success!!!!!!!!!!");  
142.        }  
143.        else  
144.        {  
145.            syslog(LOG_INFO,"jdh fail!!!!!!!!!!");  
146.            //���г���   
147.            system(RUN_NAME);  
148.        }  
149.  
150.        //����   
151.        sleep(5);  
152.        //ɾ������ļ�   
153.        system("rm "DIR_OUT_FILE);  
154.          
155.        //����   
156.        sleep(55);  
157.    }  
158.  
159.    //�ر���־   
160.    closelog();  
161.  
162.    return 0;  
163.}  
*/