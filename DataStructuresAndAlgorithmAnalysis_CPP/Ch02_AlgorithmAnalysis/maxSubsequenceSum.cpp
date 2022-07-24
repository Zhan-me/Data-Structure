#include <iostream>
#include <vector>
using namespace std;

const int N = 10;

class MaxSubsequenceSum
{
public:
    //暴力法，计算每一个下标从i到j的子序列和，比较后得出最大子序列和
    int maxSubsequenceSum1(const vector<int> &v)
    {
        int thisSum, maxSum, i, j;
        maxSum = 0;
        for (i = 0; i < v.size(); i++)
        {
            thisSum = 0;
            for (j = i; j < v.size(); j++)
            {
                thisSum += v[j];
                if (thisSum > maxSum)
                {
                    maxSum = thisSum;
                }
            }
        }
        return maxSum;
    }

    static int max(int a, int b, int c)
    {
        return (a > b) ? (a > c ? a : c) : (b > c ? b : c);
    }

    //分治法，递归求出左半部分最大和、右半部分最大和，计算跨越中间边界的最大和，
    //比较后得出最大子序列和
    static int maxSubSum(const vector<int> &v, int left, int right)
    {
        int maxLeftSum, maxRightSum;
        int maxLeftBorderSum, maxRightBorderSum;
        int leftBorderSum, rightBorderSum;
        int center, i;

        if (left == right)
        {
            if (v[left] > 0)
            {
                return v[left];
            }
            else
            {
                return 0;
            }
        }

        center = (left + right) / 2;
        maxLeftSum = maxSubSum(v, left, center);
        maxRightSum = maxSubSum(v, center + 1, right);

        maxLeftBorderSum = leftBorderSum = 0;
        for (i = center; i >= left; i--)
        {
            leftBorderSum += v[i];
            if (leftBorderSum > maxLeftBorderSum)
            {
                maxLeftBorderSum = leftBorderSum;
            }
        }

        maxRightBorderSum = rightBorderSum = 0;
        for (i = center + 1; i <= right; i++)
        {
            rightBorderSum += v[i];
            if (rightBorderSum > maxRightBorderSum)
            {
                maxRightBorderSum = rightBorderSum;
            }
        }

        return max(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
    }

    int maxSubsequenceSum2(const vector<int> &v)
    {
        return maxSubSum(v, 0, v.size() - 1);
    }

    //联机算法
    int maxSubsequenceSum3(const vector<int> &v)
    {
        int thisSum, maxSum, i;
        maxSum = thisSum = 0;
        for (i = 0; i < v.size(); i++)
        {
            thisSum += v[i];
            if (thisSum > maxSum)
            {
                maxSum = thisSum;
            }
            else if (thisSum < 0)
            {
                thisSum = 0;
            }
        }
        return maxSum;
    }
};

void test01()
{
    vector<int> v;
    int x;
    cout << "请输入" << N << "个整数：" << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    MaxSubsequenceSum mss;
    int sum;
    sum = mss.maxSubsequenceSum1(v);

    cout << "最大子序列和为：" << sum << endl;
}

int main()
{
    test01();

    return 0;
}