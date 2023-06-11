#include <stdio.h>
#include <string.h>

#define maxnum 100

int main()
{
    // 读入Pearl字符串
    char pearl[maxnum];

    scanf("%s", pearl);

    // 读入fisheyes字符串
    char fisheyes[maxnum];

    scanf("%s", fisheyes);

    // 统计珍珠数目
    int count = 0;
    int i,j;

    for (i = 0; i < strlen(pearl); i++) {

        for (j = 0; j < strlen(fisheyes); j++) {

            if (pearl[i] == fisheyes[j])

                count++;

        }
    }

    // 输出结果
    printf("%d\n", count);

    return 0;




}