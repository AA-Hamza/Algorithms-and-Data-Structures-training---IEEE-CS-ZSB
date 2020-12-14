"""
    Problem Link https://codeforces.com/problemset/problem/141/A
    Time Complexity O(n)
"""

first_name   = input()
second_name  = input()

letter_dictionary = {}
for i in first_name:
    letter_dictionary[i] = letter_dictionary.get(i, 0) + 1

for i in second_name:
    letter_dictionary[i] = letter_dictionary.get(i, 0) + 1


pile_letters = input()

pile_dictionary = {}
for i in pile_letters:
    pile_dictionary[i] = pile_dictionary.get(i, 0) + 1

if (pile_dictionary == letter_dictionary):
    print("YES")
else:
    print("NO")
