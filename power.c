#include <stdio.h>
#include <string.h>

// m的n次方算法
// 参考:https://blog.csdn.net/qq_22993855/article/details/108856359
double power(double x, int y) {
    int n = y;
        double ret = 1;
        while(n != 0) {
            // 幂指数为奇数,结果值就多乘一个基数
            if (n % 2 != 0) {
                ret = ret * x;
            }
            // 如果幂指数是奇数,因为需要整除2,所以会约掉余数1,使其变为偶数
            // 偶数就直接整除2
            n = n / 2;
            // 幂指数被除以2后,需要将底数翻倍
            x = x * x;
        }
        return y < 0 ? (1.0 / ret) : ret;
}

int maxConsecutiveAnswers(char * answerKey, int k){
    int count = strlen(answerKey);
    int start, end, res, k1, newStart;
    start = end = res = newStart = 0;
    k1 = k;
    while (end < count && start < count)
    {   
        if (answerKey[start] != answerKey[end])
        {
            if (k1 == k)
            {
                newStart = end;
            }
            k1--;
        }
        end++;
        if (k1 == 0 || end == count)
        {
            res = (end - start) > res ? (end - start) : res;
        }
        else if (k1 < 0)
        {
            start = end = newStart;
            k1 = k;   
        }
    }
    return res;
}

int main() {
    // double ret = power(2, -2);
    // printf("%f", ret);

    int num = maxConsecutiveAnswers("FFFTTFTTFT", 3);
    printf("%d", num);

    return 0;
}

