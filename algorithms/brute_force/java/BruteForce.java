
import java.util.Arrays;

/**
 * Brute Force Algorithm<BR>
 *     It will search for a pattern into an array anf if the pattern if found it will
 *     return the index of the array where the first letter of the pattern was found.<BR>
 *     If no mach is found it will return -1
 */
public class BruteForce {

    /**
     * This method searches for the pattern into an array and return the index of the first char that matches.<BR>
     * If no match is found -1 is returned
     *
     * array = abcadef  zef
     * pattern = def -> 4
     * @param array
     * @param pattern
     * @return
     */
    public int firstMatch(char[] array, char[] pattern){
       for(int a = 0; a <= array.length-pattern.length; a++) {
           for (int p = 0; p < pattern.length; p++) {
               if (array[a+p] != pattern[p]) break;
               if (p == pattern.length-1) return a;
           }
       }
       return -1;
    }


    /**
     * This method seraches for a pattern into an array and return an array of int with the indexes of
     * the elements found
     *
     * @param array
     * @param pattern
     * @return
     */
    public int[] everyMatch(char[] array, char[] pattern) {
        int[] found = new int[array.length];
        int index = 0;
        Arrays.fill(found, -1);

        for(int a = 0; a <= array.length-pattern.length; a++) {
            for (int p = 0; p < pattern.length; p++) {
                if (array[a+p] != pattern[p]) break;
                if (p == pattern.length-1) {
                    found[index++] = a;
                }
            }
        }
        return found;
    }

}
