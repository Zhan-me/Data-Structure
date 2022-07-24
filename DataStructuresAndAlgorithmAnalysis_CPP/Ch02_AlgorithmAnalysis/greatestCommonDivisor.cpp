#include <iostream>
using namespace std;

const int ERROR = -1;

class GCD
{
public:
    unsigned int gcd(unsigned int a, unsigned int b)
    {
        unsigned int reminder;

        while (b > 0)
        {
            reminder = a % b;
            a = b;
            b = reminder;
        }
        return a;
    }
};

void test01()
{
    cout << "请输入2个整数：" << endl;
    unsigned int num1, num2;
    cin >> num1 >> num2;

    GCD obj;
    int ret = obj.gcd(num1, num2);
    cout << num1 << " 和 " << num2 << "的最大公因数为：" << ret << endl;
}

int main()
{
    test01();

    return 0;
}