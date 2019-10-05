inp_arr = list(map(int,input().split()))
inp_arr.sort()
closest = float('inf')
for i in range(1,len(inp_arr)):
	temp = abs(inp[i]-inp[i-1])
	closest = min(temp,closest)

print(closest)
