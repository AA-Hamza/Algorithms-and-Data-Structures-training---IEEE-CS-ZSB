'''
    Problem Link https://www.codewars.com/kata/55983863da40caa2c900004e
'''
def sort_after_swapping(l, index):
    tmp = l[index:]
    l = l[:index]
    tmp.sort()
    l = l+tmp
    return l

def next_bigger(n):
    digits = [int(i) for i in str(n)]
    length = len(digits) 
    
    #Testing the length
    if (length < 2):
        return -1 
    
    prev = 0
    #looping from the end to the beginning 
    for i in range(length-1, -1, -1):
        curr = digits[i]
        #getting the target's index
        if (curr < prev):
            #get the least posible value to replace the target.
            #loop after the target to the end.
            for x in range(i+1, length):
                if (digits[x] <= curr):
                    #swap the the privious one with the target because it is the least bigger value.
                    digits[i] = digits[x-1]
                    digits[x-1] = curr
                    break
            #No breaks means that they are larger than the target
            else:
                #so we would take the last one
                digits[i] = digits[length-1]
                digits[length-1] = curr 
                
            #let's make the final touch, sort the list after the target
            digits = sort_after_swapping(digits, i+1)
            
            #return the list to int
            num = int("".join(map(str, digits)))
            return num
                    
        else:
            prev = curr
            
    return -1
    
