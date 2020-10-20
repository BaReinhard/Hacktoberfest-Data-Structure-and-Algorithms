#adding and removing element in list without using inbuilt function

def addEle(lst, pos, ele):
    new_lst = [ele]
    return lst[:pos]+new_lst+lst[pos:]

def removeEle(lst, pos):
    return lst[:pos]+lst[pos+1:]

lst = [1,2,3,4,5]
print(lst)
print(addEle(lst,2,33))
print(removeEle(lst,2))
