/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> s;
        for (int i = 0; i <= heights.size(); ++i) {
            int left;
            ////当前heights[i]元素小于栈顶元素或者当前下标已经到底了，计算以栈顶元素为矩形的高情况下矩形最大面积，单调栈，只有比栈顶元素大的入栈。
            while (!s.empty() && i == heights.size() || !s.empty() && heights[i] < heights[s.top()]) { //此时i为右端元素，找左边，如果单调栈出现了比heighti小的元素就要停止了，不然高度不重合。
                int top = s.top();
                s.pop();
                if (!s.empty()) {left = s.top();}  //找左边。
                else {left = -1;} 
                ans = max(ans, (i - left - 1) * heights[top]); //不断更新。
            }
            if (i != heights.size()) {s.push(i);}
        }
        return ans;
    }
};