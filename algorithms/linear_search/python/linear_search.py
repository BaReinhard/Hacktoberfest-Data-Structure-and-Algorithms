def linear_search(array, target):
        for i, index in enumerate(array):
            if index == target:
                return i
        return False

if __name__ == "__main__":
    input_list = input('Insert array (list of ints separated by a space, eg. 1 2 3 4): ')
    array = list(map(int, input_list).split())) 
    target = int(input('Insert target: '))
    print('Pos: {}'.format(linear_search(a, target))
