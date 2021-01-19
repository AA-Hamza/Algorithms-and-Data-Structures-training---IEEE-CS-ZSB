/*
 * Problem Link https://codeforces.com/problemset/problem/579/A
 * Time Complexity O()
*/
#include <stdio.h>

typedef unsigned long long ull;

int main()
{
    ull desiered;
    scanf("%llu", &desiered);

    ull added_bacteria = 0;
    while (desiered > 0) {
        if (desiered % 2)
            added_bacteria++, desiered-=1;
        else
            desiered >>= 1;
        //printf("Desiered --> %llu\n", desiered);
    }

    printf("%llu\n", added_bacteria);
}
