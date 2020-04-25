/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int cycle = numRows * 2 - 2;
        string ans;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j + i < s.size(); j += cycle){
                ans += s[j+i];
                if(i != 0 && i != numRows - 1 && j + cycle - i< s.size()) {
                    ans += s[j + cycle - i];
                }
            }
        }
        return ans;
    }
};