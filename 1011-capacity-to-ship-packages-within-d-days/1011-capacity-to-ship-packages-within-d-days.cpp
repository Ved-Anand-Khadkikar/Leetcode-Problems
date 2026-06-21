class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = maxNum(weights);
        int high = calcSum(weights);
        int leastWeight = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            int daysReq = calcDays(weights, mid);
            if (daysReq <= days) {
                leastWeight = min(leastWeight, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return leastWeight;
    }
    int maxNum(vector<int>& weights) {
        int num = INT_MIN;
        for (int i = 0; i < weights.size(); i++) {
            num = max(num, weights[i]);
        }
        return num;
    }
    int calcSum(vector<int>& weights) {
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
        }
        return sum;
    }
    int calcDays(vector<int>& weights, int cap) {
        int days = 1;
        int load = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (load + weights[i] > cap) {
                days++;
                load = weights[i];
            } else {
                load += weights[i];
            }
        }
        return days;
    }
};