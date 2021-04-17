/*
 *  Problem Link http://codeforces.com/contest/363/problem/B
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    
    int *arr = malloc(sizeof(int)*n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int tmp = 0;
    for (int i = 0; i < k; ++i) {
        tmp += arr[i];
    }
    int smallest = tmp;
    int solution = 0;

    for (int i = k; i < n; ++i) {
        tmp += arr[i];
        tmp -= arr[i-k];
        if (tmp < smallest) {
            solution = i-k+1;
            smallest = tmp;
        }
        //printf("tmp -> %d\n", tmp);
    }
    printf("%d\n", solution+1);
}
