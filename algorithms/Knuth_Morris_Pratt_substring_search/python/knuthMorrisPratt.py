#Knuth Morris Pratt algorithm
#Find if substring is present in string
#Applications: find the number of occurences of substring in string
#Algorithm: Caculate the widest border of the substring in the preprocessing phase.
#If mismatch - shift position by string match - widest boder length

def preprocessing(s):
	table = [1] * (len(s) + 1)
	j = 1
	for i in range(len(s)):
		while j <= i and s[i] != s[i-j]:
			j += table[i-j]
		table[i+1] = j
	return table
	
def knuthMorrisPratt(s, substring):
	table = preprocessing(substring)
	count = 0
	#print (table)
	j = 0
	for ch in s:
		while (j == len(substring) or (j >= 0 and ch != substring[j])):
			j -= table[j]
		j += 1	
		if j == len(substring):
			#return 'Substring Found'
			count += 1
	#return 'Substring not found'
	return count	

substring = input()
s = input()
print (knuthMorrisPratt(s, substring))