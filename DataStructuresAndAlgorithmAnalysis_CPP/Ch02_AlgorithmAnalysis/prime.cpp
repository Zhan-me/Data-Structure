#include <iostream>
#include <cmath>
using namespace std;

class Prime
{
public:
    int isPrime(int a)
    {
        if (a <= 0) //输入有误
        {
            return -1;
        }
        if (a == 1) // 1不是素数
        {
            return 0;
        }
        else
        {
            for (int i = 2; i <= sqrt(a); i++)
            {
                if (a % i == 0) //不是素数
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};

void test01()
{
    cout << "请输入一个整数：" << endl;
    int a;
    scanf("%d", &a);

    Prime p;
    int ret = p.isPrime(a);
    if (ret == -1)
    {
        cout << "输入有误" << endl;
    }
    else if (ret == 0)
    {
        cout << a << " 不是素数" << endl;
    }
    else
    {
        cout << a << " 是素数" << endl;
    }
}

int main()
{
    test01();

    return 0;
}