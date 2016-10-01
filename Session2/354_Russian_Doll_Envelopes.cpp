class Solution {
public:
    // 宽相同的时候高按降序排，保证不会有相同宽度的被加到结果中，如(3,3)和(3,4)并不能套在一起
    static bool myCmp(const pair<int,int> &a, const pair<int,int> &b) {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if(n == 0)
            return 0;
        sort(envelopes.begin(), envelopes.end(), myCmp);
        vector<int> dp;
        dp.push_back(envelopes[0].second);
        for(int i = 1; i < n; i ++) {
            int h = envelopes[i].second;
            if(h < dp[0])
                dp[0] = h;
            else if(h > dp[dp.size() - 1])
                dp.push_back(h);
            else {
                int l = 0;
                int r = dp.size() - 1;
                while(l <= r) {
                    int mid = (l + r) / 2;
                    if(h > dp[mid])
                        l = mid + 1;
                    else
                        r = mid - 1;
                }
                dp[l] = h;
            }
        }
        return dp.size();
    }
};
