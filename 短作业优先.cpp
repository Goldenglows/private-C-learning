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

// daunzuoyeyouxian �����㷨
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
    // �ܵĵȴ�ʱ��
    double waittime = 0; 
    // �ܵ���תʱ��
    double surtime = 0; 
    // ʣ�����ʱ��
    int remiant[4]; 

    for (int i = 0; i < 4; i++) 
    {
        remiant[i] = process_alr[i].setime; // ��ʼ��ʣ�����ʱ��
    }
    int prfin[4] = { 0 }; // ����Ѵ���Ľ���
    int countpr = 0; // �Ѵ��������
    while (countpr < 4) 
    {
        int flag = -1;
        int count = 10000;
        for (int i = 0; i < 4; i++) 
        {
            if (prfin[i] == 0 && now >= process_alr[i].arrtime && remiant[i] < count) 
            {
                flag = i;
                count = remiant[i];
            }
        }
        if (flag == -1) 
        { // ���н��̶�δ�������ʣ�����ʱ������ڵ�ǰ���ʣ�����ʱ��
            now++;
        }
        else 
        {
            // ����ȴ�ʱ��
            waittime += now - process_alr[flag].arrtime; 

            // ���µ�ǰʱ��
            now += remiant[flag]; 

            // ������תʱ��
            surtime += now - process_alr[flag].arrtime; 

            remiant[flag] = 0;

            prfin[flag] = 1;

            count++;

        }
    }

    // ������
    double owtime = waittime / 4;
    double ortime = surtime / 4;
    printf("ƽ���ȴ�ʱ�䣺%.2f\n", owtime);
    printf("ƽ����תʱ�䣺%.2f\n", ortime);
    printf("ƽ����Ȩ��תʱ�䣺%.2f\n", ortime / process_alr[3].setime);

    return 0;





}