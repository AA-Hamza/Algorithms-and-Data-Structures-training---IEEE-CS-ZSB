"""
    Problem Link http://codeforces.com/contest/9/problem/A
"""
from fractions import Fraction
Yakko, Wakko = map(int, input().split())

#Test how many faces can Dot get to win
Dot = 6-max(Yakko, Wakko)+1

#Printing probablity
probablity = Fraction(Dot, 6)

if (probablity == 1):
    print("1/1")
elif (probablity == 0):
    print("0/1")
else:
    print(probablity)

