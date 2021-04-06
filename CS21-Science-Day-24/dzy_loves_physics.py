'''
    Problem Link https://codeforces.com/problemset/problem/444/A
'''
n, m = map(int, input().split())
nodes = list(map(int, input().split()))

max_density = 0
for i in range(m):
    n1, n2, e = map(int, input().split())
    val = (nodes[n1-1]+nodes[n2-1])/e
    if (val > max_density):
        max_density = val

max_density = "{:.16f}".format(max_density)
if (max_density[-1] >= '5'):
    print(max_density[:-2], int(max_density[-2])+1, sep="")
else:
    print(max_density[:-1])
