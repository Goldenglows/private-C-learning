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

// 时间片轮转算法
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
    int remaint[4];

    for (int i = 0; i < 4; i++) 
    {
        // 剩余服务时间
        remaint[i] = process_alr[i].setime;
    }
    // 已处理的进程记录
    int prfin[4] = { 0 }; 
    // 已处理进程计数器
    int count = 0; 
    // 时间片
    int timepian = 1;
    while (count < 4) {
        for (int i = 0; i < 4; i++) 
        {

            if (remaint[i] > 0 && now >= process_alr[i].arrtime) 
            {
                // 进程已完成
                if (remaint[i] <= timepian) 
                { 
                    // 计算等待时间
                    waittime += now - process_alr[i].arrtime - remaint[i]; 

                    // 更新当前时间
                    now += remaint[i];

                    // 计算周转时间
                    surtime += now - process_alr[i].arrtime; 
                    remaint[i] = 0;
                    prfin[i] = 1;
                    count++;
                }
                // 进程未完成，执行一个时间片
                else 
                { 


                    // 计算等待时间
                    waittime += now - process_alr[i].arrtime; 

                    // 更新当前时间
                    now += timepian; 

                    // 更新剩余服务时间
                    remaint[i] -= timepian; 
                }
            }
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