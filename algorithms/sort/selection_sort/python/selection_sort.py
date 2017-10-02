# -*- coding: utf-8 -*-
"""
Created on Sun Oct 1 21:17 2017
@author: john2ksonn

Just a simple implementation of the selectionsort algo
"""

def selectionsort(a):
    n = len(a)
    left = 0
    while left < n:
        minVal = left
        for i in range(left + 1, n):
            if(a[i] < a[minVal]):
                minVal = i
        temp = a[left]
        a[left] = a[minVal]
        a[minVal] = temp
        left += 1


a = [12, 33, 1, 3, 54, 32, 78, 54, 99, 6]
print(a)
selectionsort(a)
print(a)
