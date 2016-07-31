class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> mp;
        int len = s.length();
        for(int i = 0; i < len; i ++) {
            if(mp.find(s[i]) == mp.end())
                mp[s[i]] = 1;
            else
                mp[s[i]] ++;
        }
        int count = 0;
        for(auto w : mp) {
            if(w.second % 2 == 1) {
                count ++;
                if(count > 1)
                    return false;
            }
        }
        return true;
    }
};
/*
其他解法：http://www.cnblogs.com/grandyang/p/5223238.html
1. 用一个set，如果不存在当前元素，加入，如果存在，删除，最后判断set的大小，如果为0或1，则为回文串
2. 用bitset，256大小的bitset，每个字母根据其ASCII码值的不同都有其对应的位置，然后我们遍历整个字符串，遇到一个字符，就将其对应的位置的二进制数flip一下，就是0变1，1变0，那么遍历完成后，所有出现次数为偶数的对应位置还应该为0，而出现次数为奇数的时候，对应位置就为1了，那么我们最后只要统计1的个数，就知道出现次数为奇数的字母的个数了，只要个数小于2就是回文数
*/
