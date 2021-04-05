/*
    Problem Link https://codeforces.com/contest/1065/problem/C
    Time Complexity O(n)
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef unsigned long long ull;

int main()
{
    ull n, k;
    cin >> n >> k;
    ull *heights = new ull[n];
    ull max = 0;
    ull min = 2*10e5+1;
    for (ull i = 0; i < n; ++i) {
        cin >> heights[i];
        if (heights[i] > max) {
            max = heights[i];
        }
        if (heights[i] < min) {
            min = heights[i];
        }
    }

    ull diff = max-min;
    ull *blocks_each_level = new ull[diff+2];
    for (ull i = 0; i < diff+2; ++i) {
        blocks_each_level[i] = 0;
    }
    for (ull i = 0; i < n; ++i) {
        ull level = heights[i]-min;
        blocks_each_level[level] += 1;
    }

    ull chunk = 0;
    ull times = 0;
    for (ull i = diff; i>0; --i) {
        blocks_each_level[i] += blocks_each_level[i+1];
        chunk += blocks_each_level[i];
        if (chunk > k) {
            times++;
            chunk = blocks_each_level[i];
        }
    }
    
    if (chunk)
        times++;
    cout << times << endl;
    return 0;
}
