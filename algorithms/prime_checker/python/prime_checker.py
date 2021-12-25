'''
Programe to check whether a given
number is prime or not
'''

# Function to check prime or not
def prime_checker(user_input):
  flag = 0
  if user_input > 1:
    for i in range(2, user_input):
      if user_input % i == 0:
        print('Not Prime')
        flag = 1
        break
    if flag == 0:
      print('Prime')
  else:
    print('Not Prime nor Composite')

# Taking Input
user_input = int(input('Enter Number\n'))

# Calling Function
prime_checker(user_input)
