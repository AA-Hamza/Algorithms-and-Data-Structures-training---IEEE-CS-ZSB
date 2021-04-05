'''
    Problem Link https://codeforces.com/contest/479/problem/B
'''

n, k = map(int, input().split())
towers = list(map(int, input().split()))

def get_min_max_indices():
    tmp = towers[0]
    max_index = 0
    min_index = 0
    for i in range(1, len(towers)):
        if (towers[i] > towers[max_index]):
            max_index = i
        if (towers[i] < towers[min_index]):
            min_index = i
    return min_index, max_index

tracks = []
for i in range(k):
    min_index, max_index = get_min_max_indices()
    if (towers[min_index] == towers[max_index]):
        break
    towers[max_index] -= 1
    towers[min_index] += 1
    tracks.append([max_index+1, min_index+1])

lowest_point, highest_point = get_min_max_indices()
print(towers[highest_point]-towers[lowest_point], len(tracks))

for record in tracks:
    print(*record)
