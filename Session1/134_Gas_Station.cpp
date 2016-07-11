class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int num = gas.size();
        int total = 0;
        int curSum = 0;
        int start = 0;
        for(int i = 0; i < num; i ++) {
            total += (gas[i] - cost[i]);
            curSum += (gas[i] - cost[i]);
            if(curSum < 0) {
                start = i + 1;
                curSum = 0;
            }
        }
        if(total < 0)
            return -1;
        return start;
    }
};
