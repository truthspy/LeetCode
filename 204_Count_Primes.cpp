/*
找到一个质数k之后把所有小于n的，是k的倍数的数都排除掉
*/
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n,true);
        int count = 0;
        int sqr = sqrt(n);
        for(int i = 2; i < n; i ++) {
            if(prime[i]) {
               count ++; 
               //防止数太大溢出!!!!!
               if(i > sqr)
                    continue;
               int j = i * i;
               while(j < n) {
                   prime[j] = false;
                   j += i;
               }
            }
        }
        return count;
    }
};
//slow solution
/*
class Solution {
public:
    int countPrimes(int n) {
        if(n < 3)
            return 0;
        vector<int> primes;
        for(int i = 2; i < n; i ++) {
            if(primes.empty())
                primes.push_back(i);
            else {
                int size = primes.size();
                int j = 0;
                int sqr = sqrt(i);
                bool flag = false;
                while(j < size && primes[j] <= sqr) {
                    if(i % primes[j] == 0) {
                        flag = true;
                        break;
                    }
                    j ++;
                }
                if(!flag)
                    primes.push_back(i);
            }
        }
        return primes.size();
    }
};
*/
