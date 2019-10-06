def checkPall(string):
	x = len(string)
	for i in range(x):
		if(string[i]!=string[x-i-1]):
			return False
	return True

string = input()
if(checkPall(string)):
	print("Yes")
else:
	print("No")