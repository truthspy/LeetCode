class MedianFinder {
private:
    priority_queue<int> pqMax;
    priority_queue<int, vector<int>, greater<int>> pqMin;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        // 这个写得太复杂了，可以统一先都压到pqMax里
        // 然后再把最大的弹出来，压到pqMin里
        // 如果pqMax的size小于paMin的size，则从pqMin弹出来一个压入到pqMax中
        pqMax.push(num);
        pqMin.push(pqMax.top());
        pqMax.pop();
        if(pqMax.size() < pqMin.size()){
            pqMax.push(pqMin.top());
            pqMin.pop();
        }
        /*
        if(pqMax.size() == 0)
            pqMax.push(num);
        else if(pqMax.size() == pqMin.size()) {
            if(num <= pqMax.top())
                pqMax.push(num);
            else {
                pqMin.push(num);
                int cur = pqMin.top();
                pqMin.pop();
                pqMax.push(cur);
            }
        }
        else {
            if(num >= pqMax.top())
                pqMin.push(num);
            else {
                int cur = pqMax.top();
                pqMax.pop();
                pqMax.push(num);
                pqMin.push(cur);
            }
        }
        */
    }

    // Returns the median of current data stream
    double findMedian() {
        if(pqMax.size() == pqMin.size())
            return ((double)pqMax.top() + (double)pqMin.top()) / 2.0;
        return pqMax.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
