'''
    Problem Link http://codeforces.com/contest/268/problem/C
'''

n, m = map(int, input().split())
points = min(n, m)

result = []
for i in range(points+1):
    result.append([i, points-i])

print(len(result))
for [x, y] in result:
    print(x, y)
