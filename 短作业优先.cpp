#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct process
{

	//进程名
	char name;
	//进程需要服务的时间
	int setime;
	//进程到达时间
	int arrtime;

};

// daunzuoyeyouxian 服务算法
int main()
{
	//假设系统中有 4 个作业
	struct process process_alr[4];

	// 输入所有的进程信息
	for (int i = 0; i < 4; i++) 
    {
		printf("请输入各进程名、到达时间、需要服务的时间（空格分隔）：\n");
		scanf("%c%d%d", &process_alr[i].name, &process_alr[i].arrtime, &process_alr[i].setime);
	}

    // 当前的时间
    int now = 0; 
    // 总的等待时间
    double waittime = 0; 
    // 总的周转时间
    double surtime = 0; 
    // 剩余服务时间
    int remiant[4]; 

    for (int i = 0; i < 4; i++) 
    {
        remiant[i] = process_alr[i].setime; // 初始化剩余服务时间
    }
    int prfin[4] = { 0 }; // 标记已处理的进程
    int countpr = 0; // 已处理进程数
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
        { // 所有进程都未到达或者剩余服务时间均大于当前最短剩余服务时间
            now++;
        }
        else 
        {
            // 计算等待时间
            waittime += now - process_alr[flag].arrtime; 

            // 更新当前时间
            now += remiant[flag]; 

            // 计算周转时间
            surtime += now - process_alr[flag].arrtime; 

            remiant[flag] = 0;

            prfin[flag] = 1;

            count++;

        }
    }

    // 输出结果
    double owtime = waittime / 4;
    double ortime = surtime / 4;
    printf("平均等待时间：%.2f\n", owtime);
    printf("平均周转时间：%.2f\n", ortime);
    printf("平均带权周转时间：%.2f\n", ortime / process_alr[3].setime);

    return 0;





}