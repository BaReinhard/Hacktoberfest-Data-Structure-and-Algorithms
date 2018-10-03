#python code to find median of two arrays of size n.


def median(x, y, n):
	print(n)
	print(x)
	print(y)	
	if n==1:
		return min(x[0],y[0])
	if n==2:
		return min(max(x[0], y[0]), min(x[1], y[1]))
	elif x[n/2]< y[n/2]:
		return median(x[((n/2)):n], y[:(n/2)+1], (n/2)+1)
	else:
		return median(x[:(n/2)+1], y[((n/2)):n], (n/2)+1)

x=[1,12,15,26,38]
y=[2,13,17,30.45]
n=5
print(median(x,y,n))
