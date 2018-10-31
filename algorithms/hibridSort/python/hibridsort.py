import random

def quickSort(array, low, high): 
    if low < high: #enquanto o indice de inicio do vetor for menos que o indice do final
        p = hpartition(array, low, high)
        if p == -1:
            return            
        quickSort(array, low, p)
        quickSort(array, p+1, high)


def hpartition(array, low, high):
    #o pivo é escolhiod aleatoriamente
    pivot_index = random.randint(low, high)

    pivot = array[pivot_index]
    
    #fazer a troca pro insertion aqui
    #Se a condicao abaixo for verdadeira, a uma chance desse vetor ja estar ordenado
    #Podemos arriscar fazer a troca pro insertionsor pelo seu tamanho ideal
    if((low - high + 1) <= 1000) and (pivot == pivot_index) and (low == array[low]) and (high == array[high]): 
        insertionsort(array[low : high])
        return -1
    
    while True:
        while array[low] < pivot:
            low += 1

        while array[high] > pivot:
            high -= 1

        if low >= high:
            return high

        array[low], array[high] = array[high], array[low] 

        low += 1
        high -= 1

def hibridsortHandler(array):
    quickSort(array, 0, len(array) - 1)


#####

def insertionsort(Array):
  for i in range( 1, len(Array)):
    chave = Array[i]
    k = i
    while k > 0 and chave < Array[k - 1]:
        Array[k] = Array[k - 1]
        k -= 1
    Array[k] = chave

