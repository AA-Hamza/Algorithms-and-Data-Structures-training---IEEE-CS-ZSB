'''
    Problem Link https://codeforces.com/contest/1009/problem/B
    Time Complexity O(n)
'''
num = input()
length = len(num)

first_2 = num.find('2')

if first_2 == -1:
    first_2 = length

zeros_before_first_two = num[:first_2].count('0')
ones = num.count('1')
print('0'*zeros_before_first_two, end="")
print('1'*ones, end="")
for i in range(first_2, length):
    if (num[i] != '1'):
        print(num[i], end="")

