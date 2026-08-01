class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0;
        int r = 0;
        int n = s.length();
        int changes = 0;
        int maxFreq = INT_MIN;
        int maxLen = INT_MIN;

        while (r < n) {
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            changes = (r - l + 1) - maxFreq;
            while (changes > k) {
                mp[s[l]]--;
                l++;
                changes = r - l + 1 - maxFreq;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};