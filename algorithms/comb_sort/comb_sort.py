__author__ = "Matteo Veraldi"
__email__ = "mattveraldi@gmail.com"
__github__ = "mattveraldi"

def comb_sort(lis, comb = None):
    factor = 1.3
    if(comb == None):
        comb = len(lis)
    gap = int(comb // factor)
    while (gap >= 1):
        i = 0
        j = gap
        #print("[=] Gap value: " + str(gap)) #UNCOMMENT TO DEBUG
        while(j < len(lis)):
            #print("[>] Compare: " + str(lis[i]) + " " + str(lis[j])) #UNCOMMENT TO DEBUG
            if(lis[i] > lis[j]):
                #print("[!] Switched") #UNCOMMENT TO DEBUG
                lis[i], lis[j] = lis[j], lis[i]
            i += 1
            j += 1
        gap = int(gap // factor)
    return lis    

def test():
    print("##COMB SORT by Matteo Veraldi##")
    unordered_list = [1, 4, 9, 18, 1920, 3.2, 6, 5, 2, 0]
    expected = [0, 1, 2, 3.2, 4, 5, 6, 9, 18, 1920]
    assert comb_sort(unordered_list) == expected, "test failed."
    print("test ok.")