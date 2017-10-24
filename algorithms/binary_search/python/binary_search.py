#Simple implementation of the binary search

def b_search(a,s,start,end):
    target = int((start+end)/2)
    if start > end:
        return -1
    if s == a[target]:
        return target
    if s > a[target]:
        return b_search(a,s, target+1, end)
    if s < a[target]:
        return b_search(a,s, start, target-1)

#input: s = target, a = array 
print('Insert array (list of ints separated by a space): ')
a = list(map(int, input().split()))
print('Insert target: ')
s = int(input())
print('Pos: ')
print(b_search(a,s,0,len(a)-1))
