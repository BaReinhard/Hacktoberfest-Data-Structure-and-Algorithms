def fast_power(a,n):
	if n==1:
		return a
	x = fast_power(a,n//2)
	if n%2==0: 					# For even n
		return x*x
	else:						# For odd n
		return x*x*a

def main():
	print('For a^n, enter the value of a and n separated by enter:')
	a = int(input())
	n = int(input())
	print(a,'^',n,'is',fast_power(a,n))

if __name__ == '__main__':
	main()