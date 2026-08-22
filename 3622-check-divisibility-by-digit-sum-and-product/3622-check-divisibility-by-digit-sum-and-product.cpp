class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int sum = 0;
        int prod = 1;
        while (n > 0) {
            sum += (n % 10);
            prod *= (n % 10);
            n /= 10;
        }
        int num = sum + prod;
        if (original % num == 0) {
            return true;
        } else {
            return false;
        }
    }
};