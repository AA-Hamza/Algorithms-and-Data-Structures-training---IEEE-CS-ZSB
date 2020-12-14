"""
  Problem Link https://codeforces.com/problemset/problem/520/A
  Time complexity O(n^2)
"""

import string
_ = input()
buffer = str(input()).lower()

for i in string.ascii_lowercase:
    if (i not in buffer):
        print("NO")
        break
else:
    print("YES")
