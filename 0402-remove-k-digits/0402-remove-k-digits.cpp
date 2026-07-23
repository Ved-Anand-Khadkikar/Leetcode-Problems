class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans = "";
        for (int i = 0; i < num.length(); i++) {
            while (!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k > 0 && !st.empty()) {
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
        while (ans.length() != 0 && ans.back() == '0') {
            ans.pop_back();
        }
        if (ans.length() == 0) {
            return "0";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};