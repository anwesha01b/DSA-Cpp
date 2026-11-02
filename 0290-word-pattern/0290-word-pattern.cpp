class Solution {
public:
    bool wordPattern(string pattern, string s) {
         vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        if (pattern.size() != words.size()) {
            return false;
        }
        unordered_map<char, int> charFirst;
        unordered_map<string, int> wordFirst;
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            if (charFirst.find(c) == charFirst.end()) {
                charFirst[c] = i;
            }
            if (wordFirst.find(words[i]) == wordFirst.end()) {
                wordFirst[words[i]] = i;
            }
            if (charFirst[c] != wordFirst[words[i]]) {
                return false;
            }
        }

        return true;
    }
};