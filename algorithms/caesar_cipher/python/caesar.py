def caesar_shift(text,shift,mode):
    new_text = ""
    for char in text:
        char_num = ord(char)
        if char_num == 32:
            new_text += " "
        elif char_num >= 65 and char_num <= 90:
            new_char_num = shift_char(char_num - 64, shift,mode)
            new_text += chr(new_char_num + 64)
        elif char_num >= 97 and char_num <= 122 :
            new_char_num = shift_char(char_num - 96, shift, mode)
            new_text += chr(new_char_num + 96)
    return(new_text)
def shift_char(char_num,shift,mode):
    if mode:
        new_char_num = char_num + shift
        if (new_char_num > 26):
            new_char_num %= 26
    else:
        new_char_num = char_num - shift
        if (new_char_num < 1):
            new_char_num = 26 - abs(new_char_num)
    return(new_char_num)
def get_message():
    print("Please enter your message: ")
    message = str(input().strip())
    return(message)

def get_shift():
    print("Please enter the shift value: ")
    shift = str(input().strip())
    if shift.isdigit():
        shift = int(shift)
    else:
        print("Invalid input. Please try again")
        shift = get_shift()
    return(shift)

def get_mode():
    print("Please enter E for encoding or D for decoding")
    mode_text = str(input().strip())
    if mode_text == "E" or mode_text == "e":
        mode = True
    elif mode_text == "D" or mode_text == "d":
        mode = False
    else:
        print("Invalid input. Please try again")
        mode = get_mode()
    return(mode)
message = get_message()
shift = get_shift()
mode = get_mode()
result = caesar_shift(message,shift,mode)
print("Result is " +result)

