/*
 * Problem Link https://www.hackerrank.com/challenges/equal/problem
 * Time Complexity O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Calculate the number of operations needed to reduce val into target with values 1, 2, 5
int calc_ops(int val, int target) {
    int diff = val-target;
    int ops  = 0;

    ops += diff/5;
    diff = diff-(diff/5)*5;

    ops += diff/2;
    diff = diff-(diff/2)*2;

    ops += diff;

    return ops;
}

int main()
{
    int t, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        int *arr = malloc(sizeof(int) * n);
        int min = INT_MAX;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
            if (arr[i] < min)
                min = arr[i];
        }

        int tests[3] = {0};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                int ops = calc_ops(arr[i], min-j);
                tests[j] += ops;
            }
        }

        min = INT_MAX;
        for (int i = 0; i < 3; ++i) {
            if (min > tests[i])
                min = tests[i];
        }

        printf("%d\n", min);
        free(arr);
    }
}
