from math import sqrt,floor

x = int(input())

for c in range(x):
	flag = True
	a = int(input())
	cont = 1
	
	if a not in [2,3]:
		for i in range(2,floor(sqrt(a))+1):
			if a % i == 0:
				cont += 1
			if cont > 1:
				flag = False
				break
	if flag:
		print("Prime")
	else:
		print("Not Prime")
