'''
    Problem link https://codeforces.com/contest/810/problem/B
    Time Complexity O(n log(n))
'''

n, f = map(int, input().split())

not_sure_cases = []
sold = 0
for i in range(n):
    k, l = map(int, input().split())
    if (k >= l):
        sold += l
    else:
        not_sure_cases.append((k, l, (l if 2*k >= l else 2*k)-k))

sorted_cases = sorted(not_sure_cases, key=lambda day: day[2], reverse=True)

for i in range(len(sorted_cases)):
    if (i < f):
        k, l, gain = sorted_cases[i];
        sold += l if 2*k >= l else 2*k
    else:
        sold += sorted_cases[i][0]
print(sold)
