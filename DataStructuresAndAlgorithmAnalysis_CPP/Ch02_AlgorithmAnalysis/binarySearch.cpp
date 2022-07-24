#include <iostream>
#include <vector>
using namespace std;

const int N = 10;
const int NOT_FOUND = -1;

class BinarySearch
{
public:
    int binarySearch(const vector<int> &v, int x)
    {
        int low, mid, high;

        low = 0;
        high = v.size() - 1;
        while (low <= high) //只要剩余序列不为空，就继续二分查找
        {
            mid = (low + high) / 2;
            if (x < v[mid]) //待查找元素在左半边序列中
            {
                high = mid - 1;
            }
            else if (x > v[mid]) //带查找元素在右半边序列中
            {
                low = mid + 1;
            }
            else //查找成功
            {
                return mid;
            }
        }
        return NOT_FOUND; //查找失败
    }
};

void test01()
{
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        v.push_back(i);
    }

    cout << "请输入待查找元素：" << endl;
    int elem;
    cin >> elem;

    BinarySearch bs;
    int index = bs.binarySearch(v, elem);
    if (index != NOT_FOUND)
    {
        printf("查找成功，元素 %d 在第%d个位置\n", elem, index + 1);
    }
    else
    {
        printf("查找失败，没有此元素\n");
    }
}

int main()
{
    test01();

    return 0;
}