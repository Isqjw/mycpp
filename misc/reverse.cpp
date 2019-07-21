#include "../head.h"

//我觉得官方的代码有多余，因为int类型最大数和最小数开头的数字只能是1或2，所以如果有最后一次循环的话，pop的值一定为1或2，
//所以(rev == INT_MAX / 10 && pop > 7)和(rev == INT_MIN / 10 && pop < -8)判断可以省略。本人已测。
int reverse(int x)
{
    int rev = 0;
    while (x != 0)
    {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
        {
            return 0;
        }
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
        {
            return 0;
        }
        rev = rev * 10 + pop;
    }
    return rev;
}

int main()
{
    cout << reverse(-120) << endl;
    return 0;
}