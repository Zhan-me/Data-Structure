#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

const int N = 10;

class RandomSequence
{
public:
    //生成[begin, end]区间的随机整数
    int randInt(int begin, int end)
    {
        return rand() % (end - begin + 1) + begin;
    }

    void naturalNumRandomReplace1(vector<int> &v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            int ran;
            int isSame = 1;

            while (isSame) //生成随机数，直到与已有的随机数不同
            {
                ran = randInt(0, v.size() - 1);
                isSame = 0;
                for (int j = 0; j < i; j++) //检查新生成的随机数是否与已有的相同
                {
                    if (ran == v[j])
                    {
                        isSame = 1;
                        break;
                    }
                }
            }
            v[i] = ran;
        }
    }

    void naturalNumRandomReplace2(vector<int> &v)
    {
        vector<bool> used(v.size(), false);
        for (int i = 0; i < v.size(); i++)
        {
            int ran;

            do //生成随机数直到其未被使用过
            {
                ran = randInt(0, v.size() - 1);
            } while (used[ran]);
            used[ran] = 1; //设置已使用标记
            v[i] = ran;
        }
    }

    // void swap(int *p1, int *p2)
    // {
    //     int temp = *p1;
    //     *p1 = *p2;
    //     *p2 = temp;
    // }

    void naturalNumRandomReplace3(vector<int> &v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            v[i] = i;
        }
        for (int i = 1; i < v.size(); i++) //将每一个数与前面随机的一个数交换位置
        {
            swap(v[i], v[randInt(0, i)]);
        }
    }
};

void test01()
{
    vector<int> v(N, 0);
    RandomSequence rs;
    // rs.naturalNumRandomReplace1(v);
    // rs.naturalNumRandomReplace2(v);
    rs.naturalNumRandomReplace3(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL)); //设置随机数种子
    test01();

    return 0;
}