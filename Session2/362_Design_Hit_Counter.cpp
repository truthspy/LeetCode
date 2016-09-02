// follow up: 保存每秒的count值
class HitCounter {
private:
    queue<int> ts;
    int count;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        count = 0;
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        ts.push(timestamp);
        count ++;
        while(!ts.empty()) {
            int cur = ts.front();
            if(timestamp - cur >= 300) {
                ts.pop();
                count --;
            }
            else
                break;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!ts.empty()) {
            int cur = ts.front();
            if(timestamp - cur >= 300) {
                ts.pop();
                count --;
            }
            else
                break;
        }
        return count;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
