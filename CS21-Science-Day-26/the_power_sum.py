"""
    https://www.hackerrank.com/challenges/the-power-sum/problem
    Time Complexity O(n)
    All my hoomies love dynamic programming. Recursion sucks (made by anti-recursion gang)
"""
x = int(input())
n = int(input())
array = [0] * (x+1)
array[0] = 1
for i in range(1, int(x**(1/n))+1):
    for j in range(x, i**n-1, -1):
        array[j] += array[j-i**n]

print(array[x])
