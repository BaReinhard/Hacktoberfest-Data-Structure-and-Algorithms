import random

def bozo_sort(nums):
    while nums != sorted(nums):
        index_a, index_b = random.sample(range(0, len(nums)), 2)
        a = nums[index_a]
        b = nums[index_b]
        nums[index_a] = b
        nums[index_b] = a
    else:
        return nums
