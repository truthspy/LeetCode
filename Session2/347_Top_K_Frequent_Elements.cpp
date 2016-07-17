// Method1:
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int size = nums.size();
        for(int i = 0; i < size; i ++) {
            if(mp.find(nums[i]) == mp.end())
                mp[nums[i]] = 1;
            else
                mp[nums[i]] ++;
        }
        priority_queue<pair<int,int>> q;
        for(auto i : mp) {
            q.push(make_pair(i.second, i.first));
        }
        vector<int> res;
        while(k > 0) {
            k --;
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
// Method2:
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int size = nums.size();
        for(int i = 0; i < size; i ++) {
            mp[nums[i]] ++;
        }
        vector<vector<int>> buckets(size);
        for(auto num : mp) {
            //因为至少有一个，不减1会越界
            buckets[num.second - 1].push_back(num.first);
        }
        int curNum = 0;
        vector<int> res;
        for(int i = size - 1; i >= 0; i --) {
            for(int j = 0; j < buckets[i].size(); j ++) {
                curNum ++;
                res.push_back(buckets[i][j]);
                if(curNum == k)
                    return res;
            }
        }
        return res;
    }
};
