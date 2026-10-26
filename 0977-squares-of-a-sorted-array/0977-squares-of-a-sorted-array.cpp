class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> result(n);
        for (int i = n - 1; i >= 0; i--) {
            int sq1 = nums[left] * nums[left];
            int sq2 = nums[right] * nums[right];
            if (sq1 > sq2) {
                result[i] = sq1;
                left++;
            } else {
                result[i] = sq2;
                right--;
            }
        }
        return result;
    }
};