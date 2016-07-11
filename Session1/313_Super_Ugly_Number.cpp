class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> result(n, 1);
        vector<int> p(k, 0);
        int m = 1;
        while(m < n) {
            int min = INT_MAX;
            for(int i = 0; i < k; i ++) {
                if(result[p[i]] * primes[i] < min)
                    min = result[p[i]] * primes[i];
            }
            result[m] = min;
            for(int i = 0; i < k; i ++) {
                if(result[p[i]] * primes[i] == min)
                    p[i] ++;
            }
            m ++;
        }
        return result[n - 1];
    }
};
