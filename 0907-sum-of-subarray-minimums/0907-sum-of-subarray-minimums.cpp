class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        int m = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        vector<int> nse(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            long long leftEl = i - pse[i];
            long long rightEl = nse[i] - i;
            long long count = leftEl * rightEl;
            long long totalSum = arr[i] * count;
            sum = (sum + totalSum) % m;
        }
        return sum;
    }
};