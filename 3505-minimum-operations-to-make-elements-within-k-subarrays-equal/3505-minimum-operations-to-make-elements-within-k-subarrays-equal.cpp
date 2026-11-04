
class Solution {
public:
    multiset<int> low, high;
    long long lowSum = 0, highSum = 0;
    void balance() {
        while (low.size() > high.size() + 1) {
            int val = *low.rbegin();
            low.erase(low.find(val));
            lowSum -= val;
            high.insert(val);
            highSum += val;
        }
        while (low.size() < high.size()) {
            int val = *high.begin();
            high.erase(high.find(val));
            highSum -= val;
            low.insert(val);
            lowSum += val;
        }
    }
    void add(int val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
            lowSum += val;
        } else {
            high.insert(val);
            highSum += val;
        }
        balance();
    }
    void remove(int val) {
        auto it = low.find(val);
        if (it != low.end()) {
            low.erase(it);
            lowSum -= val;
        } else {
            it = high.find(val);
            high.erase(it);
            highSum -= val;
        }
        balance();
    }
    long long getCost() {
        long long median = *low.rbegin();
        return median * low.size() - lowSum
             + highSum - median * high.size();
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        low.clear();
        high.clear();
        lowSum = 0;
        highSum = 0;
        int n = nums.size();
        vector<long long> cost;
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }
        cost.push_back(getCost());
        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);
            cost.push_back(getCost());
        }
        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                long long skip = dp[i + 1][j];
                long long pick = INF;
                if (i + x <= n) {
                    pick = cost[i] + dp[i + x][j - 1];
                }
                dp[i][j] = min(skip, pick);
            }
        }
        return dp[0][k];
    }
};
