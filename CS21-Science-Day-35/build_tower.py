'''
    Problem Link https://www.codewars.com/kata/576757b1df89ecf5bd00073b/
'''

def tower_builder(n_floors):
    last_astriks = n_floors*2-1
    tower = []
    tmp = 0
    for i in range(last_astriks, 0, -2):
        tower.append([' '*tmp + '*'*i + ' '*tmp])
        tmp += 1
        
    tower.reverse()
    return tower

print(tower_builder(3))
