#include <iostream>
using namespace std;

class Power
{
public:
    long int power(long int x, unsigned int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n % 2 == 0)
        {
            return power(x * x, n / 2);
        }
        else
        {
            return power(x * x, n / 2) * x;
        }
    }
};

void test01()
{
    cout << "请输入底数和幂：" << endl;
    long int x;
    unsigned int n;
    cin >> x >> n;

    Power p;
    cout << x << " ^ " << n << " = " << p.power(x, n) << endl;
}

int main()
{
    test01();

    return 0;
}