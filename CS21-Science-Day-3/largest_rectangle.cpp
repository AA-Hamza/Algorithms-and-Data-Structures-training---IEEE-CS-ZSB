/*
    *Problem Link https://www.hackerrank.com/challenges/largest-rectangle/problem
    *This the second attempt to implement
    Time Complexity = O(n^2)    but in general cases where they aren't all equal (worst case)
                                it would be O((n^2)/2) & best case scenario is O(2n)=O(n)
*/

#include <iostream>

using namespace std;

int area(int *(&h), int n) {
    int max = 0;
    for (int i = 0; i < n; ++i) {
        int j, floor = 1;

        //looking backword
        j = i-1;
        while (j >= 0 && h[j] >= h[i]) {
            floor++;
            j--;
        }

        //looking backword
        j = i+1;
        while (j < n && h[j] >= h[i]) {
            floor++;
            j++;
        }
        max = std::max(floor*h[i], max);
    }
    return max;
} 

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << area(arr, n) << endl;
}
