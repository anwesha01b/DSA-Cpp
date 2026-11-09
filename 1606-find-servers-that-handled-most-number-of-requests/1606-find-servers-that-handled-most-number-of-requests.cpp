class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k, 0);
        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> busy;
        for (int i = 0; i < arrival.size(); i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if (available.empty()) {
                continue;
            }
            int server = i % k;
            auto it = available.lower_bound(server);
            if (it == available.end()) {
                it = available.begin();
            }
            int chosen = *it;
            available.erase(it);
            cnt[chosen]++;
            busy.push({arrival[i] + load[i], chosen});
        }
        int maxi = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == maxi) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};