class Solution {
public:
    int lowerBound(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        int first = -1, last = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int upperBound(vector<int>& arr, int x) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = n;
        int first = -1, last = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);
        if (lb == nums.size() || nums[lb] != target) {
            return {-1, -1};
        }
        return {lb, ub - 1};
    }
};