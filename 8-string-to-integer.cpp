/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
*/

class Solution {
public:
    int myAtoi(string str) {
        if(str.empty()) return 0;
        bool flag = 1;
        long ans = 0;
        int i = 0;
        while(str[i] == ' ') i++; //先处理开头的空格
        if(str[i] == '-'){
            flag = 0;
            i++;
        }
        else if(str[i] == '+'){
            flag = 1;
            i++;
        }
        for(; i < str.size() ; i++){
            if(str[i] >= '0' && str[i] <= '9'){
                ans = ans * 10 + (str[i] - '0');
                if(ans > 2147483647 && flag) return INT_MAX;
                else if(ans > 2147483647 && !flag) return INT_MIN; //负数越界会变成正数
            }
            else break;
        }
        return flag ? ans : -ans;
    }
};