# Problem Link https://codeforces.com/contest/1204/problem/A
# Time Complexity = O(n)
# Explanation: count function is liner 
num_in_bin = input()
biggest_power = len(num_in_bin) - 1
num_of_1s = num_in_bin.count('1') 
stations = 0

if (biggest_power % 2 == 0):
    stations = (biggest_power-1)//2 + int(num_of_1s > 1)
else:
    stations = (biggest_power) // 2

print(stations+4**0)
