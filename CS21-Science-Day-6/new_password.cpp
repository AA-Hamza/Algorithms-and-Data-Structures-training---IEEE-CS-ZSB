/*
    Problem Link http://codeforces.com/contest/770/problem/A 
    Time Complexity O(n)
*/
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cout << (char)('a'+i%k);
    }
    cout << endl;
}
