class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n + 1, true);
        int count = 0;
        // 遍历上界到sqrt(n)就可以
        // 然后再扫一遍
        int square = sqrt(n);
        for(int i = 2; i <= square; i ++) {
            if(prime[i] == false)
                continue;
            for(int j = i * i; j <= n; j +=i)
                prime[j] = false;
        }
        for(int i = 2; i < n; i ++) {
            if(prime[i])
                count ++;
        }
        return count;
    }
};
