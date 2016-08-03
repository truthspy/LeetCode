// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int total = 0;
        while(total < n) {
            int cur = read4(buf + total);
            // buf += cur;
            total += cur;
            if(cur < 4)
                break;
        }
        return min(total, n);
    }
};
