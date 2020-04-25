/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
*/

class Solution {
public:
    int reverse(int x){
    string s, m = x > 0 ? "2147483647" : "-2147483648";
    for(s = x >= 0 ? "" : "-"; x; x/=10) s += to_string(abs(x % 10));
    return s.size() == m.size() && s > m || s == "" ? 0 : stoi(s);
    }
    bool isPalindrome(int x) {
            if(x < 0) return false;
            else if(to_string(reverse(x)) == to_string(x)) return true;
            else return false;
        }
};