/*
 * Problem Link https://codeforces.com/problemset/problem/433/B
 * Time compleixty O(n*log(n))
 * The creator of this problem is clearly a weeb
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ull;

void MERGE(ull *arr, ull *buf, int lpos, int rpos, int right_end)
{
    int left_end = rpos-1;
    int buf_pos = lpos;
    int num_of_elem = right_end-lpos+1;
    /*
    printf("lpos = %d\trpos = %d\tright_end=%d\n", lpos, rpos, right_end);

    printf("left sub array ");
    for (int i = lpos; i <= left_end; ++i) {
        printf("%llu ", arr[i]);
    }
    putchar('\n');

    printf("right sub array ");
    for (int i = rpos; i <= right_end; ++i) {
        printf("%llu ", arr[i]);
    }
    putchar('\n');
    */

    while (lpos <= left_end && rpos <= right_end) {
        if (arr[lpos] <= arr[rpos])
            buf[buf_pos++] = arr[lpos++];
        else
            buf[buf_pos++] = arr[rpos++];
    }


    //Dealing with leftovers
    while(lpos<=left_end) 
        buf[buf_pos++] = arr[lpos++];

    while(rpos<=right_end) 
        buf[buf_pos++] = arr[rpos++];

    for (int i = 0; i < num_of_elem; ++i, right_end--) {
        arr[right_end] = buf[right_end];
    }
}

void MSORT(ull *arr, ull *buf, int left, int right)
{
    if (left < right) {
        int mid = (left+right)/2;
        MSORT(arr, buf, left, mid);
        MSORT(arr, buf, mid+1, right);
        MERGE(arr, buf, left, mid+1, right);
    }
}

void merge_sort(ull *arr, int n)
{
    ull *buf = malloc(n * sizeof(ull));
    MSORT(arr, buf, 0, n-1);
    free(buf);
}

int main()
{
    int n;
    scanf("%d", &n);
    ull *arr = malloc(n * sizeof(ull));

    for (int i = 0; i < n; ++i) {
        scanf("%llu", &arr[i]);
    }

    ull *sorted = malloc(n * sizeof(ull));
    memcpy(sorted, arr, sizeof(ull) * n);
    merge_sort(sorted, n);
    //for (int i = 0; i < n; ++i) {
    //    printf("\t%d\n", sorted[i]);
    //}

    ull carry = 0;
    ull *type_1 = malloc(n * sizeof(ull));
    for (int i = 0; i < n; ++i) {
        carry += arr[i];
        type_1[i] = carry;
    }

    carry = 0;
    ull *type_2 = malloc(n * sizeof(ull));
    for (int i = 0; i < n; ++i) {
        carry += sorted[i];
        type_2[i] = carry;
    }


    int m;
    scanf("%d", &m);
    while (m--) {
        int type, l, r;
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1) {
            printf("%llu\n", type_1[r-1]-type_1[l-1]+arr[l-1]);
        }
        else {
            printf("%llu\n", type_2[r-1]-type_2[l-1]+sorted[l-1]);
        }
    }
}
