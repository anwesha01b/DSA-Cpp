class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currentMax=0, maxSum=nums[0];
        int currentMin=0, minSum=nums[0];
        int totalSum=0;
        for(int num:nums){
             currentMax = max(currentMax + num, num);
        maxSum = max(maxSum, currentMax);
        currentMin = min(currentMin + num, num);
        minSum = min(minSum, currentMin);
        totalSum += num;
        }
        if(maxSum<0) return maxSum;
        return max(maxSum,totalSum-minSum);
    }
};