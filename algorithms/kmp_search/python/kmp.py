def build_suffix(suffix_array, pattern):
	j=0
	i=0
	suffix_array.append(0)
	while(i<len(pattern)):
		if(pattern[i]==pattern[j]):
			suffix_array.append(j+1)
			i+=1
			j+=1
		else:
			if(j!=0):
				j = suffix_array[i-1]
			else:
				suffix_array.append(0)
				i+=1

def search(suffix_array, string, pattern):
	j=0
	i=0

	while(i<len(string)):
		if(string[i]==pattern[j]):
			i+=1
			j+=1
		else:
			if(j!=0):
				j=suffix_array[i-1]
			else:
				j=0

		if(j==len(pattern)):
			return (j-len(pattern))

	return -1

if __name__ == "__main__":
	string = raw_input("Enter the main-string: ")
	pattern = raw_input("Enter the pattern to search for: ")

	suffix_array=[]
	build_suffix(suffix_array, pattern)
	index = search(suffix_array, string, pattern)
	if(index==-1):
		print("Not found!")
	else:
		print("Found at "+ index+1)