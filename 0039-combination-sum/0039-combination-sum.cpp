class Solution {
public:
    void combinationSum(int i, vector<int>& candidates, int target,
                        vector<vector<int>>& ans, vector<int>& temp) {
        if (i > candidates.size() - 1) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if (candidates[i] <= target) {
            temp.push_back(candidates[i]);
            combinationSum(i, candidates, target - candidates[i], ans, temp);
            temp.pop_back();
        }
        combinationSum(i + 1, candidates, target, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSum(0, candidates, target, ans, temp);
        return ans;
    }
};