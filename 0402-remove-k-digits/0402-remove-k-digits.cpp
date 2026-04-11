class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;
        string ans = "";
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        if (st.empty()) {
            return "0";
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        while (!ans.empty() && ans.back() == '0') {
            ans.pop_back();
        }
        if(ans.empty()){
            return "0";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};