def matrix_chain_multiplication(dimensions):
    """
    Implementation of matrix chain multiplication
    """

    matrix = [[0 for _ in dimensions] for _ in dimensions]

    for j in range(2, len(dimensions)):
        for i in range(j - 1, 0, -1):
            if j == i + 1:
                matrix[i][j] = dimensions[i - 1] * dimensions[i] * dimensions[i + 1]
            else:
                matrix[i][j] = \
                        min((matrix[i][k] + matrix[k + 1][j] + 
                             dimensions[i - 1] * dimensions[k] * dimensions[j]) 
                            for k in range(i, j))
        
    return matrix[1][len(dimensions) - 1]

# Test
if __name__ == '__main__':
    test_cases = (
        ([13, 5, 89], 13 * 5 * 89), # (M_1*M_2)*(M_3*M_4)
        ([13, 5, 89, 3, 34], 2856), # (M_1*(M_2*M_3))*M_4
        ([2, 3, 5, 2, 4, 3], 78), # (M_1*(M_2*M_3))*(M_4*M_5)
        ([66, 87, 71, 43, 18, 19, 33, 98, 54], 498402) # (M_1*(M_2*(M_3*M_4)))*(((M_5*M_6)*M_7)*M_8)
    )
    for dimensions, result in test_cases:
        assert matrix_chain_multiplication(dimensions) == result
