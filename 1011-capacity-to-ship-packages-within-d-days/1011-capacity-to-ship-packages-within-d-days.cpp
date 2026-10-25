class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low < high) {
            int mid = low + (high - low) / 2;
            int totalDays = 0;
            int current = 0;
            for (int w : weights) {
                if (current + w > mid) {
                    totalDays++;
                    current = 0;
                }
                current += w;
            }
            totalDays++;
            if (totalDays <= days)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};