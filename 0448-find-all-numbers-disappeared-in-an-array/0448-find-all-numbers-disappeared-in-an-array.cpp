class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num:nums){
            seen.insert(num);
        }
        vector<int> result;
        for(int i=1; i<=nums.size();i++){
            if(seen.find(i)==seen.end())
            result.push_back(i);
        }
        return result;
    }
};