/*
 * Problem Link https://codeforces.com/contest/816/problem/B
 * Time complexity O(n)
*/

#include <stdio.h>

#define MAX (200000+2)
int main()
{
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);
    int arr[MAX] = {0};

    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        arr[l] += 1;
        arr[r+1] -= 1;
    }

    int addmissible[MAX] = {0};
    int carry_coffee = 0;
    int carry_addmissible = 0;
    for (int i = 0; i < MAX; ++i) {
        carry_coffee += arr[i];
        arr[i] = carry_coffee;
        if (arr[i] >= k) {
            carry_addmissible++;
        }
        addmissible[i] = carry_addmissible;
    }

    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", addmissible[r]-addmissible[l-1]);
    }
}
