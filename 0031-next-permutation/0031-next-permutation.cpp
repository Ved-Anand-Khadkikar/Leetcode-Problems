class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        int j = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        while (nums[idx] >= nums[j]) {
            j--;
        }
        swap(nums[idx], nums[j]);
        reverse(nums.begin() + idx + 1, nums.end());
    }
};