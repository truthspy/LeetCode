//unordered_map的使用

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        int size = nums.size();
        for(int i = 0; i < size; i ++) {
            if(hashMap.find(nums[i]) != hashMap.end())
                if(i - hashMap[nums[i]] <= k)
                    return true;
            hashMap[nums[i]] = i;
        }
        return false;
    }
};
