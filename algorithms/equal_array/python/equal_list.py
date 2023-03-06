# Python3 program to find given
# two array are equal or not

# Returns true if arr1[0..n-1] and
# arr2[0..m-1] contain same elements.


def areEqual(arr1, arr2, n, m):

	# If lengths of array are not
	# equal means array are not equal
	if (n != m):
		return False

	# Sort both arrays
	arr1.sort()
	arr2.sort()

	# Linearly compare elements
	for i in range(0, n - 1):
		if (arr1[i] != arr2[i]):
			return False

	# If all elements were same.
	return True


# Driver Code
arr1 = [3, 5, 2, 5, 2]
arr2 = [2, 3, 5, 5, 2]
n = len(arr1)
m = len(arr2)

if (areEqual(arr1, arr2, n, m)):
	print("Yes")
else:
	print("No")

# This code is contributed
# by Shivi_Aggarwal.

