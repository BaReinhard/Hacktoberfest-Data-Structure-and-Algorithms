def linear_search(a,target):
	i = 0
 	while i < len(a) and a[i] != target:
 		i = i+1
 	return i < len(a);

#input: target = target, a = array 
print('Insert array (list of ints separated by a space): ') #For example: "1 2 3 4"
a = list(map(int, input().split())) 
print('Insert target: ')
target = int(input())
print('Pos: ')
print(linear_search(a,target))