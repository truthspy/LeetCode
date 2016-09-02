class PhoneDirectory {
private:
    vector<int> mp;
    queue<int> notUsed;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        mp.resize(maxNumbers, 0);
        for(int i = 0; i < maxNumbers; i ++) {
            notUsed.push(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int res = -1;
        if(!notUsed.empty()) {
            res = notUsed.front();
            notUsed.pop();
            mp[res] = 1;
        }
        return res;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return mp[number] == 0;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(mp[number] == 1) {
            mp[number] = 0;
            notUsed.push(number);
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
