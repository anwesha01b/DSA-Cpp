class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mpp;
        for(char c: text){
            mpp[c]++;
        }
        return min({
            mpp['b'],
            mpp['a'],
            mpp['l']/2,
            mpp['o']/2,
            mpp['n']
        });
    }
};