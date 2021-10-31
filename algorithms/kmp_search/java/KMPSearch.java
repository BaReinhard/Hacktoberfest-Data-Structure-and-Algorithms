
public class KMPSearch {
    public static void main(String[] args) {
        new KMPSearch().demo();
    }

    private void demo() {
        String s1 = "abcxabcdabxabcdabcdabcypo";
        String s2 = "abcdabcy";
        int[] prefixArray = new int[s2.length()];
        calculatePrefixArray(s2, prefixArray);
        for (int i = 0, j = 0; i < s1.length(); i++) {
            if (s1.charAt(i) == s2.charAt(j)) {
                j++;
            } else {
                if (j != 0) {
                    j = prefixArray[j - 1];
                    i--;
                }
            }

            if (j == s2.length()) {
                int index = i - j + 1;
                System.out.println("Pattern found at index " + index);
                System.out.println(s1.substring(index, index+s2.length()));
                return;
            }

        }
        System.out.println("Pattern not found");
    }


    private void calculatePrefixArray(String s, int[] prefixArray) {
        int j = 0;
        prefixArray[j] = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(j)) {
                prefixArray[i] = j + 1;
                j++;
            } else {
                if (j == 0) {
                    prefixArray[i] = 0;
                } else {
                    j = prefixArray[j - 1];
                    while (j != 0) {
                        if (s.charAt(j) == s.charAt(i)) {
                            prefixArray[i] = j + 1;
                            break;
                        } else {
                            j--;
                        }
                    }
                    if (j == 0) {
                        prefixArray[i] = 0;

                    }
                }

            }

        }

    }
}
