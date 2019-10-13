# Python program to find maximum contiguous subarray 
# To find this sum we use Kadane's Algorithm


def max_subarray_sum(array):
    max_so_far = 0
    max_ending_here = 0

    for i in array:
        max_ending_here = max_ending_here + i
        if max_ending_here < 0:
            max_ending_here = 0
        elif max_so_far < max_ending_here:
            max_so_far = max_ending_here

    return max_so_far

'''
Example:
max_subarray_sum([-2,-3,4,-1,-2,1,5,-3]) = 7
'''
