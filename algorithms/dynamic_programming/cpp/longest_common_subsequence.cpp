/*
** Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0
*/

#include <iostream>
#include <vector>

using namespace std;

class LCS {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len_text1 = text1.size(), len_text2 = text2.size();
        int dp[len_text1+1][len_text2+1];

        for(int i = 0; i < len_text1 + 1; i++){
            dp[i][0] = 0;
        }

        for(int i = 0; i < len_text2 + 1; i++){
            dp[0][i] = 0;
        }

        for(int i = 1; i < len_text1 + 1; i++){
            for(int j = 1; j < len_text2 + 1; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[len_text1][len_text2];
    }
};


int main() {
    LCS obj_lcs;

    string t1 = "abcde";
    string t2 = "ace";

    int output = obj_lcs.longestCommonSubsequence(t1, t2);

    cout << "Output length: " << output << endl;

    return 0;
}
