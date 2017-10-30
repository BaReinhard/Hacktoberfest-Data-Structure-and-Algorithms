def findLongestCommonSubString(str1, str2):
    len_str1 = len(str1)
    len_str2 = len(str2)
    LCSuff = [[0 for j in range(len_str2)] for i in range(len_str1)] # Longest common suffix
    indexOfLastChar1 = 0 # Last char of the longest common sub string in str1
    maxCommonLength = 0
    for i in range(len_str1):
        for j in range(len_str2):
            if str1[i] == str2[j]:
                if i == 0 or j == 0:
                    LCSuff[i][j] = 1
                else:
                    LCSuff[i][j] = LCSuff[i-1][j-1] + 1
                if LCSuff[i][j] > maxCommonLength:
                    maxCommonLength = LCSuff[i][j]
                    indexOfLastChar1 = i
    indexOfFirstChar1 = indexOfLastChar1 - maxCommonLength + 1
    return str1[indexOfFirstChar1:indexOfLastChar1+1]

if __name__ == '__main__':
    str1 = "ABABC"
    str2 = "BABCA"
    result = findLongestCommonSubString(str1, str2)
    assert result == "BABC"
