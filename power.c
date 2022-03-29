#include <stdio.h>

// m的n次方算法

int power(int x, int y) {
    int m = x;
    int n = y;
    int ret = 1;
    while (n != 0)
    {
        // 幂指数为奇数,结果值就多乘一个基数
        if (n % 2 != 0) {
            ret = ret * m;
        }
        // 如果幂指数是奇数,因为需要整除2,所以会约掉余数1,使其变为偶数
        // 偶数就直接整除2
        n = n / 2;
        // 幂指数被除以2后,需要将底数翻倍
        m = m * m;
    }
    return ret;
}

int main() {
    int ret = power(2, 10);
    printf("%d", ret);
    return 0;
}