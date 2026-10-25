class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        while (low <= high) {
            double mid = low + (high - low) / 2;
            double sq = mid * mid;
            if (sq == num)
                return true;
            else if (sq < num)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
