#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct process
{

	//������
	char name;
	//������Ҫ�����ʱ��
	int setime;
	//���̵���ʱ��
	int arrtime;

};

// �����ȷ����㷨
int main()
{
	//����ϵͳ���� 4 ����ҵ
	struct process process_alr[4]; 

	// �������еĽ�����Ϣ
	for (int i = 0; i < 4; i++) 
    {
		printf("�������������������ʱ�䡢��Ҫ�����ʱ�䣨�ո�ָ�����\n");
		scanf("%c%d%d", &process_alr[i].name, &process_alr[i].arrtime, &process_alr[i].setime);
	}

    // ��ǰ��ʱ��
    int now = 0; 
    //�ܵĵȴ�ʱ��
    double waittime = 0; 
    //�ܵ���תʱ��
    double surtime = 0;

    for (int i = 0; i < 4; i++) 
    {
        if (now < process_alr[i].arrtime) 
        {
            // ���µ�ǰʱ��
            now = process_alr[i].arrtime; 
        }
        // �ȴ�ʱ��
        waittime += now - process_alr[i].arrtime; 
        // ���µ�ǰʱ��
        now += process_alr[i].setime; 
        // ��תʱ��
        surtime += now - process_alr[i].arrtime; 
    }

    // ������
    double owtime = waittime / 4;
    double ortime = surtime / 4;
    printf("ƽ���ȴ�ʱ�䣺%.2f\n", owtime);
    printf("ƽ����תʱ�䣺%.2f\n", ortime);
    printf("ƽ����Ȩ��תʱ�䣺%.2f\n", ortime / process_alr[3].setime);

    return 0;


}