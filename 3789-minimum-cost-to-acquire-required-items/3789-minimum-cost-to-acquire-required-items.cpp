class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
       long long a = (long long)need1 * cost1 + (long long)need2 * cost2;
        long long b = (long long)min(need1, need2) * costBoth;
        if (need1 > need2)
            b += (long long)(need1 - need2) * cost1;
        else
            b += (long long)(need2 - need1) * cost2;
        long long c = (long long)max(need1, need2) * costBoth;
        return min(a, min(b, c));
    }
};