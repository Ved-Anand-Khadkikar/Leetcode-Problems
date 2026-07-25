class Solution {
public:
    vector<int> nextSmallerElement(vector<int> heights, int n) {
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> prevSmallerElement(vector<int> heights, int n) {
        vector<int> pse(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        vector<int> nextSmaller = nextSmallerElement(heights, n);
        vector<int> prevSmaller = prevSmallerElement(heights, n);

        for (int i = 0; i < n; i++) {
            int area = heights[i] * (nextSmaller[i] - prevSmaller[i] - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};