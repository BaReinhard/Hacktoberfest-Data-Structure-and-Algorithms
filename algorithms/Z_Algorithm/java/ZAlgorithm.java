/**
 * Z Algorithm<br>
 * This algorithm uses a table to improve performance while searching for the
 * pattern into an array. It uses the Z-Table
 */
public class ZAlgorithm {

    private char SEPARATOR = '$';

    public int search(char[] pattern, char[] array) {
        int[] z = createZTable(pattern, array);
        int i = pattern.length + 1;
        while (i < z.length) {
            if (z[i] == pattern.length)
                return (i - pattern.length - 1);
            i++;
        }
        return -1;
    }

    public int[] searchAll(char[] pattern, char[] array) {
        int[] result = new int[array.length];
        int[] z = createZTable(pattern, array);

        int i = pattern.length + 1;
        while (i < z.length) {
            if (z[i] == pattern.length)
                result[i - pattern.length - 1] = z[i];
            i++;
        }
        return result;
    }

    /**
     * abc aaabcaa aab$aaabcaa 01002310021 20 320r
     *
     * @param pattern
     * @param array
     * @return
     */
    public int[] createZTable(char[] pattern, char[] array) {
        int[] z = new int[pattern.length + array.length + 1];
        char[] longString = createLongString(pattern, array);
        int left = 0;
        int right = 0;
        for (int i = 1; i < longString.length; i++) {
            if (i > right) {
                left = right = i;
                while (right < longString.length && longString[right - left] == longString[right])
                    right++;
                z[i] = right - left;
                right--;
            } else {
                int k = i - left;
                if (z[k] < right - i + 1)
                    z[i] = z[k];
                else {
                    left = i;
                    while (right < longString.length && longString[right - left] == longString[right])
                        right++;
                    z[i] = right - left;
                    right--;
                }
            }
        }
        return z;
    }

    public char[] createLongString(char[] pattern, char[] array) {
        char[] s = new char[pattern.length + array.length + 1];
        for (int i = 0; i < pattern.length; i++) {
            s[i] = pattern[i];
        }
        s[pattern.length] = SEPARATOR;
        for (int i = 0; i < array.length; i++) {
            s[pattern.length + 1 + i] = array[i];
        }
        return s;
    }
}
