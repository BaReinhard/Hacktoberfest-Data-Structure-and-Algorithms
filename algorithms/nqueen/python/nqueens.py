## https://www.interviewbit.com/problems/nqueens/

import copy
class Solution():

    def nqueen(self, A):
        arr = [[0 for i in range(A)] for j in range(A)]
        out = []
        self.nqueenCheck(arr, 0, out)
        return out

    def nqueenCheck(self, arr, index, out):
        n = len(arr)
        if index == n:
            self.convertArr(arr)
            out.append(arr)
            return
        for i in range(n):
            if arr[index][i] == 0:
                new_arr = copy.deepcopy(arr)
                # new_arr = arr[:][:]
                new_arr[index][i] = 10*n
                self.markBoard(new_arr, index, i)
                self.nqueenCheck(new_arr, index+1, out)

    def markBoard(self, arr, x, y):
        n = len(arr)
        for i in range(n):
            arr[x][i] = arr[x][i] + 1 if i != y else arr[x][i]
            arr[i][y] = arr[i][y] + 1 if i != x else arr[i][y]
            if x-i >= 0:
                if y-i >= 0:
                    arr[x-i][y-i] = arr[x-i][y-i] + 1 if i!=0 else arr[x-i][y-i]
                if y+i < n:
                    arr[x - i][y + i] = arr[x-i][y+i] + 1 if i!=0 else arr[x-i][y+i]
            if x+i < n:
                if y-i >= 0:
                    arr[x + i][y - i] = arr[x+i][y-i] + 1 if i!=0 else arr[x+i][y-i]
                if y+i < n:
                    arr[x + i][y + i] = arr[x+i][y+i] + 1 if i!=0 else arr[x+i][y+i]

    def convertArr(self, arr):
        n = len(arr)
        for i in range(n):
            for j in range(n):
                if arr[i][j] // (10*n) > 0:
                    arr[i][j] = 'Q'
                else:
                    arr[i][j] = '.'


if __name__ == "__main__":
    sol = Solution()
    print (sol.nqueen(4))
