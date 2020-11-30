/*
    Problem Link https://leetcode.com/problems/defanging-an-ip-address/
    Time complexity O(n)
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string defangIPaddr(const string &address) {
        string ip;
        for (const auto &ch: address) {
            if (ch == '.') {
                ip.push_back('[');
                ip.push_back('.');
                ip.push_back(']');
            }
            else {
                ip.push_back(ch);
            }
        }
        return ip;
    }
};


int main()
{
    string ip;
    cin >> ip;
    Solution solve;
    cout << solve.defangIPaddr(ip) << endl;
}
