class Solution {
public:
    string minWindow(string s, string t) {
        int freq[256] = {0};
        for (char c : t)
            freq[c]++;
        int left = 0, count = 0;
        int start = 0, minLen = INT_MAX;
        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right]] > 0)
                count++;
            freq[s[right]]--;
            while (count == t.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                freq[s[left]]++;
                if (freq[s[left]] > 0)
                    count--;
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

