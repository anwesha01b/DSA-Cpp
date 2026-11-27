class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxLeftScore=values[0]+0;
        int maxScore=0;
        for(int j=1;j<values.size();j++){
            maxScore=max(maxScore,maxLeftScore+values[j]-j);
            maxLeftScore=max(maxLeftScore,values[j]+j);
        }
        return maxScore;
    }
};