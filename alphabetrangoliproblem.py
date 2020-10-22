def print_rangoli(size):
    # your code goes here
    mapping = {1: 'a', 2: 'b', 3: 'c', 4: 'd', 5: 'e',
       6: 'f', 7: 'g', 8: 'h', 9: 'i', 10: 'j',
       11: 'k', 12: 'l', 13: 'm', 14: 'n', 15: 'o',
       16: 'p', 17: 'q', 18: 'r', 19: 's', 20: 't',
       21: 'u', 22: 'v', 23: 'w', 24: 'x', 25: 'y',
       26: 'z'}

    width = (4 * size) - 3

    lis = [mapping[i] for i in range(size, 0, -1)]
    res = []
    final = []
    for i in range(0, size):
        res.append(lis[i])
        final.append(res + res[::-1][1:])

    final.extend(final[::-1][1:])

    for i in final:
        string = '-'.join(i)
        print(string.center(width, '-'))

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
