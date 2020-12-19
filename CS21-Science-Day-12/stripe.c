/*
 *  Problem Link https://codeforces.com/contest/18/problem/C
 *  Time complexity O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    long *sum = calloc(n+1, sizeof(long));
    for (int i = 1; i <= n; ++i) {
        long tmp;
        scanf(" %ld", &tmp);
        sum[i] += sum[i-1] + tmp;
    }


    int result = 0;
    for (int i = 1; i < n; ++i) {
        if (sum[i] == sum[n]-sum[i])
            result++;
    }
    printf("%d\n", result);
}
