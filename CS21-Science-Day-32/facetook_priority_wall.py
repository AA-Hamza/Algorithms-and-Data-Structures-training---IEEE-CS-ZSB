'''
    Problem Link https://codeforces.com/contest/75/problem/B
'''
import re

my_name = input()
num_of_interactions = int(input())

post = re.compile(r"(\w+) posted on (\w+)'s wall")
comment = re.compile(r"(\w+) commented on (\w+)'s post")
like = re.compile(r"(\w+) likes (\w+)'s post")

friends = dict()

def get_other_name(my_name, groups):
    global firends
    other_name = str()
    if (groups[0] == my_name):
        other_name = groups[1]
    elif(groups[1] == my_name):
        other_name = groups[0]
    else:
        friends[groups[0]] = friends.get(groups[0], 0)
        friends[groups[1]] = friends.get(groups[1], 0)

    return other_name

for _ in range(num_of_interactions):
    line = input()
    post_result = post.match(line)
    comment_result = comment.match(line)
    like_result = like.match(line)
    if (post_result):
        #print("post matched")
        other_name = get_other_name(my_name, post_result.groups())
        if (other_name):
            friends[other_name] = friends.get(other_name, 0) + 15
    elif(comment_result):
        #print("comment matched")
        other_name = get_other_name(my_name, comment_result.groups())
        if (other_name):
            friends[other_name] = friends.get(other_name, 0) + 10
    elif(like_result):
        #print("like matched")
        other_name = get_other_name(my_name, like_result.groups())
        if (other_name):
            friends[other_name] = friends.get(other_name, 0) + 5

print(*[name for name, priority in sorted(friends.items(), key=lambda item: (-item[1], item))], sep='\n')
