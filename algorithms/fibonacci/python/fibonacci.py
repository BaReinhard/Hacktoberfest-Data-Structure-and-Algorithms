#find a specific index of the fibonacci sequence
import math

#this uses dynamic programming
fibNums = [0,1]
def fibonacci(i):
	if i<=0:
		return 0
	elif i==1: 
		return 1
	elif i <= len(fibNums):
		return fibNums[i-1]
	else:
		#recursively calculate fibonacci numbers until we reach the one we want
		nextFib = fibonacci(i-1) + fibonacci(i-2)
		fibNums.append(nextFib)
		return nextFib

#TEST
print(fibonacci(6))