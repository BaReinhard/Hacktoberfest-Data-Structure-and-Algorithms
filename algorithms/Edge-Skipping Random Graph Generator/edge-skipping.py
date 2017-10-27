import random
import math

def choose(n, k):
	if 0 <= k and k <= n:
		 nk = 1                                      # N to the K
		 kk = 1                                      # K to the K
		 for t in range(1, min(k, n - k) + 1):
		 	nk *= n
		 	kk *=t
		 	n -= 1
		 return nk // kk
	else:
		return 0

def EdgeSkipping(n,p):
	m = n/2 * (n-1)
	x = 0
	while x < m:
		r = random.random()
		l = math.floor(math.log(r)/math.log(1-p))
		x = x + l + 1

		if x <= m:
			u = math.ceil((-1+math.sqrt(1+8*x))/2)
			v = x - choose(u,2) - 1
			print(u,v)

print('Input a number of nodes:')
n = int(input())
print('Inputer a probability p:')
p = float(input())
EdgeSkipping(n,p)
