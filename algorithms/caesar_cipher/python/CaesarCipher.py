cipher = []
a = raw_input("Input string: ")
shift = int(raw_input("Shift: "))
for i in a:
    j = ord(i)
    if (i.isupper()):
        cipher.append(chr((j+shift-65)%26 + 65))
    else:
        cipher.append(chr((j+shift-97)%26 + 97))
    b = ''.join(cipher)
print ("Cipher: " + b)
