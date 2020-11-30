/*
    Problem Link https://codeforces.com/problemset/problem/767/A
    Time complexity O(n*n*log(n))       Computer goes brrrrrrr / didn't pass n=100000 test case

*/

#include <iostream>
#include <algorithm>

using namespace std;

void lets_sort(int *begin, int *end) {
    /*
    while ((*begin) == -1) {
        begin++;++
    }
    if (end-begin > 0) 
        sort(begin, end);
    */
    static int *starting_point = begin;
    while (*starting_point == -1) {
        starting_point++;
    }
    if (end-starting_point > 0) {
        sort(starting_point, end);
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n+1];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int curr = n;

    for (int i = 0; i < n; ++i) {
        if (arr[i] == curr) {
            cout << arr[i] << " ";
            arr[i] = -1;
            curr--;
            lets_sort(arr, arr+i);
            //cout << "arr:";
            //for (int i = 0; i < n; ++i) {
            //    cout << " " <<  arr[i];
            //}
            //cout << endl;
            for (int j = i-1; j >= 0; --j) {
                if (curr == arr[j]) {
                    cout << arr[j] << " ";
                    curr = arr[j]-1;
                    arr[j] = -1;
                }
                else
                    break;
            }
        }
        cout << endl;
    }
}
