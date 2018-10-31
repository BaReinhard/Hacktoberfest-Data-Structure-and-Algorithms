def shuffle(items):

    #http://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffl

    for i in range(len(items)):

        j = randrange(i, len(items))

        items[i], items[j] = items[j], items[i]

        

shuffle(items = [1,2,3,4,5])
