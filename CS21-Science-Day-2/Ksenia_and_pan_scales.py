#
# Problem Link https://codeforces.com/contest/382/problem/A?csrf_token=4d09a8c581f1c0a15d0a42f90d248f6e
#
# Not so proud of it but gets the job done
# Time Complexity = O(n+m) where m = len(avilable), n = len(left)+len(right)

left, right = input().split('|')
available = input()

smaller_scale_len = min(len(left), len(right))
bigger_scale_len = max(len(left), len(right))

gap = bigger_scale_len-smaller_scale_len;
if (len(left) < len(right)):
    left_end = gap + (len(available)-gap)//2
    left = left + available[:left_end]
    right = right + available[left_end:]
elif(len(right) < len(left)):
    right_end = gap + (len(available)-gap)//2
    right = right + available[:right_end]
    left = left + available[right_end:]
else:
    if (len(available) % 2 != 0):
        print("Impossible")
        quit()
    else:
        left = left + available[:len(available)//2]
        right = right + available[len(available)//2:]

if (len(left) != len(right)):
    print("Impossible")
else:
    print(left + '|' + right)
