#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v1(10, 1);
    vector<int> v2;
    // v2.resize(10);
    copy(v1.begin(), v1.end(), back_inserter(v2));

    for (auto it = v2.begin(); it != v2.end(); ++it)
    {
        cout << *it << endl;
    }

    return 0;
}