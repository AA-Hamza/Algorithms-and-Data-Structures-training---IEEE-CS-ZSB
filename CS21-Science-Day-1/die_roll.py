"""
    Problem Link http://codeforces.com/contest/9/problem/A
    Time Complexity = O(1)
    Explanition: O(log(6))=O(1) cause gcd, which is used to simplify fraction, 
                 is O(log(min(first_paramter, second_paramter))) & second_paramter is always 6 so it is O(1)
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

