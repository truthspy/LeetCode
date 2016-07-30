//直接记录截止时间，就不用每次再做减法了
class Logger {
private:
    unordered_map<string, int> mp;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(mp.find(message) == mp.end()) {
            mp[message] = timestamp + 10;
            return true;
        }
        if(timestamp >= mp[message]) {
            mp[message] = timestamp + 10;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
 
//class Logger {
// private:
//     unordered_map<string, int> mp;
// public:
//     /** Initialize your data structure here. */
//     Logger() {
        
//     }
    
//     /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
//         If this method returns false, the message will not be printed.
//         The timestamp is in seconds granularity. */
//     bool shouldPrintMessage(int timestamp, string message) {
//         if(mp.find(message) == mp.end()) {
//             mp[message] = timestamp;
//             return true;
//         }
//         int last = mp[message];
//         if(timestamp - last >= 10) {
//             mp[message] = timestamp;
//             return true;
//         }
//         return false;
//     }
// };

// /**
//  * Your Logger object will be instantiated and called as such:
//  * Logger obj = new Logger();
//  * bool param_1 = obj.shouldPrintMessage(timestamp,message);
//  */
