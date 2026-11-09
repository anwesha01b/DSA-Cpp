class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = n / 3;
        vector<int> result;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n) {
            int current = nums[i];
            int count = 0;
            while (i < n && nums[i] == current){
                count++;
            i++;
        }
        if (count > threshold) {
            result.push_back(current);
        }
        }
        return result;
    }
};