/*
Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: 
[−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

*/

class Solution {
public:
    int reverse(int x) {
        string s, m = x > 0 ? "2147483647" : "-2147483648";
        for(s = x >= 0 ? "" : "-"; x; x /= 10) s += to_string(abs(x % 10));
        return s.size() == m.size() and s > m or s == "" ? 0 : stoi(s);
    }
};