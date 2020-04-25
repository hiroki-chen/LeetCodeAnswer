/*
Given a string, find the length of the longest substring without repeating characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int len = s.size();
        int max = 0;
        vector<int> dp(len + 1, 0);
        for(int i = 1; i <= len; i++){
            dp[i] = 1 + dp[i-1];
            for(int j = i - dp[i-1]; j < i; j++){
                if(s[i-1] == s[j-1]) {dp[i] = i - j; break;}
            }
            max = max > dp[i] ? max : dp[i];
        }
        return max;
    }
};