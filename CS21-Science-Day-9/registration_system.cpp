/*
    Problem Link https://codeforces.com/contest/4/problem/C
    Time Complexity O(n)
*/

#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<string, int> database;
    string name;
    while (n--) {
        cin >> name;
        auto it = database.find(name);
        if (it != database.end()) {
            (it->second)++;
            cout << it->first << it->second << endl;
        }
        else {
            database.insert(make_pair(name, 0));
            cout << "OK" << endl;
        }
    }
}
