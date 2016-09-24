class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> mp;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) != mp.end())
            return false;
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) == mp.end()) 
            return false;
        int pos = mp[val];
        cout << mp.count(val) << endl;
        nums[pos] = nums[nums.size() - 1];
        nums.pop_back();
        // 要注意删除之后为空的情况
        mp[nums[pos]] = pos;
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int pos = rand() % (nums.size());
        return nums[pos];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
