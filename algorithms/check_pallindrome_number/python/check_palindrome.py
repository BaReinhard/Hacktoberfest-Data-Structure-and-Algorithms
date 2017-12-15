def check_palindrome(x) : 
    # start reversing the number by keep dividing to 10
    reverse = 0
    source  = x
    while (x > 10) : 
        reverse = (reverse * 10) + (x % 10)
        x = x / 10
    # remainder
    reverse = (reverse * 10) + x;
    if (reverse == source) :
        return True
    else:
        return False

input=1224334221
print("Palindrome Number" if check_palindrome(input) else "Not Palindrome Number")
