// 对于res，0-res-1都有人不认识他，或者他认识其他人；同时，res+1-n-1，res都不认识他们
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        for(int i = 1; i < n; i ++) {
            if(knows(res, i))
                res = i;
        }
        for(int i = 0; i < n; i ++) {
            if(i == res)
                continue;
            if(knows(i, res) && !knows(res, i))
                continue;
            else
                return -1;
        }
        return res;
    }
};
/*
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        unordered_set<int> notCelebrity;
        for(int i = 0; i < n; i ++) {
            if(notCelebrity.find(i) != notCelebrity.end())
                continue;
            for(int j = 0; j < n; j ++) {
                if(i == j)
                    continue;
                if(knows(j,i)) {
                    notCelebrity.insert(j);
                    if(!knows(i, j))
                        continue;
                }
                notCelebrity.insert(i);
                break;
            }
            if(notCelebrity.find(i) == notCelebrity.end())
                return i;
        }
        return -1;
    }
};
*/
