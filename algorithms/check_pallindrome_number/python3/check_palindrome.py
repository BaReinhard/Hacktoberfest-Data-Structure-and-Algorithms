from math import ceil

def palindrome(string):
    string = str(string) 
    if string[ceil(len(string)/2):] == ''.join(list(reversed(string[0:int(len(string)/2)]))):
        return True
    else:
        return False

