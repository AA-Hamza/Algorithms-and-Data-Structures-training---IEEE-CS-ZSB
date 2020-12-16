/*
 * Problem Link https://codeforces.com/problemset/problem/368/B
 * Time Complexity O(n)
*/
#include <stdio.h>
#include <stdlib.h>


#define MAX 10e5+1

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int *arr = malloc(n * sizeof(int)); 

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int *occurrences      = calloc(MAX, sizeof(int));     //Not space efficient, but get the job done
    /*Also occurrences could only be a flag (Seen before or not)*/
    int *queries_by_index = calloc(n  , sizeof(int));

    int carry = 0;
    for (int i = n-1; i >= 0; --i) {
        if (occurrences[arr[i]] == 0)
            queries_by_index[i] = ++carry;
        else
            queries_by_index[i] = carry;

        occurrences[arr[i]]++;
    }

    int index;
    while(m--) {
        scanf("%d", &index);
        printf("%d\n", queries_by_index[index-1]);
    }
    return 0;
}
