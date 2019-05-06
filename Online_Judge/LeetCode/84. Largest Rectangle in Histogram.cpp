/*
Author: Tony Hsiao
Date: 2019/05/06
Topic: 84. Largest Rectangle in Histogram
Note: Brute force O(n*n) will get TLE. Use stack and O(n) to solve it.
http://www.cnblogs.com/grandyang/p/4322653.html
當右方柱狀值小於目前STACK頂部的時候，更新最大區域面積
為了讓全部做完也會更新在後方增加一個元素0
*/
class Solution {
public:
    int max(int x, int y){
        return (x>y)?x:y;
    }
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        stack<int>st;

        heights.push_back(0);

        for(int i = 0 ; i < heights.size() ; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){ // need update max area
                int cur = st.top();
                st.pop();
                max_area = max(max_area,  heights[cur] * (!st.empty()?i-st.top()-1:i) );
                //printf("%d %d %d\n", i,  heights[cur], max_area);
            }
            st.push(i);
        }
        return max_area;
    }
};