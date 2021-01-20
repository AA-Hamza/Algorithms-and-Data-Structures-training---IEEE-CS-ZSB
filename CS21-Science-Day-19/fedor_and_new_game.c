/*
 * Problem Link https://codeforces.com/problemset/problem/467/B
 * Time Complexity O(n)
 *
*/

#include <stdio.h>
#include <stdint.h>

int number_of_set_bits(uint32_t number) {
    // There are dedicated alogrithms that do it faster
    int count = 0;
    while (number > 0) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

int main()
{
    int n, m, k, fedor;
    scanf("%d %d %d", &n, &m, &k);
    int players[m];
    for (int i = 0; i < m; ++i) {
        scanf("%d", &players[i]);
    }
    scanf("%d", &fedor);

    int friends = 0;
    for (int i = 0; i < m; ++i) {
        int different_bits = fedor^players[i];
        int num_of_diff_types = number_of_set_bits(different_bits);
        if (num_of_diff_types <= k)
            friends++;
            
    }
    printf("%d\n", friends);
}
