class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int maxSize;
    int curNum;
    int curSum;
    MovingAverage(int size) {
        maxSize = size;
        curNum = 0;
        curSum = 0;
    }
    
    double next(int val) {
        if(curNum < maxSize) {
            q.push(val);
            curNum ++;
            curSum += val;
        }
        else {
            int front = q.front();
            q.pop();
            curSum -= front;
            q.push(val);
            curSum += val;
        }
        return (double)curSum / (double)curNum;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
