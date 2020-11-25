/*
    Problem Link https://www.hackerrank.com/challenges/flipping-the-matrix/problem
    Time Complexity O(m) m is the size of array
*/
#include <iostream>
#include <algorithm>
#include <initializer_list>

using namespace std;

// Note that c & r < n
inline int get_max_for_place(int n, int c, int r, int **matrix) {
    /*
        There will be four values to compare
        Basically you can get any of them to one of these corners
         ___________________
        |                   |
        |   *     :     *   |
        |  .......:.......  |
        |         :         |
        |   *     :     *   |
        |___________________|
    */

    int upper_left  = matrix[c][r];
    int upper_right = matrix[c][(n-1)-r];

    int lower_left  = matrix[(n-1)-c][r];
    int lower_right = matrix[(n-1)-c][(n-1)-r];
    return max({upper_right, upper_left, lower_right, lower_left});
}

int main()
{
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int **matrix = new int*[2*n];
        for (int i = 0; i < 2*n; ++i) {
            matrix[i] = new int[2*n];
        }

        for (int i = 0; i < 2*n; ++i) {
            for (int j = 0; j < 2*n; ++j) {
                cin >> matrix[i][j];
            }
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += get_max_for_place(2*n, i, j, matrix);
            }
        }
        cout << sum << endl;
    }
}
