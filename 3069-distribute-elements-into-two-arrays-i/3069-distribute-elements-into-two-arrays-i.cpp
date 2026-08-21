class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        vector<int> result;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        // result = arr1;
        // result.insert(result.end(), arr2.begin(), arr2.end());
        // return result;
        int i = 0;
        while (i < arr1.size()) {
            result.push_back(arr1[i]);
            i++;
        }
        i = 0;
        while (i < arr2.size()) {
            result.push_back(arr2[i]);
            i++;
        }
        return result;
    }
};