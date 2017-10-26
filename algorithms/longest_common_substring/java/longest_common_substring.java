import java.util.Arrays;

class StringManager {

    public static String findLongestCommonSubString(String str1, String str2) throws NullPointerException {
    	
    	char[] x = str1.toCharArray();
    	char[] y = str2.toCharArray();
    	
        int LCSMatrix[][] = new int[x.length+1][y.length+1];
        int length = 0;
        int indexOfLastCharX = 0;

        for(int i = 0; i < x.length; i++){
            for(int j = 0; j < y.length; j++){
                if(x[i] == y[j]){
                    if(i == 0 || j == 0){
                        LCSMatrix[i][j] = 1;
                        if(LCSMatrix[i][j] > length){
                        	length = LCSMatrix[i][j];
                            indexOfLastCharX = i;
                        }
                    } else {
                        LCSMatrix[i][j] = LCSMatrix[i-1][j-1] + 1;
                        if(LCSMatrix[i][j] > length){
                        	length = LCSMatrix[i][j];
                            indexOfLastCharX = i;
                        }
                    }
                } else {
                    LCSMatrix[i][j] = 0;
                }
            }
        }
        
        if(indexOfLastCharX == 0) return "";
        
        int indexOfFirstCharX = indexOfLastCharX - length + 1;
        return new String(Arrays.copyOfRange(x, indexOfFirstCharX, indexOfLastCharX + 1));
    }

    public static void main(String[] args){
    	String test1 = "immeasurable";
    	String test2 = "measure";
    	
    	String result = findLongestCommonSubString(test1, test2);
        System.out.println(result);
    }

}
