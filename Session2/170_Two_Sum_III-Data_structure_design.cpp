// add操作比find多，所以之前的写法会超时
class TwoSum {
private:
    unordered_map<int, int> mp;
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    mp[number] ++;
	    //下面那样会超时，估计是因为找了两遍？
	   // cout << 3 << endl;
	   // if(mp.find(number) == mp.end())
	   //     mp[number] = 1;
	   // else
	   //     mp[number] = 2;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(auto num : mp) {
	        int target = value - num.first;
	        if(target == num.first) {
	            if(num.second > 1)
	                return true;
	            continue;
	        }
	        if(mp.find(target) == mp.end())
	            continue;
	        return true;
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
