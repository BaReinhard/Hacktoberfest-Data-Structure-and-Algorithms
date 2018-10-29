

def unique_chars(s):
	chars = {}
	for c in s:
		if c in chars:
			return False
		chars[c] = True
	return True
	
print(unique_chars("ADFKKS"))
print(unique_chars("ADFKS"))
print(unique_chars("ADFKSA"))
print(unique_chars("ADFK2S"))
print(unique_chars("AD2FK2S"))
print(unique_chars("A^D2FKS"))
print(unique_chars("ADFK2S^^"))
