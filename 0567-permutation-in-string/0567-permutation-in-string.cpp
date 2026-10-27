class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;
        vector<int> freq(26, 0);
        for (char c : s1) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            freq[s2[i] - 'a']--;
        }
        if (all_of(freq.begin(), freq.end(), [](int x) { return x == 0; })) {
            return true;
        }
        for (int i = n; i < m; i++) {
            freq[s2[i - n] - 'a']++;
            freq[s2[i] - 'a']--;
            if (all_of(freq.begin(), freq.end(),
                       [](int x) { return x == 0; })) {
                return true;
            }
        }
        return false;
    }
};