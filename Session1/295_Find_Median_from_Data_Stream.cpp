//思路from discuss
class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if(maxHeap.size() == 0)
            maxHeap.push(num);
        else {
            if(num >= maxHeap.top()) {
                minHeap.push(num);
                if(minHeap.size() > maxHeap.size()) {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                }
            }
            else {
                maxHeap.push(num);
                if((maxHeap.size() - minHeap.size()) == 2)  {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(maxHeap.size() > minHeap.size())
            return maxHeap.top();
        else {
            double a = maxHeap.top();
            double b = minHeap.top();
            return (a + b) / 2.0;
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
