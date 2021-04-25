'''
    Problem Link https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
'''

import bisect

def median(l):
    size = len(l)
    if ((size//2)*2 == size):   #even
        return (l[size//2]+l[size//2-1])/2
    else:
        return l[size//2]

n, d = map(int, input().split())
exp = list(map(int, input().split()))

test = sorted(exp[:d])
result = 0

for i in range(d, n):
    med = median(test)
    if (exp[i] >= med*2):
        result += 1
    del test[bisect.bisect_left(test, exp[i-d])]
    bisect.insort(test, exp[i])

print(result)
