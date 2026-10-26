class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastSum[3]={-1,-1,-1};
        int cnt=0;
        for(int i=0;i<s.size();i++){
            lastSum[s[i]-'a']=i;
            cnt+=1+min(lastSum[0],min(lastSum[1],lastSum[2]));
        }
        return cnt;
    }
};