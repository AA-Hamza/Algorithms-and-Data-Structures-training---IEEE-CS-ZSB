/*
 * Problem Link https://codeforces.com/contest/1025/problem/A
 * Time complexity O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR(x) ((x)-'a')
#define NUM_OF_ENGLISH_LETTERS 'z'-'a'+1

int main()
{
    int *puppies = malloc(sizeof(int) * NUM_OF_ENGLISH_LETTERS);
    memset(puppies, 0, sizeof(int) * NUM_OF_ENGLISH_LETTERS);

    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("YES\n");
        return 0;
    }

    while (n--) {
        char smol_puppy;
        scanf(" %c", &smol_puppy);
        puppies[COLOR(smol_puppy)]++;
    }

    for (int i = 0; i < NUM_OF_ENGLISH_LETTERS; ++i) {
        if (puppies[i] > 1) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
