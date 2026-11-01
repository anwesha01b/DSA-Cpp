class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        deque<int> queue;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            count[ch]++;
            queue.push_back(i);
            while (!queue.empty() && count[s[queue.front()]] > 1) {
                queue.pop_front();
            }
        }
         return queue.empty() ? -1 : queue.front();
    }
};