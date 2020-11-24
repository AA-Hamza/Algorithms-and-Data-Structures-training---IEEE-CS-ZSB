/*
    Problem Link https://www.hackerrank.com/challenges/array-left-rotation/problem
    Time Complexity = O(n) "Worst case senario"
*/
#include <stdio.h>
#include <stdlib.h>

void shift_arr(int *arr, int n, int d) {
    //Shifting one by one cause it just easier
    while (d--) {
        int tmp = arr[0];
        for (int i = 0; i < n-1; ++i) {
            arr[i] = arr[i+1];
        }
        arr[n-1] = tmp;
    }
}

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);

    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]/*or arr+i */);
    }

    shift_arr(arr, n, d%n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
