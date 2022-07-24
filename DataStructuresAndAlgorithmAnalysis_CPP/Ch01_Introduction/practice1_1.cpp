#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 100;
const int K = N / 2;

class Solution
{
public:
    int selectKthMax1(vector<int> &v, int k)
    {
        //将所有元素按递减排序
        sort(v.begin(), v.end(), greater<int>());
        return v[k - 1];
    }

    int selectKthMax2(vector<int> &v1, int k)
    {
        vector<int> v2;

        //将v1的前k个元素复制到v2中，并按递减排序
        // v2.resize(k + 1);
        // copy(v1.begin(), v1.begin() + k, v2.begin()); //对容器进行copy()之前需要先resize()

        copy(v1.begin(), v1.begin() + k, back_inserter(v2)); //使用back_inserter()指定目的容器，无须先resize()
        sort(v2.begin(), v2.end(), greater<int>());

        //将剩余元素插入到已排序序列的合适位置
        // for (int i = k; i < N; i++)
        // {
        //     int temp = v1[i];
        //     int j = k;
        //     for (; v2[j - 1] < temp && j > 0; j--)
        //     {
        //         v2[j] = v2[j - 1];
        //     }
        //     v2[j] = temp;
        // }

        for (auto i = v1.begin() + k; i != v1.end(); i++)
        {
            int temp = *i;
            auto j = v2.begin() + k;
            for (; *(j - 1) < temp && j > v2.begin(); j--)
            {
                *j = *(j - 1);
            }
            *j = temp;
        }

        return v2[k - 1];
    }
};

void test01()
{
    vector<int> v1;
    for (int i = 0; i < N; i++)
    {
        v1.push_back(i);
    }

    Solution s;
    int ret;
    // ret = s.selectKthMax1(v1, K);
    ret = s.selectKthMax2(v1, K);

    cout << ret << endl;
}

int main()
{
    test01();

    return 0;
}