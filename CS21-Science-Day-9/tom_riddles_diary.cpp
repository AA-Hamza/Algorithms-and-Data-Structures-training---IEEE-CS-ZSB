/*
    Problem Link https://codeforces.com/contest/855/problem/A
    Time complexity O(n^2)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> list;
    list.reserve(100);
    while (n--) {
        string name;
        cin >> name;
        if (find(list.begin(), list.end(), name) == list.end()) {
            cout << "NO" << endl;
            list.push_back(name);
        }
        else {
            cout << "YES" << endl;
        }
    }
}
