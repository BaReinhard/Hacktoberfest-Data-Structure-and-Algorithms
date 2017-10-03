import javax.sound.midi.SysexMessage;

class LongestCommonSubString {

    public static int findLongestCommonSubString(char[] x, char[] y, int m, int n){

        int LCSMatrix[][] = new int[m+1][n+1];
        int result = 0;
        int indexOfLastCharX = 0;
        int indexOfLastCharY = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(x[i] == y[j]){
                    if(i == 0 || j == 0){
                        LCSMatrix[i][j] = 1;
                        if(LCSMatrix[i][j] > result){
                            result = LCSMatrix[i][j];
                            indexOfLastCharX = i;
                            indexOfLastCharY = j;
                        }
                    } else {
                        LCSMatrix[i][j] = LCSMatrix[i-1][j-1] + 1;
                        if(LCSMatrix[i][j] > result){
                            result = LCSMatrix[i][j];
                            indexOfLastCharX = i;
                            indexOfLastCharY = j;
                        }
                    }
                } else {
                    LCSMatrix[i][j] = 0;
                }
            }
        }
        printCommonSubString(x, result, indexOfLastCharX);
        return result;
    }

    private static void printCommonSubString(char[] x, int length, int i){
        for(int startingPoint = i - length + 1; startingPoint <= i; startingPoint++){
            System.out.print(x[startingPoint]);
        }
        System.out.print("\n");
    }

    public static void main(String[] args){
        char[] test1 = "immeasurable".toCharArray();
        char[] test2 = "measure".toCharArray();
        System.out.print(findLongestCommonSubString(test1, test2, test1.length, test2.length));
    }

}
