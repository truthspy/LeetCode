class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> hashTable;
        int size = nums.size();
        for(int i = 0; i < size; i ++) {
            if(hashTable.find(nums[i]) != hashTable.end())
                hashTable[nums[i]] ++;
            else
                hashTable[nums[i]] = 1;
        }
        //使用pair，自动按pair中的元素从前往后排序，无需重载比较函数
        priority_queue<pair<int,int>> q;
        for(auto it = hashTable.begin(); it != hashTable.end(); it ++) {
            q.push(make_pair(it->second, it->first));
        }
        while(k > 0) {
            result.push_back(q.top().second);
            q.pop();
            k --;
        }
        return result;
    }
};
