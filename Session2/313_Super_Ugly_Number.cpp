class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> index(k, 0);
        vector<int> res;
        res.push_back(1);
        int count = 1;
        while(count < n) {
            count ++;
            vector<int> equals;
            int cur = INT_MAX;
            for(int i = 0; i < k; i ++) {
                if(res[index[i]] * primes[i] == cur)
                    equals.push_back(i);
                else if(res[index[i]] * primes[i] < cur) {
                    cur = res[index[i]] * primes[i];
                    equals.clear();
                    equals.push_back(i);
                }
            }
            res.push_back(cur);
            for(int i = 0; i < equals.size(); i ++) {
                index[equals[i]] ++;
            }
        }
        return res[n - 1];
    }
};
