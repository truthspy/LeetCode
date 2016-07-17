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
