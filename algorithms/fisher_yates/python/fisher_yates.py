import random

def fisher_yates(arr):
	switchIndex = len(arr) -1

	while(switchIndex != 0):
		roll = random.randrange(switchIndex)
		temp = arr[roll]
		arr[roll] = arr[switchIndex]
		arr[switchIndex] = temp
		switchIndex = switchIndex - 1
	return arr

print('Array before shuffling')
arr = [1,2,3,4,5,6,7,8,9]
print(arr)

print('\nShuffling...')
arr = fisher_yates(arr)

print('\nArray after shuffling')
print(arr)